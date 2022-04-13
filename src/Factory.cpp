/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-tekspice-laetitia.bousch
** File description:
** Factory
*/

#include "Factory.hpp"

#include "Or.hpp"
#include "And.hpp"
#include "Nand.hpp"
#include "Xor.hpp"
#include "Nor.hpp"
#include "Inverter.hpp"

#include "C4001.hpp"
#include "C4011.hpp"
#include "C4030.hpp"
#include "C4069.hpp"
#include "C4071.hpp"
#include "C4081.hpp"

#include "Clock.hpp"
#include "Input.hpp"
#include "Output.hpp"
#include "False.hpp"
#include "True.hpp"

#include <iostream>
#include <string>
#include <memory>

namespace nts {
    std::shared_ptr<IComponent> Factory::create(const std::string &name)
    {
        if (name == "or") {
            return std::make_shared<Or>();
        }
        if (name == "and") {
            return std::make_shared<And>();
        }
        if (name == "nand") {
            return std::make_shared<Nand>();
        }
        if (name == "xor") {
            return std::make_shared<Xor>();
        }
        if (name == "nor") {
            return std::make_shared<Nor>();
        }
        if (name == "4001") {
            return std::make_shared<C4001>();
        }
        if (name == "4011") {
            return std::make_shared<C4011>();
        }
        if (name == "4030") {
            return std::make_shared<C4030>();
        }
        if (name == "4069") {
            return std::make_shared<C4069>();
        }
        if (name == "4071") {
            return std::make_shared<C4071>();
        }
        if (name == "4081") {
            return std::make_shared<C4081>();
        }
        if (name == "clock") {
            return std::make_shared<Clock>();
        }
        if (name == "input") {
            return std::make_shared<Input>();
        }
        if (name == "output") {
            return std::make_shared<Output>();
        }
        if (name == "false") {
            return std::make_shared<False>();
        }
        if (name == "true") {
            return std::make_shared<True>();
        }
        if (name == "inverter") {
            return std::make_shared<Inverter>();
        }
        throw std::runtime_error("unhandled component \"" + name + "\"");
    }
}