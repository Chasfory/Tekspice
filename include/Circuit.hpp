/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-tekspice-laetitia.bousch
** File description:
** circuit
*/

#ifndef CIRCUIT_HPP_
#define CIRCUIT_HPP_

#include "IComponent.hpp"

#include <map>
#include <string>
#include <memory>

namespace nts {
    class Circuit{
        public:
            Circuit();
            ~Circuit() = default;

            void addInputOrOutput(const std::string &name_compo, const std::string &name, const std::string &component);
            void addComponent(const std::string &name, const std::string &component);
            void linksComponent(const std::string &name, const std::string &Othername, size_t pin, size_t Otherpin);
            void displayCircuit(int tick);
            void simulateCircuit(size_t tick);
            void setState(const std::string &name, Tristate state);

        private:
            size_t tick;
            std::map<std::string, std::shared_ptr<IComponent>> p_links;
            std::map<std::string, std::shared_ptr<IComponent>> p_output;
            std::map<std::string, std::shared_ptr<IComponent>> p_input;
    };
}

#endif /* !CIRCUIT_HPP_ */