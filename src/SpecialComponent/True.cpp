/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-tekspice-ryan.hercule
** File description:
** True
*/

#include "True.hpp"

nts::True::True(const std::string &name) : SpecialComponent(name)
{
  val = nts::TRUE;
}

nts::Tristate nts::True::compute(std::size_t pin)
{
  if (pin == 0 || pin > nb_max) {
    throw nts::Error("Index out of bonds");
  }
  return val;
}
