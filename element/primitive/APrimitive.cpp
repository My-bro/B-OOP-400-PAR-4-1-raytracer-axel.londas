/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** APrimitive
*/

#include "APrimitive.hpp"

void RayTracer::APrimitive::translation(Math::Vector3D vector)
{
    _center._x += vector._x;
    _center._y += vector._y;
    _center._z += vector._z;
}

Math::Point3D RayTracer::APrimitive::whereHit(Ray &ray)
{
    return Math::Point3D();
}

Math::Vector3D RayTracer::APrimitive::normal(Math::Point3D &point)
{
    return Math::Vector3D();
}

float RayTracer::APrimitive::getColorBrillance(Math::Vector3D light_direction, Math::Vector3D normal, float ambiant_light)
{
    return 0;
}

float RayTracer::APrimitive::distanceBetween(const Math::Point3D& v1, const Math::Point3D& v2)
{
    float dx = v2._x - v1._x;
    float dy = v2._y - v1._y;
    float dz = v2._z - v1._z;

    return std::sqrt(dx * dx + dy * dy + dz * dz);
}
