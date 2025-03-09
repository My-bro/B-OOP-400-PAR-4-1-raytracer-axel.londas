/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-raytracer-tom.facon
** File description:
** APrimitive
*/

#ifndef APRIMITIVE_HPP_
    #define APRIMITIVE_HPP_

#include "IPrimitive.hpp"
#include <memory>
#include <vector>
#include "Point3D.hpp"
#include "Vector3D.hpp"

namespace RayTracer {
    class APrimitive : public IPrimitive {
        public:
            APrimitive() = default;
            ~APrimitive() = default;
            void translation(Math::Vector3D vector) override;
        protected:
            Math::Point3D whereHit(Ray &ray) override;
            Math::Vector3D normal(Math::Point3D &point) override;
            float getColorBrillance(Math::Vector3D light_direction, Math::Vector3D normal, float ambiant_light) override;
            virtual void putPosition(libconfig::Setting &setting) = 0;
            virtual void putColor(libconfig::Setting &setting) = 0;
            float distanceBetween(const Math::Point3D& v1, const Math::Point3D& v2);
            std::string _type;
            std::string _name;
            Math::Point3D _center;
            Color _color;
    };
}

#endif /* !APRIMITIVE_HPP_ */
