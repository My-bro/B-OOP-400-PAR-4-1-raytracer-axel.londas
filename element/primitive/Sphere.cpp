/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-raytracer-tom.facon
** File description:
** Sphere
*/

#include "Sphere.hpp"

void RayTracer::Sphere::putPosition(libconfig::Setting &setting)
{
    try {
        this->_center._x = setting["x"];
    } catch(const libconfig::SettingNotFoundException &nfex) {
        std::cerr << "No 'x' setting in configuration file." << std::endl;
        throw ParserError();
    }
    try {
        this->_center._y = setting["y"];
    } catch(const libconfig::SettingNotFoundException &nfex) {
        std::cerr << "No 'y' setting in configuration file." << std::endl;
        throw ParserError();
    }
    try {
        this->_center._z = setting["z"];
    } catch(const libconfig::SettingNotFoundException &nfex) {
        std::cerr << "No 'z' setting in configuration file." << std::endl;
        throw ParserError();
    }
}

void RayTracer::Sphere::putColor(libconfig::Setting &setting)
{
    try {
        this->_color.r = setting["color"]["r"];
    } catch(const libconfig::SettingNotFoundException &nfex) {
        std::cerr << "No 'r' setting in configuration file." << std::endl;
        throw ParserError();
    }

    try {
        this->_color.g = setting["color"]["g"];
    } catch(const libconfig::SettingNotFoundException &nfex) {
        std::cerr << "No 'g' setting in configuration file." << std::endl;
        throw ParserError();
    }

    try {
        this->_color.b = setting["color"]["b"];
    } catch(const libconfig::SettingNotFoundException &nfex) {
        std::cerr << "No 'b' setting in configuration file." << std::endl;
        throw ParserError();
    }
}

RayTracer::Sphere::Sphere(libconfig::Setting &setting)
{
    this->_type = "sphere";
    try {
        this->_name = setting["name"].c_str();
    } catch(const libconfig::SettingNotFoundException &nfex) {
        std::cerr << "No 'name' setting in configuration file." << std::endl;
        throw ParserError();
    }
    putPosition(setting);
    putColor(setting);
    try {
        this->_radius = setting["r"];
    } catch(const libconfig::SettingNotFoundException &nfex) {
        std::cerr << "No 'radius' setting in configuration file." << std::endl;
        throw ParserError();
    }
}

void RayTracer::Sphere::printInfo(std::ostream &os)
{
    os << "Sphere: " << _name << std::endl;
    os << "Position: " << _center << std::endl;
    os << "Color: " << _color << std::endl;
    os << "Radius: " << _radius << std::endl;
}

bool RayTracer::Sphere::hits(Ray& ray)
{
    Math::Point3D point = ray._origin - _center;
    Math::Vector3D vec(point._x, point._y, point._z);
    double a = ray._direction.dotProduct(ray._direction, ray._direction);
    double b = 2.0 * ray._direction.dotProduct(vec, ray._direction);
    double c = vec.dotProduct(vec, vec) - (_radius * _radius);
    double discriminant = (b * b) - (4.0 * a * c);

    return discriminant >= 0;
}

Math::Point3D RayTracer::Sphere::whereHit(Ray &ray)
{
    Math::Point3D point = ray._origin - _center;
    Math::Vector3D vec(point._x, point._y, point._z);
    double a = ray._direction.dotProduct(ray._direction, ray._direction);
    double b = 2.0 * ray._direction.dotProduct(vec, ray._direction);
    double c = vec.dotProduct(vec, vec) - (_radius * _radius);
    double discriminant = (b * b) - (4.0 * a * c);
    double t = (-b - sqrt(discriminant)) / (2.0 * a);
    Math::Point3D hit = ray._origin + ray._direction * t;

    return hit;
}

Math::Vector3D RayTracer::Sphere::normal(Math::Point3D &point)
{
    Math::Point3D normal_point = point - _center;
    Math::Vector3D normal(normal_point._x, normal_point._y, normal_point._z);
    normal.normalize();

    return normal;
}

float RayTracer::Sphere::getColorBrillance(Math::Vector3D light_direction, Math::Vector3D normal, float ambiant_light)
{
    light_direction.normalize();
    Math::Vector3D negative_light_direction = light_direction * -1;
    float d_product = fmax(light_direction.dotProduct(negative_light_direction, normal), ambiant_light);

    return d_product;
}

bool RayTracer::Sphere::handlePrimitiveDisplay(RayTracer::Ray &r, std::pair<Math::Point3D, sf::Color> &nearest_color_point, std::pair<Lights, Camera> &utils, bool isPixelEmpty)
{
    if (this->hits(r)) {
        Math::Point3D hit = whereHit(r);
        Math::Vector3D normal = this->normal(hit);
        float d = getColorBrillance(utils.first._direction, normal, utils.first._ambient);
        RayTracer::Color color_ombrer = _color * d;
        sf::Color color_mbr = {static_cast<sf::Uint8>(color_ombrer.r), static_cast<sf::Uint8>(color_ombrer.g), static_cast<sf::Uint8>(color_ombrer.b)};
        if (isPixelEmpty) {
            nearest_color_point.first = hit;
            nearest_color_point.second = color_mbr;
            return false;
        } else if (distanceBetween(utils.second._origin, hit) < distanceBetween(utils.second._origin, nearest_color_point.first)) {
            nearest_color_point.first = hit;
            nearest_color_point.second = color_mbr;
        }
    }
    return isPixelEmpty;
}
