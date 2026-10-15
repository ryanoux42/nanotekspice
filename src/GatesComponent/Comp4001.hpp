/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-tekspice-ryan.hercule
** File description:
** Comp4001
*/

#ifndef COMP4001_HPP_
#define COMP4001_HPP_

#include "GatesComponent.hpp"

namespace nts {
    class Comp4001 : public GatesComponent {
        public:
            Comp4001(const std::string &name);
            ~Comp4001() = default;
            nts::Tristate ComputeGateNor(std::size_t pin1, std::size_t pin2);
            nts::Tristate compute(std::size_t pin);
    };
}

#endif /* !COMP4001_HPP_ */
