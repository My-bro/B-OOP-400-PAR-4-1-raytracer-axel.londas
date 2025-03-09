# Raytracer

A CPU-based raytracer implementation that renders 3D scenes defined in configuration files.

![Screenshot 1](assets/screen1.png)
![Screenshot 2](assets/screen2.png)
![Screenshot 3](assets/screen3.png)

## Description

This raytracer supports:
- Spheres, planes, cylinders and rectangles primitives
- Point lights and ambient lighting
- Camera positioning and field of view
- Real-time rendering with SFML
- Scene configuration through .cfg files
- Interactive camera movement (ZQSD keys)

## Requirements

- C++ compiler with C++20 support
- SFML library
- libconfig++

## Building

```bash
make