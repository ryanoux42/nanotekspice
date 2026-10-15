/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-tekspice-ryan.hercule
** File description:
** Comp2716
*/

#ifndef COMP2716_HPP_
#define COMP2716_HPP_

#include "AComponent.hpp"

namespace nts {
    class Comp2716 : public AComponent {
        public:
            Comp2716(const std::string &name);
            ~Comp2716() = default;
            nts::Tristate compute(std::size_t pin);
    };
}

#endif /* !COMP2716_HPP_ */
