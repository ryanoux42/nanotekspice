/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-tekspice-ryan.hercule
** File description:
** Not
*/

#include "Not.hpp"
#include "DoOperation.hpp"

nts::Not::Not(const std::string &name) : ElementaryComponent(name)
{
    nb_max = 2;
}

nts::Tristate nts::Not::compute(std::size_t pin)
{
  if (pin == 0 || pin > nb_max) {
    throw nts::Error("Index out of bonds");
  }
  if (pin == 2) {
    if (link_comps.find(1) == link_comps.end()) {
        throw nts::Error("Missing an input");
    }
    return nts::operation::DoNot(link_comps[1].first->compute(link_comps[1].second));
  }
  return nts::UNDEFINED;
}