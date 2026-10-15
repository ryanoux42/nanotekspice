/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-tekspice-ryan.hercule
** File description:
** Comp4081
*/

#include "Comp4081.hpp"
#include "DoOperation.hpp"

nts::Comp4081::Comp4081(const std::string &name) : GatesComponent(name)
{
}

nts::Tristate nts::Comp4081::ComputeGateAnd(std::size_t pin1, std::size_t pin2)
{
    if (link_comps.find(pin1) == link_comps.end() || (link_comps.find(pin2) == link_comps.end())) {
        throw nts::Error("Missing an input");
    }
    return nts::operation::DoAnd(link_comps[pin1].first->compute(link_comps[pin1].second), link_comps[pin2].first->compute(link_comps[pin2].second));
}

nts::Tristate nts::Comp4081::compute(std::size_t pin)
{
  if (pin == 0 || pin > nb_max) {
    throw nts::Error("Index out of bonds");
  }
  if (pin == 3) {
    return ComputeGateAnd(1, 2);
  } 
  if (pin == 4) {
    return ComputeGateAnd(5, 6);
  }
  if (pin == 10) {
    return ComputeGateAnd(8, 9);
  }
  if (pin == 11) {
    return ComputeGateAnd(12, 13);
  }
  return nts::UNDEFINED;
}
