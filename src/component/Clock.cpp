/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-tekspice-laetitia.bousch
** File description:
** Clock
*/

#include "Clock.hpp"
#include "Factory.hpp"

#include <exception>
#include <iostream>

namespace nts {

    void Clock::simulate(std::size_t tick)
    {
        p_tick = tick;
        if (p_state == Tristate::TRUE && tmp == 0) {
            p_state = Tristate::FALSE;
            p_tmp_state = Tristate::FALSE;
        } else if (p_state == Tristate::FALSE && tmp == 0) {
            p_state = Tristate::TRUE;
            p_tmp_state = Tristate::TRUE;
        }
        tmp = 0;
    }

    nts::Tristate Clock::compute(std::size_t pin)
    {
        return p_state;
    }

    void Clock::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
    {
        p_links.emplace(pin, Link(other, otherPin));
    }

    void Clock::setValue(nts::Tristate value)
    {
        p_tmp_state = value;
        tmp = 1;
    }

    void Clock::dump(void) const
    {
        std::cout << "state Clock" << std::endl;
    }

    void Clock::doneValue(void)
    {
        p_state = p_tmp_state;
    }
}