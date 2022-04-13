/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-tekspice-laetitia.bousch
** File description:
** ParserFile
*/

#ifndef PARSEURFILE_HPP_
#define PARSEURFILE_HPP_

#include "Circuit.hpp"

#include <string>

namespace nts {
    class ParserFile {
        public:
            ParserFile(const std::string &filepath);
            ~ParserFile() = default;

            void addComponentChipset(const std::string &line);
            void addComponentLinks(const std::string &line);
            Circuit &getCircuit();
        private:
            Circuit p_circuit;
    };
}

#endif /* !PARSEURFILE_HPP_ */
