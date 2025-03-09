/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-raytracer-tom.facon
** File description:
** Display
*/

#include "Display.hpp"
#include "Vector3D.hpp"

Display::Display()
{
}

float distanceBetween(const Math::Point3D& v1, const Math::Point3D& v2)
{
    float dx = v2._x - v1._x;
    float dy = v2._y - v1._y;
    float dz = v2._z - v1._z;

    return std::sqrt(dx * dx + dy * dy + dz * dz);
}

Display::Display(int &screenWidth, int &screenHeight, int &frameRate)
{
    this->_screenWidth = screenWidth;
    this->_screenHeight = screenHeight;
    this->_frameRate = frameRate;
}

void Display::initWindow(RayTracer::Element &element, std::string title)
{
    this->_window.create(sf::VideoMode(element.camera._reso._x, element.camera._reso._y), title);
}

void Display::handlePicture(RayTracer::Element &element)
{
    Math::Point3D point;
    sf::Color color;
    std::pair<Math::Point3D, sf::Color> nearest_color_point = std::make_pair(point, color);

    for (unsigned int x = 0; x < _image.getSize().x; ++x) {
        for (unsigned int y = 0; y < _image.getSize().y; ++y) {
            _image.setPixel(x, y, sf::Color::Black);
        }
    }

    for (double y = element.camera._reso._y; y > 0; y--) {
        for (double x = 0; x < element.camera._reso._x; x++) {
            element.pixelIsEmpty = true;

            _u = x / element.camera._reso._x;
            _v = y / element.camera._reso._y;
            _r = element.camera.ray(_u, _v);

            element.primitivesFactory->displayPrimitives(element, _r, nearest_color_point);

            if (!element.pixelIsEmpty) {
                _image.setPixel(x, y, nearest_color_point.second);
            }
            if (firstFrame == true) {
                std::cout << static_cast<int>(nearest_color_point.second.r) << " " << static_cast<int>(nearest_color_point.second.g) << " " << static_cast<int>(nearest_color_point.second.b) << std::endl;
            }
        }
    }
    _texture.loadFromImage(_image);
    _sprite.setTexture(_texture);
    _window.draw(_sprite);
}

void Display::launch(RayTracer::Element &element)
{
    sf::Texture texture;
    texture.loadFromFile("./assets/nvidia-geforce-rtx-logo.png");
    double camera_speed = 0.1;
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setScale(sf::Vector2f(0.05, 0.05));
    sprite.setPosition(sf::Vector2f(750.0f, 700.0f));
    _image.create(element.camera._reso._x, element.camera._reso._y, sf::Color::Black);
    _window.setFramerateLimit(60);

    initWindow(element, "Raytracer");
    std::cout << "P3" << std::endl;
    std::cout << element.camera._reso._x << " " << element.camera._reso._y << std::endl;
    std::cout << "255" << std::endl;
    while (_window.isOpen())
    {
        sf::Event event;
        while (_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                _window.close();
        }

        _window.clear();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z))
            element.camera._origin._z += camera_speed;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
            element.camera._origin._x += camera_speed;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
            element.camera._origin._z -= camera_speed;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
            element.camera._origin._x -= camera_speed;

        handlePicture(element);
        _window.draw(sprite);
        _window.display();
        firstFrame = false;
    }
}