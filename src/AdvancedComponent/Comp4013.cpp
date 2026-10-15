/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-tekspice-ryan.hercule
** File description:
** Comp4013
*/

#include "Comp4013.hpp"
#include "DoOperation.hpp"

nts::Comp4013::Comp4013(const std::string &name) : AComponent(name, 13), firstRes(UNDEFINED), scndRes(UNDEFINED), enable(UNDEFINED), clock(UNDEFINED), set(UNDEFINED), reset(UNDEFINED)
{
}

void nts::Comp4013::initFlipFlop(std::size_t pin_set, std::size_t pin_enable, std::size_t pin_reset, std::size_t pin_clock)
{
    if (link_comps.find(pin_set) == link_comps.end() || (link_comps.find(pin_enable) == link_comps.end()) || (link_comps.find(pin_reset) == link_comps.end()) || (link_comps.find(pin_clock) == link_comps.end())) {
        throw nts::Error("Missing an input");
    }
    set = link_comps[pin_set].first->compute(link_comps[pin_set].second);
    enable = link_comps[pin_enable].first->compute(link_comps[pin_enable].second);
    reset = link_comps[pin_reset].first->compute(link_comps[pin_reset].second);
    clock = link_comps[pin_clock].first->compute(link_comps[pin_clock].second);
}

void nts::Comp4013::computeFlipFlop()
{
    if (enable == FALSE || (set == FALSE && reset == FALSE)) {
        if (clock != UNDEFINED) {
            firstRes = nts::operation::DoNot(clock);
            scndRes = clock;
        } else {
            firstRes = UNDEFINED;
            scndRes = UNDEFINED;
        }
    } else if (enable != UNDEFINED && set != UNDEFINED && reset != UNDEFINED){
        if (set == FALSE) {
            firstRes = FALSE;
            scndRes = TRUE;
        } else if (reset == FALSE) {
            firstRes = TRUE;
            scndRes = FALSE;
        } else {
            firstRes = FALSE;
            scndRes = FALSE;
        }
    } else {
        firstRes = UNDEFINED;
        scndRes = UNDEFINED;
    }
}

nts::Tristate nts::Comp4013::compute(std::size_t pin)
{
    if (pin == 0 || pin > nb_max) {
        throw nts::Error("Index out of bonds");
    }
    if (pin == 1 || pin == 2) {
        initFlipFlop(6, 5, 4, 3);
        computeFlipFlop();
        if (pin == 1)
            return scndRes;
        else
            return firstRes;
    }
    if (pin == 12 || pin == 13) {
        initFlipFlop(8, 9, 10, 11);
        computeFlipFlop();
        if (pin == 13)
            return scndRes;
        else
            return firstRes;
    }
    return UNDEFINED;
}