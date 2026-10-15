/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-tekspice-ryan.hercule
** File description:
** Circuit
*/

#ifndef CIRCUIT_HPP_
#define CIRCUIT_HPP_

#include "Parser.hpp"
#include <algorithm>
#include <csignal>
#include <memory>
#include <bits/stdc++.h> 

namespace nts {
    class Circuit {
        public:
            Circuit(std::vector<std::unique_ptr<nts::IComponent>> components);
            ~Circuit();
            void run();
            static void sigintHandler(int signal);
            void inputChangeValue(int x, std::string val);
            void makeChange();
            void simulate();
            bool checkCommandInput(std::string line);
            static bool my_sort(std::unique_ptr<nts::IComponent>& value1, std::unique_ptr<nts::IComponent>& value2);
            void display();
            bool checkline();
        private:
            std::size_t tick;
            std::vector<std::unique_ptr<nts::IComponent>> components;
            bool needToChange;
            static bool ctrlC;
            std::string line;
            std::vector<std::string> inputValue;
    };
}

#endif /* !CIRCUIT_HPP_ */
