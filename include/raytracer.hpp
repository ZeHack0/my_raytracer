/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Wed, Apr, 2026                                                     *
 * Title           - bootstrap                                                          *
 * Description     -                                                                    *
 *     raytracer                                                                        *
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

#include "math.hpp"
#include <stdio.h>

namespace RayTracer {

    class Ray {

        public:
            Ray() = default;
            Ray(const Math::Point3D& origin, const Math::Vector3D& direction) : direction(direction), origin(origin) {}

            Math::Vector3D direction;
            Math::Point3D origin;
    };

    class Sphere {

        public:
            Sphere() = default;
            Sphere(const Math::Point3D center, double radius) : center(center), radius(radius) {}
            ~Sphere() = default;

            Math::Point3D center;
            double radius;
            bool hits(Ray ray) {
                Math::Vector3D origine;

                origine.X = ray.origin.X - center.X;
                origine.Y = ray.origin.Y - center.Y;
                origine.Z = ray.origin.Z - center.Z;
                
                double a = ray.direction.dot(ray.direction);
                double b = 2.0 * origine.dot(ray.direction);
                double c = origine.dot(origine) - radius * radius;

                double discriminant = b * b - 4 * a * c;
                return discriminant >= 0;
            }
    };
    
    class Rectangle3D {

        public:
            Rectangle3D() = default;
            ~Rectangle3D() = default;

            Math::Point3D origin;
            Math::Vector3D bottom_side;
            Math::Vector3D left_side;

            Math::Point3D pointAt(double u, double v) const {
                return origin + (bottom_side.double_mul_operator(u)) + (left_side.double_mul_operator(v));
            }
    };

    class Camera {

        public:
            Camera() : origin(0, 0, 0) {}
            ~Camera() = default;

            Math::Point3D origin;
            Rectangle3D screen;

            Ray ray(double u, double v) const {
                Math::Point3D screenPoint = screen.pointAt(u, v);

                Math::Vector3D direction = Math::Vector3D(screenPoint.X - origin.X, screenPoint.Y - origin.Y, screenPoint.Z - origin.Z);
                return Ray(origin, direction);
            }
    };

}
