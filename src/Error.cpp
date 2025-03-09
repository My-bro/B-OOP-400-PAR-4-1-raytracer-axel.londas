/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-raytracer-tom.facon
** File description:
** Error
*/

#include "Error.hpp"
#include <iostream>
#include <cstring>

CommandHandling::CommandHandling(int ac, char * const av[])
{
    if (ac != 2) {
        try {
            throw WrongArgumentNumber();
        } catch(const std::exception& e) {
            std::cerr << e.what();
            throw ParserError();
        }
    }
    if (ac == 2 && strcmp(av[1],"--h") == 0) {
        try {
            throw Helper();
        } catch(const std::exception& e) {
            std::cerr << e.what();
            throw ParserError();
        }
    }
}

