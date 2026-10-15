/*
** EPITECH PROJECT, 2024
** $
** File description:
** Or
*/

#ifndef OR_HPP_
#define OR_HPP_

#include "ElementaryComponent.hpp"

namespace nts {
    class Or : public ElementaryComponent {
        public:
            Or(const std::string &name);
            ~Or() = default;
            nts::Tristate compute(std::size_t pin);
    };
}

#endif /* !OR_HPP_ */
