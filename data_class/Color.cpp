/*
** EPITECH PROJECT, 2024
** b-OOP-400-PAR-4-1-raytracer-tom.facon
** File description:
** Color
*/

#include "Color.hpp"

RayTracer::Color::Color(int r, int g, int b)
{
    this->r = r;
    this->g = g;
    this->b = b;
}

RayTracer::Color::Color()
{
    this->r = 0;
    this->g = 0;
    this->b = 0;
}


std::ostream& operator<<(std::ostream& os, const RayTracer::Color& color)
{
    os << "Color: " << color.r << ", " << color.g << ", " << color.b;
    return os;
}

RayTracer::Color::Color(const RayTracer::Color &other)
{
    r = other.r;
    g = other.g;
    b = other.b;
}

RayTracer::Color::Color(const RayTracer::Color &&other)
{
    r = std::move(other.r);
    g = std::move(other.g);
    b = std::move(other.b);
}

RayTracer::Color& RayTracer::Color::operator=(const RayTracer::Color& other)
{
    if (this != &other) {
        r = other.r;
        g = other.g;
        b = other.b;
    }
    return *this;
}

RayTracer::Color& RayTracer::Color::operator=(const RayTracer::Color&& other)
{
    if (this != &other) {
        r = std::move(other.r);
        g = std::move(other.g);
        b = std::move(other.b);
    }
    return *this;
}

RayTracer::Color RayTracer::Color::operator*(const double& other) const
{
    int red = r * other;
    int green = g * other;
    int blue = b * other;

    return RayTracer::Color{red, green, blue};
}
