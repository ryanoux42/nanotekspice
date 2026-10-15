/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-tekspice-ryan.hercule
** File description:
** Comp4040
*/

#include "Comp4040.hpp"
#include "DoOperation.hpp"

nts::Comp4040::Comp4040(const std::string &name) : AComponent(name, 16), fst(UNDEFINED), snd(UNDEFINED), reset(UNDEFINED)
{
    _map[9] = 0;
    _map[7] = 1;
    _map[6] = 2;
    _map[5] = 3;
    _map[3] = 4;
    _map[2] = 5;
    _map[4] = 6;
    _map[13] = 7;
    _map[12] = 8;
    _map[14] = 9;
    _map[15] = 10;
    _map[1] = 11;

}
void nts::Comp4040::computeFlipFlop(nts::Tristate set, nts::Tristate reset, nts::Tristate clock)
{
    if (set == FALSE && reset == FALSE) {
        if (clock != UNDEFINED) {
            fst = nts::operation::DoNot(clock);
            snd = clock;
        } else {
            fst = UNDEFINED;
            snd = UNDEFINED;
        }
    } else if (set != UNDEFINED && reset != UNDEFINED){
        if (set == FALSE) {
            fst = FALSE;
            snd = TRUE;
        } else if (reset == FALSE) {
            fst = TRUE;
            snd = FALSE;
        } else {
            fst = FALSE;
            snd = FALSE;
        }
    } else {
        fst = UNDEFINED;
        snd = UNDEFINED;
    }
}

nts::Tristate nts::Comp4040::compute(std::size_t pin)
{
    nts::Tristate val_clock;
    nts::Tristate val_nor;

    if (pin == 0 || pin > nb_max) {
        throw nts::Error("Index out of bonds");
    }
    if (link_comps.find(10) == link_comps.end() || (link_comps.find(11) == link_comps.end())) {
        throw nts::Error("Missing an input");
    }
    val_clock = operation::DoNot(link_comps[10].first->compute(link_comps[10].second));
    reset = link_comps[11].first->compute(link_comps[11].second);
    // std::cout << "val_clock " << val_clock << " reset " << reset << std::endl;
    val_nor = operation::DoNor(val_clock, reset);
    fst = val_nor;
    snd = operation::DoNot(val_nor);
    reset = operation::DoNot(reset);
    // std::cout << "before loop " << fst << " snd " << snd << " reset " << reset << std::endl;
    for (int i = 0; i < 12; i += 1) {
        computeFlipFlop(fst,snd,reset);
        // std::cout << "fst " << fst << " snd " << snd << " reset " << reset << std::endl;
        if (_map[pin] == i) {
            // std::cout << pin << " " << i << std::endl;
            // std::cout << "fst " << fst << " snd " << snd << " reset " << reset << std::endl;
            return fst;
        }
    }
    return nts::UNDEFINED;
}