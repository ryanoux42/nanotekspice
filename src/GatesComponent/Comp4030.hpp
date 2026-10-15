/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-tekspice-ryan.hercule
** File description:
** Comp4030
*/

#ifndef COMP4030_HPP_
#define COMP4030_HPP_

#include "GatesComponent.hpp"

namespace nts {
    class Comp4030 : public GatesComponent {
        public:
            Comp4030(const std::string &name);
            ~Comp4030() = default;
            nts::Tristate ComputeGateXor(std::size_t pin1, std::size_t pin2);
            nts::Tristate compute(std::size_t pin);
    };
}

#endif /* !COMP4030_HPP_ */
