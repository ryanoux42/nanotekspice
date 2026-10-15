/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-tekspice-ryan.hercule
** File description:
** ElementaryComponent
*/

#ifndef ELEMENTARYCOMPONENT_HPP_
#define ELEMENTARYCOMPONENT_HPP_

#include "AComponent.hpp"

namespace nts {
    class ElementaryComponent : public AComponent {
        public:
            ElementaryComponent(const std::string &name);
            ~ElementaryComponent() = default;
    };
}

#endif /* !ELEMENTARYCOMPONENT_HPP_ */
