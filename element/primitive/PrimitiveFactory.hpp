/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** PrimitiveFactory
*/

#ifndef PRIMITIVEFACTORY_HPP_
    #define PRIMITIVEFACTORY_HPP_

#include <memory>
#include <vector>
#include "IPrimitive.hpp"
#include "Sphere.hpp"
#include "Rectangle.hpp"
#include "Planes.hpp"
#include "Cylinder.hpp"
#include "Element.hpp"

namespace RayTracer {
    class Element;

    class PrimitiveFactory {
        public:
            PrimitiveFactory(Parser &parser);
            ~PrimitiveFactory() = default;
            void displayPrimitives(RayTracer::Element &element, RayTracer::Ray &r, std::pair<Math::Point3D, sf::Color> &nearest_color_point);
            std::vector<std::unique_ptr<RayTracer::IPrimitive>> _primitives;
    };
}

#endif /* !PRIMITIVEFACTORY_HPP_ */
