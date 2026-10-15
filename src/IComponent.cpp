/*
** EPITECH PROJECT, 2024
** Z.cpp
** File description:
** ex00
*/

#include "IComponent.hpp"

const char* nts::Error::what() const noexcept
{
    return msg;
}

std::ostream & operator<<(std::ostream &out, nts::Tristate v)
{
    if (v == nts::FALSE) {
        out << "0";
    }
    else if (v == nts::TRUE) {
        out << "1";
    } else {
        out << "U";
    }
    return out;
}
