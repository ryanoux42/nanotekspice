/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-tekspice-ryan.hercule
** File description:
** Comp4011
*/

#ifndef COMP4011_HPP_
#define COMP4011_HPP_

#include "GatesComponent.hpp"

namespace nts {
    class Comp4011 : public GatesComponent {
        public:
            Comp4011(const std::string &name);
            ~Comp4011() = default;
            nts::Tristate ComputeGateNand(std::size_t pin1, std::size_t pin2);
            nts::Tristate compute(std::size_t pin);
    };
}

#endif /* !COMP4011_HPP_ */
