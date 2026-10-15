/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-tekspice-ryan.hercule
** File description:
** Comp4071
*/

#ifndef COMP4071_HPP_
#define COMP4071_HPP_

#include "GatesComponent.hpp"

namespace nts {
    class Comp4071 : public GatesComponent {
        public:
            Comp4071(const std::string &name);
            ~Comp4071() = default;
            nts::Tristate ComputeGateOr(std::size_t pin1, std::size_t pin2);
            nts::Tristate compute(std::size_t pin);
    };
}

#endif /* !COMP4071_HPP_ */
