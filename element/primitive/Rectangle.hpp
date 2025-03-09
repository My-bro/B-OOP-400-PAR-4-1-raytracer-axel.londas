/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Rectangle
*/

#ifndef RECTANGLE_HPP_
    #define RECTANGLE_HPP_

#include <iostream>
#include "APrimitive.hpp"
#include "Rectangle3D.hpp"
#include "Parser.hpp"
#include "Color.hpp"

namespace RayTracer {
    class Rectangle : public APrimitive {
        public:
            Rectangle(libconfig::Setting &setting);
            void printInfo(std::ostream &os) override;
            bool handlePrimitiveDisplay(RayTracer::Ray &r, std::pair<Math::Point3D, sf::Color> &nearest_color_point, std::pair<Lights, Camera> &utils, bool isPixel) override;
            Math::Point3D whereHit(Ray &ray) override;
        protected:
        private:
            bool hits(Ray &ray) override;
            void putPosition(libconfig::Setting &setting) override;
            void putColor(libconfig::Setting &setting) override;
            void putDimensions(libconfig::Setting &setting);
            void putNormal(libconfig::Setting &setting);
            Math::Vector3D _dimensions;
            Math::Vector3D _normal;
    };
}

#endif /* !RECTANGLE_HPP_ */
