/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-tekspice-ryan.hercule
** File description:
** And
*/

#include "And.hpp"
#include "DoOperation.hpp"

nts::And::And(const std::string &name) : ElementaryComponent(name)
{
}

nts::Tristate nts::And::compute(std::size_t pin)
{
  if (pin == 0 || pin > nb_max) {
    throw nts::Error("Index out of bonds");
  }
  if (pin == 3) {
    if (link_comps.find(1) == link_comps.end() || (link_comps.find(2) == link_comps.end())) {
        throw nts::Error("Missing an input");
    }
    return nts::operation::DoAnd(link_comps[1].first->compute(link_comps[1].second), link_comps[2].first->compute(link_comps[2].second));
  }
  return nts::UNDEFINED;
}