/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-raytracer-tom.facon
** File description:
** Spheres
*/

#ifndef SPHERES_HPP_
    #define SPHERES_HPP_

#include "APrimitive.hpp"
#include "Parser.hpp"

namespace RayTracer {
    class Sphere : public APrimitive {
        public:
            Sphere(libconfig::Setting &setting);
            void printInfo(std::ostream &os) override;
            bool handlePrimitiveDisplay(RayTracer::Ray &r, std::pair<Math::Point3D, sf::Color> &nearest_color_point, std::pair<Lights, Camera> &utils, bool isPixel) override;
        private:
            void putPosition(libconfig::Setting &setting) override;
            void putColor(libconfig::Setting &setting) override;
            bool hits(Ray &ray) override;
            Math::Point3D whereHit(Ray &ray) override;
            Math::Vector3D normal(Math::Point3D &point) override;
            float getColorBrillance(Math::Vector3D light_direction, Math::Vector3D normal, float ambiant_light) override;
            double _radius;
    };
}

#endif /* !SPHERES_HPP_ */
