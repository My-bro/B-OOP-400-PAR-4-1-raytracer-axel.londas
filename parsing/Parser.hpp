/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-raytracer-tom.facon
** File description:
** Parser
*/

#ifndef PARSER_HPP_
    #define PARSER_HPP_

#include <libconfig.h++>

class Parser : libconfig::Config {
    public:
        Parser(char *const av[]);
        libconfig::Setting& myLookup(const std::string &path) {
            return this->lookup(path);
        }
        ~Parser() {};
};

#endif /* !PARSER_HPP_ */
