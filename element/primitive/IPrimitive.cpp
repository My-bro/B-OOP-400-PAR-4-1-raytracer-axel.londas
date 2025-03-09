/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-raytracer-tom.facon
** File description:
** IPrimitive
*/

#include "IPrimitive.hpp"

std::ostream &operator<<(std::ostream &os, const std::unique_ptr<RayTracer::IPrimitive> &primitive)
{
    primitive->printInfo(os);
    return os;
}
