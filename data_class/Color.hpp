/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-raytracer-tom.facon
** File description:
** Color
*/

#ifndef COLOR_HPP_
    #define COLOR_HPP_

#include <iostream>

namespace RayTracer {
    class Color {
        public:
            Color(int r, int g, int b);
            Color();
            Color(const Color &other);
            Color(const Color &&other);
            Color& operator=(const Color& other);
            Color& operator=(const Color&& other);
            Color operator*(const double& other) const;
            int r;
            int g;
            int b;
    };
};
std::ostream& operator<<(std::ostream& os, const RayTracer::Color& color);

#endif /* !COLOR_HPP_ */
