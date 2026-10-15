/*
** EPITECH PROJECT, 2024
** Z.cpp
** File description:
** ex00
*/

#include "ComponentFactory.hpp"

std::unique_ptr<nts::IComponent> nts::ComponentFactory::createComponent(const std::string &type, const std::string &name)
{
    if (_map.find(type) == _map.end()) {
        throw nts::Error("Unknow component");
    }
    return _map[type](name);
}
