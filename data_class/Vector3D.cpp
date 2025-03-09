/*
** EPITECH PROJECT, 2024
** bs
** File description:
** Vector3D
*/

#include "Vector3D.hpp"

Math::Vector3D::Vector3D() : _x(0), _y(0), _z(0)
{
}

Math::Vector3D::Vector3D(double x, double y, double z) : _x(x), _y(y), _z(z)
{
}

Math::Vector3D::Vector3D(const Vector3D &other)
{
    _x = other._x;
    _y = other._y;
    _z = other._z;
}

Math::Vector3D::Vector3D(const Vector3D &&other)
{
    _x = std::move(other._x);
    _y = std::move(other._y);
    _z = std::move(other._z);
}

Math::Vector3D& Math::Vector3D::operator=(const Math::Vector3D& other)
{
    if (this != &other) {
        _x = other._x;
        _y = other._y;
        _z = other._z;
    }
    return *this;
}

Math::Vector3D& Math::Vector3D::operator=(const Vector3D&& other)
{
    if (this != &other) {
        _x = std::move(other._x);
        _y = std::move(other._y);
        _z = std::move(other._z);
    }
    return *this;
}

double Math::Vector3D::length()
{
    return std::sqrt((_x * _x) + (_y *_y) + (_z * _z));
}

void Math::Vector3D::operator+=(Math::Vector3D &vector)
{
    _x = _x + vector._x;
    _y = _y + vector._y;
    _z = _z + vector._z;
}

Math::Vector3D Math::Vector3D::operator+(Math::Vector3D vector)
{
    Vector3D newVector;

    newVector._x = this->_x + vector._x;
    newVector._y = this->_y + vector._y;
    newVector._z = this->_z + vector._z;
    return newVector;
}

void Math::Vector3D::operator-=(Math::Vector3D &vector)
{
    _x = _x - vector._x;
    _y = _y - vector._y;
    _z = _z - vector._z;
}

Math::Vector3D Math::Vector3D::operator-(Math::Vector3D &vector)
{
    Vector3D newVector;

    newVector._x = this->_x - vector._x;
    newVector._y = this->_y - vector._y;
    newVector._z = this->_z - vector._z;
    return newVector;
}

void Math::Vector3D::operator*=(Math::Vector3D &vector)
{
    _x = _x * vector._x;
    _y = _y * vector._y;
    _z = _z * vector._z;
}

Math::Vector3D Math::Vector3D::operator*(Math::Vector3D &vector)
{
    Vector3D newVector;

    newVector._x = this->_x * vector._x;
    newVector._y = this->_y * vector._y;
    newVector._z = this->_z * vector._z;
    return newVector;
}

void Math::Vector3D::operator/=(Math::Vector3D &vector)
{
    _x = _x / vector._x;
    _y = _y / vector._y;
    _z = _z / vector._z;
}

Math::Vector3D Math::Vector3D::operator/(Math::Vector3D &vector)
{
    Vector3D newVector;

    newVector._x = this->_x / vector._x;
    newVector._y = this->_y / vector._y;
    newVector._z = this->_z / vector._z;
    return newVector;
}

void Math::Vector3D::operator/=(double param)
{
    _x = _x / param;
    _y = _y / param;
    _z = _z / param;
}

Math::Vector3D Math::Vector3D::operator/(double param)
{
    Vector3D newVector;

    newVector._x = this->_x / param;
    newVector._y = this->_y / param;
    newVector._z = this->_z / param;
    return newVector;
}

void Math::Vector3D::operator*=(double param)
{
    _x = _x * param;
    _y = _y * param;
    _z = _z * param;
}

Math::Vector3D Math::Vector3D::operator*(double param)
{
    Vector3D newVector;

    newVector._x = this->_x * param;
    newVector._y = this->_y * param;
    newVector._z = this->_z * param;
    return newVector;
}

std::ostream& operator<<(std::ostream& os, const Math::Vector3D& position)
{
    os << "Position: " << position._x << ", " << position._y << ", " << position._z;
    return os;
}

double Math::Vector3D::dotProduct(Vector3D v1, Vector3D v2)
{
    double dot = 0.0;

    dot = v1._x * v2._x + v1._y * v2._y + v1._z * v2._z;
    return dot;
}

void Math::Vector3D::normalize()
{
    double len = length();
    _x = _x / len;
    _y = _y / len;
    _z = _z / len;
}
