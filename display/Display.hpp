/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-raytracer-tom.facon
** File description:
** Display
*/

#ifndef DISPLAY_HPP_
    #define DISPLAY_HPP_

#include <iostream>
#include "Element.hpp"
#include <SFML/Graphics.hpp>

class Display {
    public:
        Display();
        Display(int &screenWidth, int &screenHeight, int &frameRate);
        void launch(RayTracer::Element &element);
        void initWindow(RayTracer::Element &element, std::string title);
        int _screenWidth;
        int _screenHeight;
        int _frameRate;

        sf::RenderWindow _window;
        sf::Event _event;

        double _u;
        double _v;
        bool firstFrame = true;
        RayTracer::Ray _r;
        sf::Image _image;
        sf::Texture _texture;
         sf::Sprite _sprite;

    protected:
    private:
        void handlePicture(RayTracer::Element &element);
};

#endif /* !DISPLAY_HPP_ */
