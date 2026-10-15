/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-tekspice-ryan.hercule
** File description:
** Comp4512
*/

#ifndef COMP4512_HPP_
#define COMP4512_HPP_

#include "AComponent.hpp"

namespace nts {
    class Comp4512 : public AComponent {
        public:
            Comp4512(const std::string &name);
            ~Comp4512() = default;
            nts::Tristate ComputeSelector(std::size_t pin);
            nts::Tristate ComputeAddressInput();
            nts::Tristate compute(std::size_t pin);
        private:
            int a;
            int b;
            int c;
    };
}

#endif /* !COMP4512_HPP_ */
