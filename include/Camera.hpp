/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Fri, May, 2026                                                     *
 * Title           - raytracer                                                          *
 * Description     -                                                                    *
 *     Camera                                                                           *
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

#pragma once
#include "math/Vector3d.hpp"
#include "math/Ray.hpp"
#include <cmath>

class Camera {
public:
    Vector3d position;
    Vector3d rotation;
    double fov = 72.0;
    int width = 1920;
    int height = 1080;

    Ray generateRay(int x, int y) const
    {
        double aspectRatio = (double)width / height;
        double scale       = std::tan(fov * 0.5 * M_PI / 180.0);

        double u = (2.0 * (x + 0.5) / width  - 1.0)
                   * aspectRatio * scale;
        double v = (1.0 - 2.0 * (y + 0.5) / height) * scale;

        Vector3d dir = Vector3d{u, v, -1.0}.normalize();

        return Ray{position, dir};
    }
};