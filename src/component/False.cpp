/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-tekspice-laetitia.bousch
** File description:
** False
*/

#include "False.hpp"
#include "Factory.hpp"

#include <exception>
#include <iostream>

namespace nts {

    void False::simulate(std::size_t tick)
    {
        p_tick = tick;
    }

    nts::Tristate False::compute(std::size_t pin)
    {
        return Tristate::FALSE;
    }

    void False::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
    {
        p_links.emplace(pin, Link(other, otherPin));
    }

    void False::dump(void) const
    {
        std::cout << "state False" << std::endl;
    }
}