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
#include <vector>
#include "primitive/Sphere.hpp"
#include "Camera.hpp"
#include "math/Vector3d.hpp"
#include "math/Color.hpp"
#include <SFML/Graphics.hpp>

int main(int ac, char **av) {

    if (ac == 2 && std::string(av[1]) == "--help") {
        std::cout << "Usage: " << av[0] << " <SCENE_FILE>\n";
        std::cout << "  SCENE_FILE: scene configuration\n";
        return 0;
    }

    int width = 400;
    int height = 400;

    Camera camera;
    camera.width = width;
    camera.height = height;
    camera.position = {0, 0, 0};

    RayTracer::Sphere sphere(Vector3d{0, 0, -5}, 1.0, Color{255, 0, 0});

    sf::RenderWindow window(sf::VideoMode(width, height), "Ray Tracer");
    sf::Image image;
    image.create(width, height);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            Ray ray = camera.generateRay(x, y);
            HitInfo hit = sphere.hits(ray);

            if (hit.hit) {
                image.setPixel(x, y, sf::Color(255, 0, 0));
            } else {
                image.setPixel(x, y, sf::Color(0, 0, 255));
            }
        }
    }

    sf::Texture texture;
    texture.loadFromImage(image);
    sf::Sprite sprite(texture);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(sprite);
        window.display();
    }
    return 0;
}
