/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** PrimitiveFactory
*/

#include "PrimitiveFactory.hpp"

RayTracer::PrimitiveFactory::PrimitiveFactory(Parser &parser)
{
     try {
        libconfig::Setting &primitives = parser.myLookup("primitives");
        libconfig::Setting &sphere = primitives["spheres"];
        for (int i = 0; i < sphere.getLength(); i++) {
            libconfig::Setting &setting = sphere[i];
            this->_primitives.emplace_back(std::make_unique<Sphere>(setting));
        }
    } catch(const libconfig::SettingNotFoundException &nfex) {
        std::cout << "No 'spheres' setting in configuration file." << std::endl;
    } try {
        libconfig::Setting &primitives = parser.myLookup("primitives");
        libconfig::Setting &planes = primitives["planes"];
        for (int i = 0; i < planes.getLength(); i++) {
            libconfig::Setting &setting = planes[i];
            this->_primitives.emplace_back(std::make_unique<Planes>(setting));
        }
    } catch(const libconfig::SettingNotFoundException &nfex) {
        std::cout << "No 'planes' setting in configuration file." << std::endl;
    } try {
        libconfig::Setting &primitives = parser.myLookup("primitives");
        libconfig::Setting &cylinder = primitives["cylinders"];
        for (int i = 0; i < cylinder.getLength(); i++) {
            libconfig::Setting &setting = cylinder[i];
            this->_primitives.emplace_back(std::make_unique<Cylinder>(setting));
        }
    } catch(const libconfig::SettingNotFoundException &nfex) {
        std::cout << "No 'cylinders' setting in configuration file." << std::endl;
    } try {
        libconfig::Setting &primitives = parser.myLookup("primitives");
        libconfig::Setting &rectangle = primitives["rectangles"];
        for (int i = 0; i < rectangle.getLength(); i++) {
            libconfig::Setting &setting = rectangle[i];
            this->_primitives.emplace_back(std::make_unique<Rectangle>(setting));
        }
    } catch(const libconfig::SettingNotFoundException &nfex) {
        std::cout<< "No 'Rectangle' setting in configuration file." << std::endl;
    }
    if (_primitives.size() == 0) {
        throw ParserError();
    }
}

void RayTracer::PrimitiveFactory::displayPrimitives(RayTracer::Element &element, RayTracer::Ray &r, std::pair<Math::Point3D, sf::Color> &nearest_color_point)
{
    std::pair<Lights, Camera> utils = std::make_pair(element.lights, element.camera);

    for (std::size_t i = 0; i < _primitives.size(); i++) {
        bool tmp = _primitives[i]->handlePrimitiveDisplay(r, nearest_color_point, utils, element.pixelIsEmpty);
        element.pixelIsEmpty = tmp;
    }
}
