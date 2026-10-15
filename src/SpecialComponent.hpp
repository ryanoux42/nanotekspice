/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-tekspice-ryan.hercule
** File description:
** SpecialComponent
*/

#ifndef SPECIALCOMPONENT_HPP_
#define SPECIALCOMPONENT_HPP_

#include "AComponent.hpp"

namespace nts {
    class SpecialComponent : public AComponent {
        public:
            SpecialComponent(const std::string &name);
            ~SpecialComponent() = default;
    };
}

#endif /* !SPECIALCOMPONENT_HPP_ */
