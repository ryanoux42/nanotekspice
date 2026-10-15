/*
** EPITECH PROJECT, 2024
** Z.cpp
** File description:
** ex00
*/

#include "AComponent.hpp"

nts::AComponent::AComponent(const std::string &name, std::size_t nb) : name(name), nb_max(nb), link_comps(), val(nts::UNDEFINED), type(nts::OTHER)
{
}

void nts::AComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
  if (pin == 0 || pin > nb_max) {
    throw nts::Error("Index out of bonds");
  }
  if (otherPin == 0 || otherPin > other.getMaxnbPin()) {
    throw nts::Error("Index out of bonds");
  }
  if (link_comps.find(pin) != link_comps.end()) {
      throw nts::Error("Already link");
  }
  link_comps[pin] = std::make_pair(&other, otherPin);
}

std::string nts::AComponent::getName() const
{
  return name;
}

std::size_t nts::AComponent::getMaxnbPin() const
{
  return nb_max;
}

void nts::AComponent::setValue(nts::Tristate new_val)
{
    val = new_val;
}

nts::Tristate nts::AComponent::getValue() const
{
    return val;
}

nts::Type nts::AComponent::getType() const
{
    return type;
}
