/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-raytracer-tom.facon
** File description:
** parser
*/

#include <libconfig.h++>
#include <iostream>
#include "Parser.hpp"
#include "../src/Error.hpp"

Parser::Parser(char *const av[])
{
    try {
        this->readFile(av[1]);
    } catch(const libconfig::FileIOException &fioex) {
        std::cerr << "I/O error while reading file." << std::endl;
        throw ParserError();
    } catch(const libconfig::ParseException &pex) {
        std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine()
        << " - " << pex.getError() << std::endl;
        throw ParserError();
    }
    try {
        std::string name = this->lookup("name");
        // std::cout << "Name: " << name << std::endl;
    } catch(const libconfig::SettingNotFoundException &nfex) {
        std::cerr << "No 'name' setting in configuration file." << std::endl;
    }
}
