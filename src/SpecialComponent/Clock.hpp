/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-tekspice-ryan.hercule
** File description:
** Clock
*/

#ifndef CLOCK_HPP_
#define CLOCK_HPP_

#include "SpecialComponent.hpp"

namespace nts {
    class Clock : public SpecialComponent {
        public:
            Clock(const std::string &name);
            ~Clock() = default;
            nts::Tristate compute(std::size_t pin);
            void simulate(std::size_t tick);
            void setValue(nts::Tristate);
        private:
            bool canSimulate;
    };
}

#endif /* !CLOCK_HPP_ */
