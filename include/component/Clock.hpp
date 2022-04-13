/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-tekspice-laetitia.bousch
** File description:
** Clock
*/

#ifndef CLOCK_HPP_
#define CLOCK_HPP_

#include "Input.hpp"
#include "../Link.hpp"

#include <map>
#include <memory>
#include <vector>
#include <iostream>
#include <utility>

namespace nts {
    class Clock : public Input {
        public:
            Clock() = default;
            ~Clock() = default;

            void simulate(std::size_t tick) override;
            nts::Tristate compute(std::size_t pin = 1) override;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
            void setValue(nts::Tristate value) override;
            void doneValue();
            void dump() const override;

        private:
            std::size_t p_tick;
            bool tmp;
            std::map<size_t, Link> p_links;
            std::vector<std::shared_ptr<IComponent>> p_components;
    };
}

#endif /* !CLOCK_HPP_ */
