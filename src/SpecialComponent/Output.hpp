/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-tekspice-ryan.hercule
** File description:
** Output
*/

#ifndef OUTPUT_HPP_
#define OUTPUT_HPP_

#include "SpecialComponent.hpp"

namespace nts {
    class Output : public SpecialComponent {
        public:
            Output(const std::string &name);
            ~Output() = default;
            nts::Tristate compute(std::size_t pin);
    };
}

#endif /* !OUTPUT_HPP_ */
