/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-raytracer-tom.facon
** File description:
** Element
*/

#ifndef ELEMENT_HPP_
    #define ELEMENT_HPP_

#include "Parser.hpp"
#include "Camera.hpp"
#include "Lights.hpp"
#include "PrimitiveFactory.hpp"
#include <memory.h>

namespace RayTracer {
    class PrimitiveFactory;

    class Element {
        public:
            Element(Parser &parser);
            Camera camera;
            Lights lights;
            std::unique_ptr<PrimitiveFactory> primitivesFactory;
            bool pixelIsEmpty;
    };
}

#endif /* !ELEMENT_HPP_ */
