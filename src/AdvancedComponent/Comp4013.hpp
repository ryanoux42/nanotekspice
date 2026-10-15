/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-tekspice-ryan.hercule
** File description:
** Comp4013
*/

#ifndef COMP4013_HPP_
#define COMP4013_HPP_

#include "AComponent.hpp"

namespace nts {
    class Comp4013 : public AComponent {
        public:
            Comp4013(const std::string &name);
            ~Comp4013() = default;
            void initFlipFlop(std::size_t pin1, std::size_t pin2, std::size_t pin3, std::size_t clock);
            void computeFlipFlop();
            nts::Tristate compute(std::size_t pin);
        private:
            nts::Tristate firstRes;
            nts::Tristate scndRes;
            nts::Tristate enable;
            nts::Tristate clock;
            nts::Tristate set;
            nts::Tristate reset;
    };
}

#endif /* !COMP4013_HPP_ */
