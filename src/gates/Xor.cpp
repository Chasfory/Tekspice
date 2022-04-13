/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-tekspice-laetitia.bousch
** File description:
** xor
*/

#include "Xor.hpp"

#include <iostream>

namespace nts {
    Tristate xor_gate(const Tristate &a, const Tristate &b)
    {
        if ((a == Tristate::FALSE && b == Tristate::FALSE) ||
            (a == Tristate::TRUE && b == Tristate::TRUE))
            return Tristate::FALSE;
        if ((a == Tristate::FALSE && b == Tristate::TRUE) ||
            (a == Tristate::TRUE && b == Tristate::FALSE))
            return Tristate::TRUE;
        return Tristate::UNDEFINED;
    }

    void Xor::simulate(std::size_t tick)
    {
        p_tick = tick;
    }

    nts::Tristate Xor::compute(std::size_t pin)
    {
        nts::Tristate a;
        nts::Tristate b;

        if (p_links.size() != 3) {
            throw std::runtime_error("numbers pins insufficient");
        }
        auto it_a = p_links.find(1);
        if (it_a == p_links.end()) {
            throw std::runtime_error("no links " + 1);
        }
        a = it_a->second.component.compute(it_a->second.pin);
        auto it_b = p_links.find(2);
        if (it_b == p_links.end()) {
            throw std::runtime_error("no links " + 2);
        }
        b = it_b->second.component.compute(it_b->second.pin);
        return xor_gate(a, b);
    }

    void Xor::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
    {
        if (pin == 0 || pin > 3) {
            throw std::runtime_error("Link is not possible");
            return;
        }
        p_links.emplace(pin, Link(other, otherPin));
    }

    void Xor::dump(void) const
    {
        std::cout << "state Xor" << std::endl;
    }
}