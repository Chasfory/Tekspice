/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-tekspice-laetitia.bousch
** File description:
** or
*/

#include "Or.hpp"

#include <iostream>

namespace nts {
    Tristate or_gate(const Tristate &a, const Tristate &b)
    {
        if (a == Tristate::TRUE || b == Tristate::TRUE) {
            return Tristate::TRUE;
        }
        if (a == Tristate::FALSE && b == Tristate::FALSE) {
            return Tristate::FALSE;
        }
        return Tristate::UNDEFINED;
    }

    void Or::simulate(std::size_t tick)
    {
        p_tick = tick;
    }

    nts::Tristate Or::compute(std::size_t pin)
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
        return or_gate(a, b);
    }

    void Or::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
    {
        if (pin == 0 || pin > 3) {
            throw std::runtime_error("Link is not possible");
            return;
        }
        p_links.emplace(pin, Link(other, otherPin));
    }

    void Or::dump(void) const
    {
        std::cout << "state Or" << std::endl;
    }
}