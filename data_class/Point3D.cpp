/*
** EPITECH PROJECT, 2024
** bs
** File description:
** Point3D
*/

#include "Point3D.hpp"

Math::Point3D::Point3D() : _x(0), _y(0), _z(0)
{
}

Math::Point3D::Point3D(double x, double y, double z) : _x(x), _y(y), _z(z)
{
}

Math::Point3D::Point3D(const Point3D &other)
{
    _x = other._x;
    _y = other._y;
    _z = other._z;
}

Math::Point3D::Point3D(const Point3D &&other)
{
    _x = std::move(other._x);
    _y = std::move(other._y);
    _z = std::move(other._z);
}

Math::Point3D& Math::Point3D::operator=(const Math::Point3D& other)
{
    if (this != &other) {
        _x = other._x;
        _y = other._y;
        _z = other._z;
    }
    return *this;
}

Math::Point3D& Math::Point3D::operator=(const Point3D&& other)
{
    if (this != &other) {
        _x = std::move(other._x);
        _y = std::move(other._y);
        _z = std::move(other._z);
    }
    return *this;
}

Math::Point3D::~Point3D()
{
}

Math::Point3D Math::Point3D::operator-(Math::Point3D vector)
{
    Point3D newVector;

    newVector._x = this->_x - vector._x;
    newVector._y = this->_y - vector._y;
    newVector._z = this->_z - vector._z;
    return newVector;
}

Math::Point3D Math::Point3D::operator+(Math::Vector3D vector)
{
    Point3D newPoint;

    newPoint._x = this->_x + vector._x;
    newPoint._y = this->_y + vector._y;
    newPoint._z = this->_z + vector._z;
    return newPoint;
}

std::ostream& operator<<(std::ostream& os, const Math::Point3D& position)
{
    os << "Point3D: x: " << position._x << " y: " << position._y << " z: " << position._z;
    return os;
}
