/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-tekspice-ryan.hercule
** File description:
** Comp4512
*/

#include "Comp4512.hpp"

nts::Comp4512::Comp4512(const std::string &name) : AComponent(name, 15)
{
}

nts::Tristate nts::Comp4512::ComputeSelector(std::size_t pin)
{
    if (link_comps.find(pin) == link_comps.end()) {
        throw nts::Error("Missing an input");
    }
    return link_comps[pin].first->compute(link_comps[pin].second);
}

nts::Tristate nts::Comp4512::ComputeAddressInput()
{
    int res = 0;

    a = ComputeSelector(11);
    b = ComputeSelector(12);
    c = ComputeSelector(13);
    if (a < 0 || b < 0 || c < 0) {
        return nts::UNDEFINED;
    }
    res = a + (b * 2) + (c * 4);
    res += 1;
    if (res == 8) {
        res = 9;
    }
    return ComputeSelector(res);
}

nts::Tristate nts::Comp4512::compute(std::size_t pin)
{
    nts::Tristate enable;
    nts::Tristate inhibit;

    if (pin == 0 || pin > nb_max) {
        throw nts::Error("Index out of bonds");
    }
    if (pin == 14) {
        enable = ComputeSelector(15);
        inhibit = ComputeSelector(10);
        if (enable == TRUE) {
            return nts::UNDEFINED;
        }
        if (inhibit == TRUE && enable != UNDEFINED) {
            return nts::FALSE;
        }
        if (inhibit != UNDEFINED && enable != UNDEFINED) {
            return ComputeAddressInput();
        }
    }
    return nts::UNDEFINED;
}