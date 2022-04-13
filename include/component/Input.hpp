/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-tekspice-laetitia.bousch
** File description:
** Input
*/

#ifndef INPUT_HPP_
#define INPUT_HPP_

#include "../IComponent.hpp"
#include "../Link.hpp"

#include <map>
#include <memory>
#include <vector>
#include <iostream>
#include <utility>

namespace nts {
    class Input : public IComponent{
        public:
            Input();
            ~Input() = default;

            void simulate(std::size_t tick) override;
            nts::Tristate compute(std::size_t pin = 1) override;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
            virtual void setValue(nts::Tristate value);
            void doneValue();
            void dump() const override;

        protected:
            nts::Tristate p_tmp_state;
            nts::Tristate p_state;

        private:
            std::size_t p_tick;
            std::map<size_t, Link> p_links;
            std::vector<std::shared_ptr<IComponent>> p_components;
    };
}

#endif /* !INPUT_HPP_ */
