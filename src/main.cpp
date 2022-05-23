/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-tekspice-laetitia.bousch
** File description:
** main
*/

#include "Circuit.hpp"
#include "ParserFile.hpp"

#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wait.h>
#include <regex>

void directoryCommand(nts::Circuit &circuit)
{
   std::string lineptr;
   nts::Tristate tmp;
   int state;
   int tick = 0;
   std::cout << "> ";
   while (std::getline(std::cin, lineptr)) {
        if (lineptr.length () != 0) {
            if (lineptr == "exit") {
                return;
            }
            if (lineptr == "display") {
                circuit.displayCircuit(tick);
            }
            if (lineptr == "simulate") {
                tick += 1;
                circuit.simulateCircuit(tick);
            } else {
                std::regex circuit_regex("^(.*)=([0|1|U])$");
                std::smatch sm;
                std::regex_match(lineptr, sm, circuit_regex);
                std::stringstream sstream(sm[2]);
                if (sm[2] == "U") {
                    tmp = nts::Tristate::UNDEFINED;
                } else {
                    sstream >> state;
                    tmp = static_cast<nts::Tristate> (state);
                }
                circuit.setState(sm[1], tmp);
            }
            std::cout << "> ";
        } else {
            return;
        }
    }
}

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cout << "Usage: ./nanotekspice <filepath>" << std::endl;
        return 84;
    }
    try {
        nts::ParserFile File(av[1]);
        nts::Circuit &circuit = File.getCircuit();
        directoryCommand(circuit);
    }
    catch (std::exception const &error) {
        std::cerr << error.what() << std::endl;
        return 84;
    }
    return 0;
}