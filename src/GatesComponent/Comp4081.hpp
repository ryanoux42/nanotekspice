/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-tekspice-ryan.hercule
** File description:
** Comp4081
*/

#ifndef COMP4081_HPP_
#define COMP4081_HPP_

#include "GatesComponent.hpp"

namespace nts {
    class Comp4081 : public GatesComponent {
        public:
            Comp4081(const std::string &name);
            ~Comp4081() = default;
            nts::Tristate ComputeGateAnd(std::size_t pin1, std::size_t pin2);
            nts::Tristate compute(std::size_t pin);
    };
}

#endif /* !COMP4081_HPP_ */
