/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-tekspice-ryan.hercule
** File description:
** GatesComponent
*/

#ifndef GATESCOMPONENT_HPP_
#define GATESCOMPONENT_HPP_

#include "AComponent.hpp"

namespace nts {
    class GatesComponent : public AComponent {
        public:
            GatesComponent(const std::string &name);
            ~GatesComponent() = default;
    };
}

#endif /* !GATESCOMPONENT_HPP_ */
