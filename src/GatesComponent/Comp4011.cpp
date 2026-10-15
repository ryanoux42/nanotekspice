/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-tekspice-ryan.hercule
** File description:
** Comp4011
*/

#include "Comp4011.hpp"
#include "DoOperation.hpp"

nts::Comp4011::Comp4011(const std::string &name) : GatesComponent(name)
{
}

nts::Tristate nts::Comp4011::ComputeGateNand(std::size_t pin1, std::size_t pin2)
{
    if (link_comps.find(pin1) == link_comps.end() || (link_comps.find(pin2) == link_comps.end())) {
        throw nts::Error("Missing an input");
    }
    return nts::operation::DoNand(link_comps[pin1].first->compute(link_comps[pin1].second), link_comps[pin2].first->compute(link_comps[pin2].second));
}

nts::Tristate nts::Comp4011::compute(std::size_t pin)
{
  if (pin == 0 || pin > nb_max) {
    throw nts::Error("Index out of bonds");
  }

  if (pin == 3) {
    return ComputeGateNand(1, 2);
  } 
  if (pin == 4) {
    return ComputeGateNand(5, 6);
  }
  if (pin == 10) {
    return ComputeGateNand(8, 9);
  }
  if (pin == 11) {
    return ComputeGateNand(12, 13);
  }
  return nts::UNDEFINED;
}