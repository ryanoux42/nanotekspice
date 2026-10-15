/*
** EPITECH PROJECT, 2024
** B-PDG-300-PAR-3-1-PDGRUSH3-zacharie.rodde
** File description:
** Parser
*/

#ifndef ICOMPONENT_HPP_
    #define ICOMPONENT_HPP_
    #include <iostream>

namespace nts {
    enum Tristate {
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false
    };
    enum Type {
      OTHER,
      INPUT,
      OUTPUT,
    };
    class Error : public std::exception {
        public:
            Error(const char *message) : msg(message) {};
            const char* what() const noexcept;
        private:
            const char *msg;
    };
    class IComponent {
        public :
            virtual ~IComponent() = default ;
            virtual void simulate(std::size_t tick) = 0;
            virtual nts::Tristate compute(std::size_t pin) = 0;
            virtual void setLink(std::size_t pin , nts::IComponent &other, std::size_t otherPin) = 0;
            virtual std::string getName() const = 0;
            virtual std::size_t getMaxnbPin() const = 0;
            virtual void setValue(nts::Tristate) = 0;
            virtual nts::Tristate getValue() const = 0;
            virtual nts::Type getType() const = 0;
    };
}

std::ostream &operator<<(std::ostream &out, nts::Tristate v);

#endif
