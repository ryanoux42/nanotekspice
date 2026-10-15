/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-tekspice-ryan.hercule
** File description:
** Output
*/

#include "Output.hpp"

nts::Output::Output(const std::string &name) : SpecialComponent(name)
{
  type = nts::OUTPUT;
}

nts::Tristate nts::Output::compute(std::size_t pin)
{
  if (pin == 0 || pin > nb_max) {
    throw nts::Error("Index out of bonds");
  }
  if (link_comps.find(pin) != link_comps.end()) {
      return link_comps[pin].first->compute(link_comps[pin].second);
  }
  return val;
}