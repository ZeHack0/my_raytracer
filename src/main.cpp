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
#include <fstream>
//#include "raytracer.hpp"
#include <SFML/Graphics.hpp>

// void write_color(Math::Vector3D color)
// {
//     std::cout << color.X << " " << color.Y << " " << color.Z << "\n";
// }

int main(int ac, char **av) {
    (void)ac;
    (void)av;

    if (ac == 2 && std::string(av[1]) == "--help") {
        std::cout << "Usage: " << av[0] << " <SCENE_FILE>\n";
        std::cout << "  SCENE_FILE: scene configuration\n";
        return 0;
    }

    // RayTracer::Camera camera;
    // RayTracer::Sphere sphere(Math::Point3D(0, 0, -1), 0.5);
    int width = 400;
    int height = 400;

    // camera.screen.origin = Math::Point3D(-1, -1, -1); 
    // camera.screen.bottom_side = Math::Vector3D(2, 0, 0);
    // camera.screen.left_side = Math::Vector3D(0, 2, 0);

    // std::cout << "P3\n";
    // std::cout << width << " " << height << "\n";
    // std::cout << "255\n";

    // for (int j = height - 1; j >= 0; j--) {
    //     for (int i = 0; i < width; i++) {
    //         double u = (double)i / (width - 1);
    //         double v =  (double)j / (height - 1);

    //         RayTracer::Ray ray = camera.ray(u, v);
    //         if (sphere.hits(ray))
    //             write_color(Math::Vector3D(255, 0, 0));
    //         else
    //             write_color(Math::Vector3D(0, 0, 255));
    //     }
    // }

    sf::RenderWindow window(sf::VideoMode(width, height), "Ray Tracer");

    sf::Image image;
    sf::Texture texture;
    sf::Sprite sprite;

    std::ifstream file("output.ppm");

    std::string format;
    int width_img, height_img, maxColor_img;

    file >> format >> width_img >> height_img >> maxColor_img;

    image.create(width_img, height_img);

    for (int y = 0; y < height_img; y++) {
        for (int x = 0; x < width_img; x++) {
            int r, g, b;
            file >> r >> g >> b;
            image.setPixel(x, y, sf::Color(r, g, b));
        }
    }

    texture.loadFromImage(image);
    sprite.setTexture(texture);

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
