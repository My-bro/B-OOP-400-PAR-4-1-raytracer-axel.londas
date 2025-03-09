/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-raytracer-tom.facon
** File description:
** Planes
*/

#include "Planes.hpp"

void RayTracer::Planes::putPosition(libconfig::Setting &setting)
{
    try {
        this->_center._x = setting["position"]["x"];
    } catch(const libconfig::SettingNotFoundException &nfex) {
        std::cerr << "No 'x' setting in configuration file." << std::endl;
        throw ParserError();
    }
    try {
        this->_center._y = setting["position"]["y"];
    } catch(const libconfig::SettingNotFoundException &nfex) {
        std::cerr << "No 'y' setting in configuration file." << std::endl;
        throw ParserError();
    }
    try {
        this->_center._z = setting["position"]["z"];
    } catch(const libconfig::SettingNotFoundException &nfex) {
        std::cerr << "No 'z' setting in configuration file." << std::endl;
        throw ParserError();
    }
}

void RayTracer::Planes::putNormal(libconfig::Setting &setting)
{
    try {
        this->_normal._x = setting["normal"]["x"];
    } catch(const libconfig::SettingNotFoundException &nfex) {
        std::cerr << "No 'x' setting in configuration file." << std::endl;
        throw ParserError();
    }
    try {
        this->_normal._y = setting["normal"]["y"];
    } catch(const libconfig::SettingNotFoundException &nfex) {
        std::cerr << "No 'y' setting in configuration file." << std::endl;
        throw ParserError();
    }
    try {
        this->_normal._z = setting["normal"]["z"];
    } catch(const libconfig::SettingNotFoundException &nfex) {
        std::cerr << "No 'z' setting in configuration file." << std::endl;
        throw ParserError();
    }

}

void RayTracer::Planes::putColor(libconfig::Setting &setting)
{
    try {
        this->_color.r = setting["color"]["r"];
    } catch(const libconfig::SettingNotFoundException &nfex) {
        std::cerr << "No 'r' setting in configuration file." << std::endl;
        throw ParserError();
    }
    try {
        this->_color.g = setting["color"]["g"];
    } catch(const libconfig::SettingNotFoundException &nfex) {
        std::cerr << "No 'g' setting in configuration file." << std::endl;
        throw ParserError();
    }
    try {
        this->_color.b = setting["color"]["b"];
    } catch(const libconfig::SettingNotFoundException &nfex) {
        std::cerr << "No 'b' setting in configuration file." << std::endl;
        throw ParserError();
    }
}

RayTracer::Planes::Planes(libconfig::Setting &setting)
{
    this->_type = "planes";
    try {
        this->_name = setting["name"].c_str();
    } catch(const libconfig::SettingNotFoundException &nfex) {
        std::cerr << "No 'name' setting in configuration file." << std::endl;
        throw ParserError();
    }
    putPosition(setting);
    putNormal(setting);
    putColor(setting);
}

bool RayTracer::Planes::hits(Ray &ray)
{
    Math::Vector3D vect(_center._x - ray._origin._x, _center._y - ray._origin._y, _center._z - ray._origin._z);
    double a = _normal.dotProduct(_normal, vect);
    double b = _normal.dotProduct(_normal, ray._direction);

    if (a == 0 || (a < 0 && b < 0) || (a > 0 && b > 0))
        return true;
    return false;
}

void RayTracer::Planes::printInfo(std::ostream &os)
{
    os << "Plane: " << _name << std::endl;
    os << "Position: " << _center << std::endl;
    os << "Normal: " << _normal << std::endl;
    os << "Color: " << _color << std::endl;
}

Math::Point3D RayTracer::Planes::whereHit(Ray &ray)
{
    Math::Vector3D vect(_center._x - ray._origin._x, _center._y - ray._origin._y, _center._z - ray._origin._z);
    double a = _normal.dotProduct(_normal, vect);
    double b = _normal.dotProduct(_normal, ray._direction);
    double t = a / b;

    return Math::Point3D(ray._origin._x + t * ray._direction._x, ray._origin._y + t * ray._direction._y, ray._origin._z + t * ray._direction._z);
}

bool RayTracer::Planes::handlePrimitiveDisplay(RayTracer::Ray &r, std::pair<Math::Point3D, sf::Color> &nearest_color_point, std::pair<Lights, Camera> &utils, bool isPixelEmpty)
{
    if (this->hits(r)) {
        Math::Point3D hit = whereHit(r);
        if (isPixelEmpty || distanceBetween(utils.second._origin, hit) < distanceBetween(utils.second._origin, nearest_color_point.first)) {
            sf::Color color = {static_cast<sf::Uint8>(_color.r), static_cast<sf::Uint8>(_color.g), static_cast<sf::Uint8>(_color.b)};
            nearest_color_point.first = hit;
            nearest_color_point.second = color;
            return false;
        }
    }
    return isPixelEmpty;
}
