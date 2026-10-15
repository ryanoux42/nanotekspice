/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-tekspice-ryan.hercule
** File description:
** Comp4069
*/

#include "Comp4069.hpp"
#include "DoOperation.hpp"

nts::Comp4069::Comp4069(const std::string &name) : GatesComponent(name)
{
}

nts::Tristate nts::Comp4069::ComputeGateNot(std::size_t pin1)
{
    if (link_comps.find(pin1) == link_comps.end()) {
        throw nts::Error("Missing an input");
    }
    return nts::operation::DoNot(link_comps[pin1].first->compute(link_comps[pin1].second));
}

nts::Tristate nts::Comp4069::compute(std::size_t pin)
{
  if (pin == 0 || pin > nb_max) {
    throw nts::Error("Index out of bonds");
  }

  if (pin == 2) {
    return ComputeGateNot(1);
  } 
  if (pin == 4) {
    return ComputeGateNot(3);
  }
  if (pin == 6) {
    return ComputeGateNot(5);
  }
  if (pin == 8) {
    return ComputeGateNot(9);
  }
  if (pin == 10) {
    return ComputeGateNot(11);
  }
  if (pin == 12) {
    return ComputeGateNot(13);
  }
  return nts::UNDEFINED;
}
