/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-raytracer-tom.facon
** File description:
** Camera
*/

#include "Camera.hpp"
#include <cmath>

void RayTracer::Camera::constructorPutResolution(Parser &parser)
{
    try {
        libconfig::Setting &camera = parser.myLookup("camera");
        try {
            this->_reso._x = static_cast<int>(camera["resolution"]["width"]);
        } catch(const libconfig::SettingNotFoundException &nfex) {
            std::cerr << "No 'width' setting in configuration file." << std::endl;
            throw ParserError();
        }
        try {
            this->_reso._y = static_cast<int>(camera["resolution"]["height"]);
        } catch(const libconfig::SettingNotFoundException &nfex) {
            std::cerr << "No 'height' setting in configuration file."<< std::endl;
            throw ParserError();
        }
    } catch(const libconfig::SettingNotFoundException &nfex) {
        std::cerr << "No 'camera' setting in configuration file." << std::endl;
        throw ParserError();
    }
}

void RayTracer::Camera::constructorPutPosition(Parser &parser)
{
    try {
        libconfig::Setting &camera = parser.myLookup("camera");
        try {
            this->_origin._x = static_cast<float>(camera["position"]["x"]);
        } catch(const libconfig::SettingNotFoundException &nfex) {
            std::cerr << "No 'x' setting in configuration file." << std::endl;
            throw ParserError();
        }
        try {
            this->_origin._y = static_cast<float>(camera["position"]["y"]);
        } catch(const libconfig::SettingNotFoundException &nfex) {
            std::cerr << "No 'y' setting in configuration file." << std::endl;
            throw ParserError();
        }
        try {
            this->_origin._z = static_cast<float>(camera["position"]["z"]);
        } catch(const libconfig::SettingNotFoundException &nfex) {
            std::cerr << "No 'z' setting in configuration file." << std::endl;
            throw ParserError();
        }
    } catch(const libconfig::SettingNotFoundException &nfex) {
        std::cerr << "No 'camera' setting in configuration file." << std::endl;
        throw ParserError();
    }
}

void RayTracer::Camera::constructorPutRotation(Parser &parser)
{
    try {
        libconfig::Setting &camera = parser.myLookup("camera");
        try {
            this->_rotation._x = static_cast<int>(camera["rotation"]["x"]);
        } catch(const libconfig::SettingNotFoundException &nfex) {
            std::cerr << "No 'x' setting in configuration file." << std::endl;
            throw ParserError();
        }
        try {
            this->_rotation._y = static_cast<int>(camera["rotation"]["y"]);
        } catch(const libconfig::SettingNotFoundException &nfex) {
            std::cerr << "No 'y' setting in configuration file." << std::endl;
            throw ParserError();
        }
        try {
            this->_rotation._z = static_cast<int>(camera["rotation"]["z"]);
        } catch(const libconfig::SettingNotFoundException &nfex) {
            std::cerr << "No 'z' setting in configuration file." << std::endl;
            throw ParserError();
        }
    } catch(const libconfig::SettingNotFoundException &nfex) {
        std::cerr << "No 'camera' setting in configuration file." << std::endl;
        throw ParserError();
    }
}

void RayTracer::Camera::constructorPutFieldOfView(Parser &parser)
{
    try {
        libconfig::Setting &camera = parser.myLookup("camera");
        try {
            this->_field_of_view = camera["fieldOfView"];
        } catch(const libconfig::SettingNotFoundException &nfex) {
            std::cerr << "No 'fieldOfView' setting in configuration file." << std::endl;
            throw ParserError();
        }
    } catch(const libconfig::SettingNotFoundException &nfex) {
        std::cerr << "No 'camera' setting in configuration file." << std::endl;
        throw ParserError();
    }
}

RayTracer::Camera::Camera(Parser &parser)
{
    this->constructorPutResolution(parser);
    this->constructorPutPosition(parser);
    this->constructorPutRotation(parser);
    this->constructorPutFieldOfView(parser);
}

RayTracer::Ray RayTracer::Camera::ray(double u, double v)
{
    Math::Point3D pixel = _origin - _screen.pointAt(u, v);
    Math::Vector3D direction(pixel._x , pixel._y, pixel._z);
    return Ray(_origin, direction);
}

RayTracer::Camera::Camera(void)
{
    _origin = Math::Point3D(0,0,-1000);
}

std::ostream &operator<<(std::ostream &os, RayTracer::Camera &camera)
{
    os << "Camera: " << std::endl;
    os << "Resolution: " << camera._reso._x << ", "<< camera._reso._y  << std::endl;
    os << "Position: " << camera._origin << std::endl;
    os << "Rotation: " << camera._rotation << std::endl;
    os << "Field of view: " << camera._field_of_view << std::endl;
    return os;
}