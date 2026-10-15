/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-tekspice-ryan.hercule
** File description:
** DoAlgo
*/

#include "DoOperation.hpp"

nts::Tristate nts::operation::DoAnd(Tristate pin1, Tristate pin2)
{
  return (pin1 == FALSE || pin2 == FALSE) ? FALSE : (pin1 == UNDEFINED || pin2 == UNDEFINED) ? UNDEFINED : TRUE;
}

nts::Tristate nts::operation::DoOr(Tristate pin1, Tristate pin2)
{
  return (pin1 == TRUE || pin2 == TRUE) ? TRUE : (pin1 == UNDEFINED || pin2 == UNDEFINED) ? UNDEFINED : FALSE;
}

nts::Tristate nts::operation::DoNot(Tristate pin1)
{
  return (pin1 == FALSE) ? TRUE : (pin1 == TRUE) ? FALSE : UNDEFINED;
}

nts::Tristate nts::operation::DoXor(Tristate pin1, Tristate pin2)
{
  return (pin1 == UNDEFINED || pin2 == UNDEFINED) ? UNDEFINED : (pin1 == pin2) ? FALSE : TRUE;
}

nts::Tristate nts::operation::DoNor(Tristate pin1, Tristate pin2)
{
  return DoNot(DoOr(pin1, pin2));
}

nts::Tristate nts::operation::DoNand(Tristate pin1, Tristate pin2)
{
  return DoNot(DoAnd(pin1, pin2));
}
