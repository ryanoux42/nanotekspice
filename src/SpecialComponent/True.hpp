/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-tekspice-ryan.hercule
** File description:
** True
*/

#ifndef TRUE_HPP_
    #define TRUE_HPP_

    #include "SpecialComponent.hpp"

namespace nts {
    class True : public SpecialComponent {
        public:
            True(const std::string &name);
            ~True() = default;
            nts::Tristate compute(std::size_t pin);
    };
}
#endif /* !TRUE_HPP_ */
