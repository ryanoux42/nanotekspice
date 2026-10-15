/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-tekspice-ryan.hercule
** File description:
** False
*/

#include "False.hpp"

nts::False::False(const std::string &name) : SpecialComponent(name)
{
  val = nts::FALSE;
}

nts::Tristate nts::False::compute(std::size_t pin)
{
  if (pin == 0 || pin > nb_max) {
    throw nts::Error("Index out of bonds");
  }
  return val;
}
