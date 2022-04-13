/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-tekspice-laetitia.bousch
** File description:
** inverter
*/

#ifndef INVERTER_HPP_
#define INVERTER_HPP_

#include "../IComponent.hpp"
#include "../Link.hpp"

#include <map>

namespace nts {
    Tristate inverter_gate(const Tristate &a);

    class Inverter : public IComponent {
        public:
            Inverter() = default;
            ~Inverter() = default;

            void simulate(std::size_t tick) override;
            nts::Tristate compute(std::size_t pin = 1) override;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
            void dump() const override;

        private:
            nts::Tristate p_state;
            std::map<size_t, Link> p_links;
            size_t p_tick;
    };
}

#endif /* !INVERTER_HPP_ */
