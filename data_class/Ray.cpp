/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Ray
*/

#include "Ray.hpp"

RayTracer::Ray::Ray()
{
}

RayTracer::Ray::Ray(Math::Point3D origin, Math::Vector3D direction) : _origin(origin), _direction(direction)
{
}

RayTracer::Ray::~Ray()
{
}
