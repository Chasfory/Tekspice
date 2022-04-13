/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-tekspice-laetitia.bousch
** File description:
** circuit
*/

#include "Circuit.hpp"
#include "Factory.hpp"
#include "IComponent.hpp"
#include "Input.hpp"
#include "Clock.hpp"

#include <map>
#include <vector>
#include <exception>

namespace nts {

    Circuit::Circuit()
    {
        tick = 0;
    }

    void Circuit::addComponent(const std::string &name, const std::string &component)
    {
        std::shared_ptr<IComponent> compo = Factory::create(name);
        p_links.emplace(component, compo);
        if (name == "input" || name == "clock") {
            p_input.emplace(component, compo);
        }
        if (name == "output") {
            p_output.emplace(component, compo);
        }
    }

    void Circuit::simulateCircuit(size_t tick)
    {
        Input *cast;

        for (auto it_input = p_input.begin(); it_input != p_input.end(); it_input++) {
            cast = dynamic_cast<Input *>(it_input->second.get());
            cast->doneValue();
        }
        for (auto it = p_links.begin(); it != p_links.end(); it++) {
            it->second->simulate(tick);
        }
    }

    void Circuit::linksComponent(const std::string &name,
        const std::string &Othername, size_t pin, size_t Otherpin)
    {
        auto it_a = p_links.find(name);
        auto it_b = p_links.find(Othername);
        if (it_a == p_links.end()) {
            throw std::runtime_error("Unknow component name \"" + name + "\"");
        }
        if (it_b == p_links.end()) {
            throw std::runtime_error("Unknow component name \"" + Othername + "\"");
        }
        it_a->second->setLink(pin, *(it_b->second), Otherpin);
        it_b->second->setLink(Otherpin, *(it_a->second), pin);
    }

    void Circuit::setState(const std::string &name, Tristate state)
    {
        Input *cast;

        auto it = p_input.find(name);
        if (it == p_input.end()) {
            return;
        }
        cast = dynamic_cast<Input *>(it->second.get());
        cast->setValue(state);
    }

    void Circuit::displayCircuit(int tick)
    {
        std::cout << "tick: " << tick << std::endl;
        std::cout << "input(s):" << std::endl;
        for (auto it = p_input.begin(); it != p_input.end(); it++) {
            std::cout << "  " << it->first << ": ";
            if (it->second->compute(1) == Tristate::UNDEFINED) {
                std::cout << "U" << std::endl;
            } else {
                std::cout << it->second->compute(1) << std::endl;
            }
        }
        std::cout << "output(s):" << std::endl;
        for (auto it = p_output.begin(); it != p_output.end(); it++) {
            std::cout << "  " << it->first << ": ";
            if (it->second->compute(1) != Tristate::UNDEFINED) {
                std::cout << it->second->compute(1) << std::endl;
            } else {
                std::cout << "U" << std::endl;
            }
        }
    }
}