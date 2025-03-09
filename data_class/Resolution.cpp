/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-raytracer-tom.facon
** File description:
** Resolution
*/

#include "Resolution.hpp"

std::ostream& operator<<(std::ostream& os, const Resolution& resolution)
{
    os << "Resolution: " << resolution.width << " x " << resolution.height;
    return os;
}
