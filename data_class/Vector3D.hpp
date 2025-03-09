/*
** EPITECH PROJECT, 2024
** bs
** File description:
** Vector3D
*/

#ifndef Vector3D_HPP_
    #define Vector3D_HPP_

#include <iostream>
#include <math.h>

namespace Math {
    class Vector3D {
        public:
            Vector3D();
            Vector3D(double x, double y, double z);
            Vector3D(const Vector3D &other);
            Vector3D(const Vector3D &&other);
            Vector3D& operator=(const Vector3D& other);
            Vector3D& operator=(const Vector3D&& other);
            Vector3D operator+(Vector3D vector);
            void operator+=(Vector3D &vector);
            Vector3D operator-(Vector3D &vector);
            void operator-=(Vector3D &vector);
            Vector3D operator*(Vector3D &vector);
            void operator*=(Vector3D &vector);
            Vector3D operator/(Vector3D &vector);
            void operator/=(Vector3D &vector);
            Vector3D operator*(double param);
            void operator*=(double param);
            Vector3D operator/(double param);
            void operator/=(double param);
            ~Vector3D() = default;
            double dotProduct(Vector3D v1, Vector3D v2);
            void normalize(void);
            double length();
            double _x;
            double _y;
            double _z;
        private:
    };
};

std::ostream& operator<<(std::ostream& os, const Math::Vector3D& position);

#endif /* !Vector3D_HPP_ */
