/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-tekspice-laetitia.bousch
** File description:
** C4069
*/

#include "C4069.hpp"
#include "Factory.hpp"

#include <exception>
#include <iostream>

namespace nts {
    C4069::C4069(void)
    {
        for (int i = 0; i < 6; i++) {
            p_components.emplace_back(Factory::create("inverter"));
        }
        p_links.emplace(1, Link(*p_components[0].get(), 1));
        p_links.emplace(2, Link(*p_components[0].get(), 2));
        p_links.emplace(3, Link(*p_components[1].get(), 1));
        p_links.emplace(4, Link(*p_components[1].get(), 2));
        p_links.emplace(5, Link(*p_components[2].get(), 1));
        p_links.emplace(6, Link(*p_components[2].get(), 2));
        p_links.emplace(8, Link(*p_components[3].get(), 2));
        p_links.emplace(9, Link(*p_components[3].get(), 1));
        p_links.emplace(10, Link(*p_components[4].get(), 2));
        p_links.emplace(11, Link(*p_components[4].get(), 1));
        p_links.emplace(12, Link(*p_components[5].get(), 2));
        p_links.emplace(13, Link(*p_components[5].get(), 1));
    }

    void C4069::simulate(std::size_t tick)
    {
        p_tick = tick;
    }

    nts::Tristate C4069::compute(std::size_t pin)
    {
        auto it_a = p_links.find(pin);
        if (it_a == p_links.end()) {
            throw std::runtime_error("number pin is not valid : " + pin);
        }
        return it_a->second.component.compute(it_a->second.pin);
    }

    void C4069::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
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

    void C4069::dump(void) const
    {
        std::cout << "state C4069" << std::endl;
    }

}