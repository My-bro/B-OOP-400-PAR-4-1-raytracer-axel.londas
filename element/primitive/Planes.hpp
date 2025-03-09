/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-raytracer-tom.facon
** File description:
** Planes
*/

#ifndef PLANES_HPP_
    #define PLANES_HPP_

#include <iostream>
#include "APrimitive.hpp"
#include "Rectangle3D.hpp"
#include "Parser.hpp"
#include "Color.hpp"

namespace RayTracer {
    class Planes : public APrimitive {
        public:
            Planes(libconfig::Setting &setting);
            void printInfo(std::ostream &os) override;
            bool handlePrimitiveDisplay(RayTracer::Ray &r, std::pair<Math::Point3D, sf::Color> &nearest_color_point, std::pair<Lights, Camera> &utils, bool isPixel) override;
            Math::Point3D whereHit(Ray &ray) override;
        private:
            bool hits(Ray &ray) override;
            void putPosition(libconfig::Setting &setting) override;
            void putColor(libconfig::Setting &setting) override;
            void putNormal(libconfig::Setting &setting);
            Math::Vector3D _normal;
    };
}

#endif /* !PLANES_HPP_ */
