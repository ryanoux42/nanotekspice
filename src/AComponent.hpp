/*
** EPITECH PROJECT, 2024
** name
** File description:
** includes
*/

#ifndef ACOMPENENT_HPP_

    #define ACOMPENENT_HPP_
    #include <vector>
    #include "IComponent.hpp"
    #include <memory>
    #include <map>

namespace nts {
  class AComponent : public IComponent {
    protected:
      std::string name;
      std::size_t nb_max;
      std::map<std::size_t, std::pair<IComponent*, std::size_t>> link_comps;
      nts::Tristate val;  // mettre en public
      nts::Type type;
      AComponent(const std::string &name, std::size_t nb);
    public:
      ~AComponent() = default;
      void simulate(std::size_t tick) {};
      virtual nts::Tristate compute(std::size_t pin) = 0;
      void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
      std::string getName() const;
      std::size_t getMaxnbPin() const;
      void setValue(nts::Tristate);
      nts::Tristate getValue() const;
      nts::Type getType() const;
  };
}

#endif
