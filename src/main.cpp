/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-raytracer-tom.facon
** File description:
** main
*/

#include <iostream>
#include "Error.hpp"
#include <SFML/Graphics.hpp>
#include "Display.hpp"
#include "Element.hpp"

void printEveryElement(RayTracer::Element &element)
{
    std::cout << element.camera << std::endl;
    std::cout << element.lights << std::endl;
    for (std::size_t i = 0; i < element.primitivesFactory->_primitives.size(); i++)
        std::cout << element.primitivesFactory->_primitives[i] << std::endl;
}

int main(int ac, char *const av[])
{
    try {
        CommandHandling CommandHandling(ac, av);
        Parser parser(av);
        RayTracer::Element element(parser);
        // printEveryElement(element);
        Display display;
        display.launch(element);
    } catch (ParserError) {
        return 84;
    }
    return 0;
}
