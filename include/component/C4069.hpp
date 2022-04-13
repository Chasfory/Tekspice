/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-tekspice-laetitia.bousch
** File description:
** C4069
*/

#ifndef C4069_HPP_
#define C4069_HPP_

#include "../IComponent.hpp"
#include "../Link.hpp"

#include <map>
#include <memory>
#include <vector>
#include <iostream>
#include <utility>

namespace nts {
    class C4069 : public IComponent{
        public:
            C4069();
            ~C4069() = default;

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

#endif /* !C4069_HPP_ */
