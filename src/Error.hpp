/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-raytracer-tom.facon
** File description:
** Error
*/

#ifndef ERROR_HPP_
    #define ERROR_HPP_

#include <stdexcept>
#include <string>
#include <cstring>

class CommandHandling {
    public:
        CommandHandling(int ac, char * const av[]);
    private:
};

class Helper : public std::exception {
    public:
        Helper(void) {
            _message = "USAGE\n\t./raytracer file\nDESCRIPTION\n    file    file with scene description\n";
        }
        const char *what() const noexcept override
        {
            return _message.c_str();
        }
    private:
        std::string _message;
};

class WrongArgumentNumber : public std::exception {
    public:
        WrongArgumentNumber(void) {
            _message = "Error: Wrong number of arguments\n";
        }
        const char *what() const noexcept override
        {
            return _message.c_str();
        }
    private:
        std::string _message;
};

class ParserError : public std::exception {
    public:
        ParserError(void) {
            _message = "Error: Parser error\n";
        }
        const char *what() const noexcept override
        {
            return _message.c_str();
        }
    private:
        std::string _message;
};

#endif /* !ERROR_HPP_ */
