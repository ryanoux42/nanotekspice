/*
** EPITECH PROJECT, 2024
** name
** File description:
** includes
*/

#ifndef COMPONENTFACTORY_HPP_

    #define COMPONENTFACTORY_HPP_
    #include <string>
    #include <map>
    #include <functional>
    #include <memory>
    #include "IComponent.hpp"
    #include "Input.hpp"
    #include "Output.hpp"
    #include "False.hpp"
    #include "True.hpp"
    #include "Clock.hpp"
    #include "And.hpp"
    #include "Or.hpp"
    #include "Xor.hpp"
    #include "Not.hpp"
    #include "Comp4030.hpp"
    #include "Comp4001.hpp"
    #include "Comp4011.hpp"
    #include "Comp4069.hpp"
    #include "Comp4071.hpp"
    #include "Comp4081.hpp"
    #include "Comp4008.hpp"
    #include "Comp4512.hpp"
    #include "Comp4013.hpp"
    #include "Comp4040.hpp"

namespace nts {
  class ComponentFactory {
    public:
      ComponentFactory() :
          _map {
              {"input", [](const std::string &name) {return std::make_unique<nts::Input>(name);}},
              {"output", [](const std::string &name) {return std::make_unique<nts::Output>(name);}},
              {"false", [](const std::string &name) {return std::make_unique<nts::False>(name);}},
              {"true", [](const std::string &name) {return std::make_unique<nts::True>(name);}},
              {"clock", [](const std::string &name) {return std::make_unique<nts::Clock>(name);}},
              {"and", [](const std::string &name) {return std::make_unique<nts::And>(name);}},
              {"or", [](const std::string &name) {return std::make_unique<nts::Or>(name);}},
              {"xor", [](const std::string &name) {return std::make_unique<nts::Xor>(name);}},
              {"not", [](const std::string &name) {return std::make_unique<nts::Not>(name);}},
              {"4030", [](const std::string &name) {return std::make_unique<nts::Comp4030>(name);}},
              {"4001", [](const std::string &name) {return std::make_unique<nts::Comp4001>(name);}},
              {"4011", [](const std::string &name) {return std::make_unique<nts::Comp4011>(name);}},
              {"4069", [](const std::string &name) {return std::make_unique<nts::Comp4069>(name);}},
              {"4071", [](const std::string &name) {return std::make_unique<nts::Comp4071>(name);}},
              {"4081", [](const std::string &name) {return std::make_unique<nts::Comp4081>(name);}},
              {"4008", [](const std::string &name) {return std::make_unique<nts::Comp4008>(name);}},
              {"4512", [](const std::string &name) {return std::make_unique<nts::Comp4512>(name);}},
              {"4013", [](const std::string &name) {return std::make_unique<nts::Comp4013>(name);}}
              // {"4040", [](const std::string &name) {return std::make_unique<nts::Comp4040>(name); }}
          }
      {};
      ~ComponentFactory() = default;
      std::unique_ptr<nts::IComponent> createComponent(const std::string &type, const std::string &name);
    private:
      std::map<std::string, std::function<std::unique_ptr<nts::IComponent> (const std::string &)>> _map;
  };
}
#endif
