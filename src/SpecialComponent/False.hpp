/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-tekspice-ryan.hercule
** File description:
** False
*/

#ifndef FALSE_HPP_
#define FALSE_HPP_

#include "SpecialComponent.hpp"

namespace nts {
    class False : public SpecialComponent {
        public:
            False(const std::string &name);
            ~False() = default;
            nts::Tristate compute(std::size_t pin);
    };
}

#endif /* !FALSE_HPP_ */
