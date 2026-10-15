/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-tekspice-ryan.hercule
** File description:
** Input
*/

#include "SpecialComponent.hpp"

#ifndef INPUT_HPP_
#define INPUT_HPP_

namespace nts {
    class Input : public SpecialComponent {
        public:
            Input(const std::string &name);
            ~Input() = default;
            nts::Tristate compute(std::size_t pin);
    };
}

#endif /* !INPUT_HPP_ */
