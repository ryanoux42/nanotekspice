/*
** EPITECH PROJECT, 2024
** Z.cpp
** File description:
** ex00
*/

#include "Parser.hpp"
#include <fstream>

nts::Parser::Parser (const std::string &file)
{
    if (check_filename(file) == false) {
        throw nts::Error("Wrong file's name");
    }
    open_file(file);
    factory = new ComponentFactory;
    parse();
}

nts::Parser::~Parser()
{
    delete factory;
    comps.clear();
}

bool nts::Parser::check_filename (const std::string &file)
{
    int len = file.length();

    if (file[len - 4] == '.' && file[len - 3] == 'n' && file[len - 2] == 't' && file[len - 1] == 's') {
        return true;
    }
    return false;
}

void nts::Parser::open_file(const std::string &file)
{
    std::string line;
    std::ifstream ifs (file, std::ifstream::in);

    if (!ifs) {
      throw nts::Error("Can't open file");
    }
    while (std::getline(ifs, line)) {
        if (line[0] != '#' && !line.empty()) {
            data.push_back(line);
        }
    }
    ifs.close();
}

void nts::Parser::check_syntax_line(std::stringstream &_line)
{
    std::string word;

    if (_line.good()) {
        _line >> word;
        if (word[0] != '#') {
            throw nts::Error("Wrong file's format");
        }
    }
}

void nts::Parser::find_parts(std::stringstream &_line, int &i, int &j, int x)
{
    std::string word;

    while (_line.good()) {
        _line >> word;
        if (word[0] == '#') {
            break;
        }
        if (word == ".chipsets:") {
            i = x;
            check_syntax_line(_line);
        }
        if (word == ".links:") {
            j = x;
            check_syntax_line(_line);
        }
    }
}

void nts::Parser::parse()
{
    int len = data.size();
    std::stringstream _line;
    int i = -1;
    int j = -1;

    for (int x = 0; x < len; x += 1) {
        _line.clear();
        _line.str(data[x]);
        find_parts(_line, i, j, x);
    }
    if (i == -1 || j == -1) {
        throw nts::Error("Missing part of file");
    }
    parse_chipsets(i + 1, j);
    parse_links(j + 1, len);
}

void nts::Parser::check_component(std::stringstream &_line, std::string type)
{
    std::string name;

    if (_line.good()) {
        _line >> name;
        if (name[0] != '#') {
            check_syntax_line(_line);
        } else {
            throw nts::Error("Wrong file's format");
        }
        comps.push_back(factory->createComponent(type, name));
    }
}

void nts::Parser::parse_chipsets(int start, int end)
{
    std::stringstream _line;
    std::string type;

    for (int x = start; x < end; x += 1) {
        _line.clear();
        _line.str(data[x]);
        while (_line.good()) {
            _line >> type;
            if (type[0] == '#') {
                break;
            }
            check_component(_line, type);
        }
    }
}

void nts::Parser::make_link(std::vector<std::string> fst_arr, std::vector<std::string> snd_arr)
{
    std::size_t len = comps.size();
    int x = -1;
    int y = -1;
    std::size_t fst_pin = 0;
    std::size_t snd_pin = 0;

    for(std::size_t i = 0; i < len; i += 1) {
        if (comps[i]->getName() == fst_arr[0]) {
            x = i;
        }
        if (comps[i]->getName() == snd_arr[0]) {
            y = i;
        }
    }
    if (x == -1 || y == -1) {
        throw nts::Error("Component with this name doesn't exist");
    }
    try {
        fst_pin = std::stoi(fst_arr[1]);
        snd_pin = std::stoi(snd_arr[1]);
    } catch (const std::exception& e) {
        throw nts::Error("Doesn't know pin to link");
    }
    comps[x]->setLink(fst_pin, *comps[y], snd_pin);
    comps[y]->setLink(snd_pin, *comps[x], fst_pin);
}

void nts::Parser::check_link(std::stringstream &_line, std::string fst)
{
    std::string snd;
    std::vector<std::string> fst_arr;
    std::vector<std::string> snd_arr;

    if (_line.good()) {
        _line >> snd;
        if (snd[0] != '#') {
            check_syntax_line(_line);
        } else {
            throw nts::Error("Wrong file's format");
        }
        fst_arr = string_to_vector(fst, ':');
        snd_arr = string_to_vector(snd, ':');
        if (fst_arr.size() != 2 || snd_arr.size() != 2) {
            throw nts::Error("Wrong format link");
        }
        if (fst_arr[0] == snd_arr[0] && fst_arr[1] == snd_arr[1]) {
            throw nts::Error("Can't link pin to himself");
        }
        make_link(fst_arr, snd_arr);
    }
}

void nts::Parser::parse_links(int start, int end)
{
    std::stringstream _line;
    std::string fst;

    for (int x = start; x < end; x += 1) {
        _line.clear();
        _line.str(data[x]);
        while (_line.good()) {
            _line >> fst;
            if (fst[0] == '#') {
                break;
            }
            check_link(_line, fst);
        }
    }
}

std::vector<std::unique_ptr<nts::IComponent>> nts::Parser::GetComps()
{
    return std::move(comps);
}

void nts::Parser::checkSameName()
{
    std::size_t len = comps.size();
    std::string name;
 
    for(std::size_t i = 0; i < len; i += 1) {
        name = comps[i]->getName();
        for(std::size_t j = 0; j < len; j += 1) {
            if (j != i && comps[j]->getName() == name) {
                throw nts::Error("Components can't have the same name");
            }
        }
        name = "";
    }
}
