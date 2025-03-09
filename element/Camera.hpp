/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-raytracer-tom.facon
** File description:
** Camera
*/

#ifndef CAMERA_HPP_
    #define CAMERA_HPP_

#include <libconfig.h++>
#include <iostream>
#include "Point3D.hpp"
#include "Rectangle3D.hpp"
#include "Parser.hpp"
#include "Resolution.hpp"
#include "Ray.hpp"
#include "../../src/Error.hpp"

namespace RayTracer {
    class Camera {
        public:
            Camera();
            Camera(Parser &parser);
            Rectangle3D _screen;
            Math::Point3D _reso;
            Math::Point3D _origin;
            Math::Point3D _rotation;
            double _field_of_view;
            Ray ray(double u, double v);
        protected:
        private:
            void constructorPutResolution(Parser &parser);
            void constructorPutPosition(Parser &parser);
            void constructorPutRotation(Parser &parser);
            void constructorPutFieldOfView(Parser &parser);
    };
}

std::ostream &operator<<(std::ostream &os, RayTracer::Camera &camera);

#endif /* !CAMERA_HPP_ */
