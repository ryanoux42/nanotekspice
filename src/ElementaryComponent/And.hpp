/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-tekspice-ryan.hercule
** File description:
** And
*/

#ifndef AND_HPP_
#define AND_HPP_

#include "ElementaryComponent.hpp"

namespace nts {
    class And : public ElementaryComponent {
        public:
            And(const std::string &name);
            ~And() = default;
            nts::Tristate compute(std::size_t pin);
    };
}

#endif /* !AND_HPP_ */
