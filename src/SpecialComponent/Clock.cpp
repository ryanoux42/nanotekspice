/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-tekspice-ryan.hercule
** File description:
** Clock
*/

#include "Clock.hpp"

nts::Clock::Clock(const std::string &name) : SpecialComponent(name), canSimulate(true)
{
  type = nts::INPUT;
}

nts::Tristate nts::Clock::compute(std::size_t pin)
{
  if (pin == 0 || pin > nb_max) {
    throw nts::Error("Index out of bonds");
  }
  return val;
}

void nts::Clock::simulate(std::size_t tick)
{
  if (canSimulate) {
    val = (val == FALSE) ? TRUE : (val == TRUE) ? FALSE : UNDEFINED;
  }
  canSimulate = true;
}

void nts::Clock::setValue(nts::Tristate new_val)
{
    canSimulate = false;
    val = new_val;
}
