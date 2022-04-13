/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-tekspice-laetitia.bousch
** File description:
** C4071
*/

#include "C4071.hpp"
#include "Factory.hpp"

#include <exception>
#include <iostream>

namespace nts {
    C4071::C4071()
    {
        for (int i = 0; i < 4; i++) {
            p_components.emplace_back(Factory::create("or"));
        }
        p_links.emplace(1, Link(*p_components[0].get(), 1));
        p_links.emplace(2, Link(*p_components[0].get(), 2));
        p_links.emplace(3, Link(*p_components[0].get(), 3));
        p_links.emplace(4, Link(*p_components[1].get(), 3));
        p_links.emplace(5, Link(*p_components[1].get(), 1));
        p_links.emplace(6, Link(*p_components[1].get(), 2));
        p_links.emplace(8, Link(*p_components[2].get(), 1));
        p_links.emplace(9, Link(*p_components[2].get(), 2));
        p_links.emplace(10, Link(*p_components[2].get(), 3));
        p_links.emplace(11, Link(*p_components[3].get(), 3));
        p_links.emplace(12, Link(*p_components[3].get(), 1));
        p_links.emplace(13, Link(*p_components[3].get(), 2));
    }

    void C4071::simulate(std::size_t tick)
    {
        p_tick = tick;
    }

    nts::Tristate C4071::compute(std::size_t pin)
    {
        auto it_a = p_links.find(pin);
        if (it_a == p_links.end()) {
            throw std::runtime_error("number pin is not valid : " + pin);
        }
        return it_a->second.component.compute(it_a->second.pin);
    }

    void C4071::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
    {
        if ((pin == 0 || pin > 14)) {
            throw std::runtime_error("number pin is not valid");
        }
        auto it = p_links.find(pin);
        if (it == p_links.end()) {
            throw std::runtime_error("number pin no existe " + pin);
        }
        it->second.component.setLink(it->second.pin, other, otherPin);
    }

    void C4071::dump(void) const
    {
        std::cout << "state C4071" << std::endl;
    }
}