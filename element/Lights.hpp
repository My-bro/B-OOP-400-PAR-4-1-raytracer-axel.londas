/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-raytracer-tom.facon
** File description:
** Lights
*/

#ifndef LIGHTS_HPP_
    #define LIGHTS_HPP_

#include "Parser.hpp"
#include "Color.hpp"
#include "Point3D.hpp"
#include <vector>

namespace RayTracer {
    class Lights {
        public:
            Lights();
            Lights(Parser &parser);
            float _ambient;
            float _diffuse;
            std::vector<Math::Point3D> _points;
            Math::Vector3D _direction;
        protected:
        private:
    };
}

std::ostream &operator<<(std::ostream &os, RayTracer::Lights &lights);

#endif /* !LIGHTS_HPP_ */
