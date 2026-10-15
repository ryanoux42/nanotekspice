/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-tekspice-ryan.hercule
** File description:
** Circuit
*/

#include "Circuit.hpp"

nts::Circuit::Circuit(std::vector<std::unique_ptr<nts::IComponent>> components) : tick(0), components(std::move(components)), needToChange(false)
{
}

nts::Circuit::~Circuit()
{
    components.clear();
}

bool nts::Circuit::ctrlC = false;

void nts::Circuit::run()
{
    std::cout << "> ";
    while (getline(std::cin, line)) {
        if (!checkline())
            break;
        std::cout << "> ";
    }
}

void nts::Circuit::sigintHandler(int signal) 
{
    ctrlC = true;
}

void nts::Circuit::inputChangeValue(int x, std::string val)
{
    if (x == -1) {
        std::cerr << "Component with this name doesn't exist" << std::endl;
        return;
    }
    if (components[x]->getType() != nts::INPUT) {
        std::cerr << "Not an input component" << std::endl;
        return;
    }
    if (val == "0") {
        components[x]->setValue(FALSE);
    } else if (val == "1") {
        components[x]->setValue(TRUE);
    } else if (val == "U") {
        components[x]->setValue(UNDEFINED);
    } else {
        std::cerr << "This value doesn't exist" << std::endl;
    }
}

void nts::Circuit::makeChange()
{
    std::vector<std::string> fst_arr;
    std::size_t len = components.size();
    int x = -1;

    for(std::size_t i = 0; i < inputValue.size(); i += 1) {
        fst_arr = string_to_vector(inputValue[i], '=');
        for(std::size_t i = 0; i < len; i += 1) {
            if (components[i]->getName() == fst_arr[0]) {
                x = i;
            }
        }
        inputChangeValue(x, fst_arr[1]);
        x = -1;
        fst_arr.clear();
    }
    inputValue.clear();
    needToChange = false;
}

void nts::Circuit::simulate()
{
    tick += 1;
    if (needToChange) {
        makeChange();
    }
    for (size_t i = 0; i < components.size(); ++i) {
        components[i]->simulate(tick);
    }
}

bool nts::Circuit::checkCommandInput(std::string line)
{
    std::vector<std::string> fst_arr;
    std::size_t len = components.size();
    std::string val;
    int x = -1;

    fst_arr = string_to_vector(line, '=');
    for(std::size_t i = 0; i < len; i += 1) {
        if (components[i]->getName() == fst_arr[0]) {
            x = i;
        }
    }
    if (x == -1) {
        std::cerr << "Component with this name doesn't exist" << std::endl;
        return false;
    }
    if (components[x]->getType() != nts::INPUT) {
        std::cerr << "Not an input component" << std::endl;
        return false;
    }
    val = fst_arr[1];
    if (val != "0" && val != "1" && val != "U") {
        std::cerr << "This value doesn't exist" << std::endl;
        return false;
    }
    return true;
}

bool nts::Circuit::my_sort(std::unique_ptr<nts::IComponent>& value1, std::unique_ptr<nts::IComponent>& value2)
{
    return value1->getName() < value2->getName();
}

void nts::Circuit::display()
{
    std::cout << "tick: " <<  tick << std::endl << "input(s):" << std::endl;
    sort(components.begin(), components.end(), my_sort);
    for (size_t i = 0; i < components.size(); ++i) {
        if (components[i]->getType() == INPUT)
            std::cout << "  " << components[i]->getName() << ": " << components[i]->compute(1) << std::endl;
    }
    std::cout << "output(s):" << std::endl;
    for (size_t i = 0; i < components.size(); ++i) {
        if (components[i]->getType() == OUTPUT)
            std::cout << "  " << components[i]->getName() << ": " << components[i]->compute(1) << std::endl;
    }
}

bool nts::Circuit::checkline()
{
    std::signal(SIGINT, sigintHandler);
    if (line == "exit") {
        return false;
    }
    else if (line == "display") {
        display();
    }
    else if (line.find("=") != std::string::npos) {
        if (checkCommandInput(line)) {
            needToChange = true;
            inputValue.push_back(line);
        }
    }
    else if (line == "simulate") {
        simulate();
    }
    else if (line == "loop") {
        while (!ctrlC) {
            simulate();
        }
        std::signal(SIGINT, SIG_DFL);
        std::cout << std::endl;
    }
    else {
        std::cerr << "Wrong Command, use: exit, display, input=value, simulate, loop" << std::endl;
    }
    return true;
}
