/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Rectangle3D
*/

#include "Rectangle3D.hpp"

RayTracer::Rectangle3D::Rectangle3D()
{
    _bottom_side._x = 1;
    _left_side._y = 1;

}

RayTracer::Rectangle3D::Rectangle3D(Math::Point3D origin, Math::Vector3D bottom_side, Math::Vector3D left_side) : _origin(origin),
    _bottom_side(bottom_side), _left_side(left_side)
{
}

RayTracer::Rectangle3D::Rectangle3D(const Rectangle3D &other)
{
    _origin = other._origin;
    _left_side = other._left_side;
    _bottom_side = other._bottom_side;
}

RayTracer::Rectangle3D::Rectangle3D(const Rectangle3D &&other)
{
    _origin = std::move(other._origin);
    _left_side = std::move(other._left_side);
    _bottom_side = std::move(other._bottom_side);
}

RayTracer::Rectangle3D& RayTracer::Rectangle3D::operator=(const RayTracer::Rectangle3D& other)
{
    if (this != &other) {
        _origin = other._origin;
        _left_side = other._left_side;
        _bottom_side = other._bottom_side;
    }
    return *this;
}

RayTracer::Rectangle3D& RayTracer::Rectangle3D::operator=(const RayTracer::Rectangle3D&& other)
{
    if (this != &other) {
        _origin = std::move(other._origin);
        _left_side = std::move(other._left_side);
        _bottom_side = std::move(other._bottom_side);
    }
    return *this;
}


RayTracer::Rectangle3D::~Rectangle3D()
{
}

Math::Point3D RayTracer::Rectangle3D::pointAt(double u, double v)
{
    return Math::Point3D(_origin + _left_side * v + _bottom_side * u);
}
