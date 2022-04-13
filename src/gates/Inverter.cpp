/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-tekspice-laetitia.bousch
** File description:
** not
*/

#include "Inverter.hpp"

#include <iostream>

namespace nts {
    Tristate inverter_gate(const Tristate &a)
    {
        if (a == Tristate::FALSE)
            return Tristate::TRUE;
        if (a == Tristate::TRUE)
            return Tristate::FALSE;
        return Tristate::UNDEFINED;
    }

    void Inverter::simulate(std::size_t tick)
    {
        p_tick = tick;
    }

    nts::Tristate Inverter::compute(std::size_t pin)
    {
        nts::Tristate a;

        if (p_links.size() != 2) {
            throw std::runtime_error("numbers pins insufficient");
        }
        auto it_a = p_links.find(1);
        if (it_a == p_links.end()) {
            throw std::runtime_error("no links " + 1);
        }
        a = it_a->second.component.compute(it_a->second.pin);
        return inverter_gate(a);
    }

    void Inverter::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
    {
        if (pin == 0 || pin > 2) {
            throw std::runtime_error("Link is not possible");
            return;
        }
        p_links.emplace(pin, Link(other, otherPin));
    }

    void Inverter::dump(void) const
    {
        std::cout << "state Inverter" << std::endl;
    }
}