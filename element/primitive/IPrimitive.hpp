/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-raytracer-tom.facon
** File description:
** IPrimitive
*/

#ifndef IPRIMITIVE_HPP_
    #define IPRIMITIVE_HPP_

#include <iostream>
#include "Parser.hpp"
#include <memory>
#include "Ray.hpp"
#include "Color.hpp"
#include "../../src/Error.hpp"
#include "Camera.hpp"
#include "Lights.hpp"
#include <SFML/Graphics.hpp>

namespace RayTracer {
    class Element;

    class IPrimitive {
        public:
            virtual ~IPrimitive() = default;
            virtual void printInfo(std::ostream &os) = 0;
            virtual bool handlePrimitiveDisplay(RayTracer::Ray &r, std::pair<Math::Point3D, sf::Color> &nearest_color_point, std::pair<Lights, Camera> &utils, bool isPixel) = 0;
            virtual void translation(Math::Vector3D vector) = 0;
        protected:
            virtual bool hits(Ray &ray) = 0;
            virtual Math::Point3D whereHit(Ray &ray) = 0;
            virtual Math::Vector3D normal(Math::Point3D &point) = 0;
            virtual float getColorBrillance(Math::Vector3D light_direction, Math::Vector3D normal, float ambiant_light) = 0;
    };
}

std::ostream &operator<<(std::ostream &os, const std::unique_ptr<RayTracer::IPrimitive>&);

#endif /* !IPRIMITIVE_HPP_ */
