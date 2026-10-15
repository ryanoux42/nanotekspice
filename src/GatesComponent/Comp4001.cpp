/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-tekspice-ryan.hercule
** File description:
** Comp4001
*/

#include "Comp4001.hpp"
#include "DoOperation.hpp"

nts::Comp4001::Comp4001(const std::string &name) : GatesComponent(name)
{
}

nts::Tristate nts::Comp4001::ComputeGateNor(std::size_t pin1, std::size_t pin2)
{
    if (link_comps.find(pin1) == link_comps.end() || (link_comps.find(pin2) == link_comps.end())) {
        throw nts::Error("Missing an input");
    }
    return nts::operation::DoNor(link_comps[pin1].first->compute(link_comps[pin1].second), link_comps[pin2].first->compute(link_comps[pin2].second));
}

nts::Tristate nts::Comp4001::compute(std::size_t pin)
{
  if (pin == 0 || pin > nb_max) {
    throw nts::Error("Index out of bonds");
  }

  if (pin == 3) {
    return ComputeGateNor(1, 2);
  } 
  if (pin == 4) {
    return ComputeGateNor(5, 6);
  }
  if (pin == 10) {
    return ComputeGateNor(8, 9);
  }
  if (pin == 11) {
    return ComputeGateNor(12, 13);
  }
  return nts::UNDEFINED;
}