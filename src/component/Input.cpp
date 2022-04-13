/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-tekspice-laetitia.bousch
** File description:
** Input
*/

#include "Input.hpp"
#include "Factory.hpp"

#include <exception>
#include <iostream>

namespace nts {

    Input::Input()
    {
        p_state = Tristate::UNDEFINED;
        p_tmp_state = Tristate::UNDEFINED;
    }

    void Input::simulate(std::size_t tick)
    {
        p_tick = tick;
    }

    nts::Tristate Input::compute(std::size_t pin)
    {
        return p_state;
    }

    void Input::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
    {
        p_links.emplace(pin, Link(other, otherPin));
    }

    void Input::setValue(nts::Tristate value)
    {
        p_tmp_state = value;
    }

    void Input::dump(void) const
    {
        std::cout << "state Input" << std::endl;
    }

    void Input::doneValue(void)
    {
        p_state = p_tmp_state;
    }
}