/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-tekspice-ryan.hercule
** File description:
** Input
*/

#include "Input.hpp"

nts::Input::Input(const std::string &name) : SpecialComponent(name)
{
  type = nts::INPUT;
}

nts::Tristate nts::Input::compute(std::size_t pin)
{
  if (pin == 0 || pin > nb_max) {
    throw nts::Error("Index out of bonds");
  }
  return val;
}
