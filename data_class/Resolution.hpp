/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-raytracer-tom.facon
** File description:
** Resolution
*/

#ifndef RESOLUTION_HPP_
    #define RESOLUTION_HPP_

#include <iostream>

class Resolution {
    public:
        int width;
        int height;
};

std::ostream& operator<<(std::ostream& os, const Resolution& resolution);

#endif /* !RESOLUTION_HPP_ */
