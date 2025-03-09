/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Rectangle3D
*/

#ifndef RECTANGLE3D_HPP_
    #define RECTANGLE3D_HPP_

#include "Point3D.hpp"
#include "Vector3D.hpp"

namespace RayTracer {
    class Rectangle3D {
        public:
            Rectangle3D();
            Rectangle3D(Math::Point3D origin, Math::Vector3D bottom_side, Math::Vector3D left_side);
            Rectangle3D(const Rectangle3D &other);
            Rectangle3D(const Rectangle3D &&other);
            Rectangle3D& operator=(const Rectangle3D& other);
            Rectangle3D& operator=(const Rectangle3D&& other);
            ~Rectangle3D();
            Math::Point3D _origin = Math::Point3D();
            Math::Vector3D _bottom_side = Math::Vector3D();
            Math::Vector3D _left_side = Math::Vector3D();
            Math::Point3D pointAt(double u, double v);
        private:
    };
};
#endif /* !RECTANGLE3D_HPP_ */
