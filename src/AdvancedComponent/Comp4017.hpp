/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-tekspice-ryan.hercule
** File description:
** Comp4017
*/

#ifndef COMP4017_HPP_
#define COMP4017_HPP_

#include "AComponent.hpp"

namespace nts {
    class Comp4017 : public AComponent {
        public:
            Comp4017(const std::string &name);
            ~Comp4017() = default;
            nts::Tristate compute(std::size_t pin);
    };
}

#endif /* !COMP4017_HPP_ */
