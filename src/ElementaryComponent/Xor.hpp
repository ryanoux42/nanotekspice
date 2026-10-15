/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-tekspice-ryan.hercule
** File description:
** Xor
*/

#ifndef XOR_HPP_
#define XOR_HPP_

#include "ElementaryComponent.hpp"

namespace nts {
    class Xor : public ElementaryComponent {
        public:
            Xor(const std::string &name);
            ~Xor() = default;
            nts::Tristate compute(std::size_t pin);
    };
}

#endif /* !XOR_HPP_ */
