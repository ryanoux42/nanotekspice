/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-tekspice-ryan.hercule
** File description:
** Comp4008
*/

#include "Comp4008.hpp"
#include "DoOperation.hpp"

nts::Comp4008::Comp4008(const std::string &name) : AComponent(name, 16)
{
}

nts::Tristate nts::Comp4008::ComputeSum(std::size_t pin1, std::size_t pin2)
{
    nts::Tristate first_xor;
    nts::Tristate sum;
    nts::Tristate first_and;
    nts::Tristate second_and;
    nts::Tristate c_out;
    nts::Tristate pin1_value;
    nts::Tristate pin2_value;

    if (link_comps.find(pin1) == link_comps.end() || (link_comps.find(pin2) == link_comps.end())) {
        throw nts::Error("Missing an input");
    }
    pin1_value = link_comps[pin1].first->compute(link_comps[pin1].second);
    pin2_value = link_comps[pin2].first->compute(link_comps[pin2].second);
    first_xor = nts::operation::DoXor(pin1_value, pin2_value);
    sum = nts::operation::DoXor(first_xor, c);
    first_and = nts::operation::DoAnd(first_xor, c);
    second_and = nts::operation::DoAnd(pin1_value, pin2_value);
    c_out = nts::operation::DoOr(first_and,second_and);
    c = c_out;
    return sum;
}

nts::Tristate nts::Comp4008::compute(std::size_t pin)
{
    nts::Tristate sum1;
    nts::Tristate sum2;
    nts::Tristate sum3;
    nts::Tristate sum4;

    if (pin == 0 || pin > nb_max) {
        throw nts::Error("Index out of bonds");
    }
    if (link_comps.find(9) == link_comps.end()) {
        throw nts::Error("Missing an Cin");
    }
    c = link_comps[9].first->compute(link_comps[9].second);
    sum1 = ComputeSum(6, 7);
    sum2 = ComputeSum(4, 5);
    sum3 = ComputeSum(2, 3);
    sum4 = ComputeSum(1, 15);
    if (pin == 10) {
        return sum1;
    }
    if (pin == 11) {
        return sum2;
    }
    if (pin == 12) {
        return sum3;
    }
    if (pin == 13) {
        return sum4;
    }
    if (pin == 14) {
        return c;
    }
    return nts::UNDEFINED;
}