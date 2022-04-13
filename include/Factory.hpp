/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-tekspice-laetitia.bousch
** File description:
** Factory
*/

#ifndef FACTORY_HPP_
#define FACTORY_HPP_

#include "IComponent.hpp"

#include <memory>

namespace nts {
    class Factory {
        public:
            static std::shared_ptr<IComponent> create(const std::string &name);
    };
}

#endif /* !FACTORY_HPP_ */