/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-tekspice-laetitia.bousch
** File description:
** Link
*/

#ifndef LINK_HPP_
#define LINK_HPP_

#include "IComponent.hpp"

namespace nts {
    struct Link {
        Link(nts::IComponent &component, std::size_t pin): component(component), pin(pin) {}
        nts::IComponent &component;
        std::size_t pin;
    };
}

#endif /* !LINK_HPP_ */
