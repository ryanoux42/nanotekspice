/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-tekspice-ryan.hercule
** File description:
** Not
*/

#ifndef NOT_HPP_
#define NOT_HPP_

#include "ElementaryComponent.hpp"

namespace nts {
    class Not : public ElementaryComponent {
        public:
            Not(const std::string &name);
            Not() = default;
            nts::Tristate compute(std::size_t pin);
    };
}

#endif /* !NOT_HPP_ */
