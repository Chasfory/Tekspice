/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-tekspice-laetitia.bousch
** File description:
** file
*/

#include "Circuit.hpp"
#include "ParserFile.hpp"
#include "Factory.hpp"

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <utility>
#include <sstream>
#include <string>
#include <exception>
#include <cstring>
#include <regex>

namespace nts {
    void ParserFile::addComponentChipset(const std::string &line)
    {
        std::istringstream iss(line);
        std::string component;
        std::string name_other_component;
        size_t i = 0;

        std::regex circuit_regex("^ *([^ ]*) *([^ ]*) *$");
        std::smatch sm;
        std::regex_match(line, sm, circuit_regex);
        for (; i < sm.size(); ++i);
        if (i != 3) {
            throw std::runtime_error("error");
        }
        std::stringstream compo(sm[1]);
        compo >> component;
        std::stringstream other(sm[2]);
        other >> name_other_component;
        p_circuit.addComponent(component, name_other_component);
    }

    void ParserFile::addComponentLinks(const std::string &line) {
        std::istringstream iss(line);
        std::string component;
        std::string name_other_component;
        size_t pin;
        size_t other_pin;
        size_t i = 0;

        std::regex circuit_regex("^ *(.*):([0-9]*) *(.*):([0-9]*) *$");
        std::smatch sm;
        std::regex_match(line, sm, circuit_regex);
        for (; i < sm.size(); ++i);
        if (i != 5) {
            throw std::runtime_error("error");
        }
        std::stringstream compo_name(sm[1]);
        compo_name >> component;
        std::stringstream other_compo_name(sm[3]);
        other_compo_name >> name_other_component;
        std::stringstream numb_pin(sm[2]);
        numb_pin >> pin;
        std::stringstream other_numb_name(sm[4]);
        other_numb_name >> other_pin;
        p_circuit.linksComponent(component, name_other_component, pin, other_pin);
    }

    ParserFile::ParserFile(const std::string &filepath) :
        p_circuit()
    {
        std::ifstream file;
        int option = 0;

        file.open(filepath);
        if (!file.is_open()) {
            throw std::invalid_argument(filepath + ": no such file or directory");
        }
        while (!file.eof()) {
            std::string line;
            getline(file, line);
            if (line.empty()) {
                option = 0;
            }
            if (option == 1) {
                addComponentChipset(line);
            }
            if (option == 2) {
                addComponentLinks(line);
            }
            if (line[0] != '#') {
                if (line == ".chipsets:") {
                    option = 1;
                } else if (line == ".links:") {
                    option = 2;
                }
            }
        }
    }

    nts::Circuit &ParserFile::getCircuit()
    {
        return p_circuit;
    }
}