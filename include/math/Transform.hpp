/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Fri, May, 2026                                                     *
 * Title           - raytracer                                                          *
 * Description     -                                                                    *
 *     Transform                                                                        *
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

#include "Vector3d.hpp"

class Transform {
public:
    Transform();

    Transform& translate(const Vector3d& t);
    Transform& rotate(const Vector3d& angles);
    Transform& scale(double factor);

    Vector3d apply(const Vector3d& v) const;
    double getUniformScale() const;
    Vector3d getTranslation() const;

private:
    double _mat[4][4];

    void _identity();
    void _multiply(const double other[4][4]);
};