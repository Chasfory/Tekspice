/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-tekspice-laetitia.bousch
** File description:
** False
*/

#ifndef FALSE_HPP_
#define FALSE_HPP_

#include "../IComponent.hpp"
#include "../Link.hpp"

#include <map>
#include <memory>
#include <vector>
#include <iostream>
#include <utility>

namespace nts {
    class False : public IComponent{
        public:
            False() = default;
            ~False() = default;

            void simulate(std::size_t tick) override;
            nts::Tristate compute(std::size_t pin = 1) override;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
            void dump() const override;
        private:
            std::size_t p_tick;
            std::map<size_t, Link> p_links;
            std::vector<std::shared_ptr<IComponent>> p_components;
    };
}

#endif /* !FALSE_HPP_ */
