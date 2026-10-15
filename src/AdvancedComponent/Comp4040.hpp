/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-tekspice-ryan.hercule
** File description:
** Comp4040
*/

#ifndef COMP4040_HPP_
#define COMP4040_HPP_

#include "AComponent.hpp"

namespace nts {
    class Comp4040 : public AComponent {
        public:
            Comp4040(const std::string &name);
            ~Comp4040() = default;
            void computeFlipFlop(nts::Tristate set, nts::Tristate reset, nts::Tristate clock);
            nts::Tristate compute(std::size_t pin);
        private:
            nts::Tristate fst;
            nts::Tristate snd;
            nts::Tristate reset;
            std::map<std::size_t, std::size_t> _map;
    };
}

#endif /* !COMP4040_HPP_ */
