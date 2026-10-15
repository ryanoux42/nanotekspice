/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-tekspice-ryan.hercule
** File description:
** DoAlgo
*/

#ifndef DOOPERATION_HPP_
#define DOOPERATION_HPP_

#include "IComponent.hpp"

namespace nts {
    namespace operation {
        Tristate DoNot(Tristate pin1);
        Tristate DoAnd(Tristate pin1, Tristate pin2);
        Tristate DoNand(Tristate pin1, Tristate pin2);
        Tristate DoOr(Tristate pin1, Tristate pin2);
        Tristate DoNor(Tristate pin1, Tristate pin2);
        Tristate DoXor(Tristate pin1, Tristate pin2);
    }
}

#endif /* !DOALGO_HPP_ */
