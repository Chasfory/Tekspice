/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-tekspice-laetitia.bousch
** File description:
** Output
*/

#include "Output.hpp"
#include "Factory.hpp"

#include <exception>
#include <iostream>

namespace nts {

    Output::Output()
    {
    }

    void Output::simulate(std::size_t tick)
    {
        p_tick = tick;
    }

    nts::Tristate Output::compute(std::size_t pin)
    {
        auto it_a = p_links.find(pin);
        if (it_a == p_links.end()) {
            throw std::runtime_error("number pin is not valid : " + pin);
        }
        return it_a->second.component.compute(it_a->second.pin);
    }

    void Output::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
    {
        p_links.emplace(pin, Link(other, otherPin));
    }

    void Output::dump(void) const
    {
        std::cout << "state Output" << std::endl;
    }
}