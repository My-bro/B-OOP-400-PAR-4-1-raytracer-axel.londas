/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-raytracer-tom.facon
** File description:
** Element
*/

#include "Element.hpp"

RayTracer::Element::Element(Parser &parser) : camera(parser), lights(parser), primitivesFactory(std::make_unique<RayTracer::PrimitiveFactory>(parser)), pixelIsEmpty(true)
{
}
