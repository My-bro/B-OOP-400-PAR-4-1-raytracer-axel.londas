/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-raytracer-tom.facon
** File description:
** Lights
*/

#include "Lights.hpp"
#include "../src/Error.hpp"

RayTracer::Lights::Lights()
{
}

RayTracer::Lights::Lights(Parser &parser)
{
    try {
        libconfig::Setting &lights = parser.myLookup("lights");
        try {
            this->_ambient = lights["ambient"];
        } catch(const libconfig::SettingNotFoundException &nfex) {
            std::cerr << "No 'ambient' setting in configuration file." << std::endl;
            throw ParserError();
        }
        try {
            this->_diffuse = lights["diffuse"];
        } catch(const libconfig::SettingNotFoundException &nfex) {
            std::cerr << "No 'diffuse' setting in configuration file." << std::endl;
            throw ParserError();
        }
        try {
            libconfig::Setting &points = lights["point"];
            for (int i = 0; i < points.getLength(); i++) {
                Math::Point3D pos;
                try {
                    pos._x = static_cast<int>(points[i]["x"]);
                } catch(const libconfig::SettingNotFoundException &nfex) {
                    std::cerr << "No 'x' setting in configuration file." << std::endl;
                    throw ParserError();
                }
                try {
                    pos._y = static_cast<int>(points[i]["y"]);
                } catch(const libconfig::SettingNotFoundException &nfex) {
                    std::cerr << "No 'y' setting in configuration file." << std::endl;
                    throw ParserError();
                }
                try {
                    pos._z = static_cast<int>(points[i]["z"]);
                } catch(const libconfig::SettingNotFoundException &nfex) {
                    std::cerr << "No 'z' setting in configuration file." << std::endl;
                    throw ParserError();
                }
                this->_points.emplace_back(pos);
            }
        } catch(const libconfig::SettingNotFoundException &nfex) {
            std::cerr << "No 'points' setting in configuration file." << std::endl;
            throw ParserError();
        }
    } catch(const libconfig::SettingNotFoundException &nfex) {
        std::cerr << "No 'lights' setting in configuration file." << std::endl;
        throw ParserError();
    }
    this->_direction = Math::Vector3D(0, 1, -1);
}

std::ostream &operator<<(std::ostream &os, RayTracer::Lights &lights)
{
    os << "Lights: " << std::endl;
    os << "Ambient: " << lights._ambient << std::endl;
    os << "Diffuse: " << lights._diffuse << std::endl;
    os << "Points: " << std::endl;
    for (int i = 0; i < lights._points.size(); i++) {
        os << "\tPoint " << i << ": " << lights._points[i] << std::endl;
    }
    return os;
}
