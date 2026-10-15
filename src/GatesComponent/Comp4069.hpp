/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-tekspice-ryan.hercule
** File description:
** Comp4069
*/

#ifndef COMP4069_HPP_
#define COMP4069_HPP_

#include "GatesComponent.hpp"

namespace nts {
    class Comp4069 : public GatesComponent {
        public:
            Comp4069(const std::string &name);
            ~Comp4069() = default;
            nts::Tristate ComputeGateNot(std::size_t pin1);
            nts::Tristate compute(std::size_t pin);
    };
}

#endif /* !COMP4069_HPP_ */
