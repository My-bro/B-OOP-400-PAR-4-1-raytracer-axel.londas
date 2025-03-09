/*
** EPITECH PROJECT, 2024
** bs
** File description:
** Point3D
*/

#ifndef POINT3D_HPP_
    #define POINT3D_HPP_

#include "Vector3D.hpp"

namespace Math {
    class Point3D {
        public:
            Point3D();
            Point3D(double x, double y, double z);
            ~Point3D();
            Point3D(const Point3D &other);
            Point3D(const Point3D &&other);
            Point3D& operator=(const Point3D& other);
            Point3D& operator=(const Point3D&& other);
            Point3D operator-(Point3D vector);
            Point3D operator+(Vector3D vector);
            double _x;
            double _y;
            double _z;
        private:

    };
};

std::ostream& operator<<(std::ostream& os, const Math::Point3D& position);

#endif /* !POINT3D_HPP_ */
