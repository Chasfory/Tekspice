/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-tekspice-laetitia.bousch
** File description:
** True
*/

#include "True.hpp"
#include "Factory.hpp"

#include <exception>
#include <iostream>

namespace nts {

    void True::simulate(std::size_t tick)
    {
        p_tick = tick;
    }

    nts::Tristate True::compute(std::size_t pin)
    {
        return Tristate::TRUE;
    }

    void True::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
    {
        p_links.emplace(pin, Link(other, otherPin));
    }

    void True::dump(void) const
    {
        std::cout << "state True" << std::endl;
    }
}