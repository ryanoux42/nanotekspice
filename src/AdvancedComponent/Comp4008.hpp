/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-tekspice-ryan.hercule
** File description:
** Comp4008
*/

#ifndef COMP4008_HPP_
#define COMP4008_HPP_

#include "AComponent.hpp"

namespace nts {
    class Comp4008 : public AComponent {
        public:
            Comp4008(const std::string &name);
            ~Comp4008() = default;
            nts::Tristate ComputeSum(std::size_t pin1, std::size_t pin2);
            nts::Tristate compute(std::size_t pin);
        private:
            nts::Tristate c;
    };
}

#endif /* !COMP4008_HPP_ */
