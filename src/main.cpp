/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Tue, Apr, 2026                                                     *
 * Title           - raytracer                                                          *
 * Description     -                                                                    *
 *     main                                                                             *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ *
 *                                                                                      *
 *         ░        ░       ░░        ░        ░        ░░      ░░  ░░░░  ░             *
 *         ▒  ▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒▒▒  ▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒▒▒▒▒▒  ▒▒▒▒  ▒  ▒▒▒▒  ▒             *
 *         ▓      ▓▓▓       ▓▓▓▓▓  ▓▓▓▓▓▓▓  ▓▓▓▓      ▓▓▓  ▓▓▓▓▓▓▓        ▓             *
 *         █  ███████  ██████████  ███████  ████  ███████  ████  █  ████  █             *
 *         █        █  ███████        ████  ████        ██      ██  ████  █             *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ */

#include <iostream>
#include "raytracer.hpp"
#include <SFML/Graphics.hpp>

void write_color(Math::Vector3D color)
{
    std::cout << color.X << " " << color.Y << " " << color.Z << "\n";
}

int main(int ac, char **av) {
    (void)ac;
    (void)av;
    RayTracer::Camera camera;
    RayTracer::Sphere sphere(Math::Point3D(0, 0, -1), 0.5);

    camera.screen.origin = Math::Point3D(-1, -1, -1); 
    camera.screen.bottom_side = Math::Vector3D(2, 0, 0);
    camera.screen.left_side = Math::Vector3D(0, 2, 0);

    int width = 400;
    int height = 400;

    std::cout << "P3\n";
    std::cout << width << " " << height << "\n";
    std::cout << "255\n";

    for (int j = height - 1; j >= 0; j--) {
        for (int i = 0; i < width; i++) {
            double u = (double)i / (width - 1);
            double v =  (double)j / (height - 1);

            RayTracer::Ray ray = camera.ray(u, v);
            if (sphere.hits(ray))
                write_color(Math::Vector3D(255, 0, 0));
            else
                write_color(Math::Vector3D(0, 0, 255));
        }
    }

    sf::RenderWindow window(sf::VideoMode(width, height), "Ray Tracer");

    sf::Image image;
    sf::Texture texture;
    sf::Sprite sprite;

    if (!image.loadFromFile("output.ppm"))
    {
        std::cerr << "Failed to load image\n";
        return -1;
    }
    texture.loadFromImage(image);
    sprite.setTexture(texture);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.draw(sprite);
    }
    return 0;
}
