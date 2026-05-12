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

#include "primitive/Sphere.hpp"
#include <cmath>

namespace RayTracer {

    Sphere::Sphere(const Vector3d& center, double radius, const Color& color)
        : _center(center), _radius(radius), _color(color)
    {}

    HitInfo Sphere::hits(const Ray& ray) const
    {
        HitInfo info;

        Vector3d oc = ray._origin - _center;

        double a = ray._direction.lengthSquared();
        double b = 2.0 * oc.dot(ray._direction);
        double c = oc.lengthSquared() - _radius * _radius;

        double discriminant = b * b - 4 * a * c;

        if (discriminant < 0)
            return info;

        double sqrtD = std::sqrt(discriminant);

        double t = (-b - sqrtD) / (2.0 * a);

        if (t < 1e-4 || t > ray.tMax) {
            t = (-b + sqrtD) / (2.0 * a);
            if (t < 1e-4 || t > ray.tMax)
                return info;
        }

        info.hit    = true;
        info.t      = t;
        info.point  = ray.at(t);
        info.normal = (info.point - _center).normalize();
        info.color  = _color;

        if (info.normal.dot(ray._direction) > 0)
            info.normal = -info.normal;

        return info;
    }

    void Sphere::applyTransform(const Transform& t)
    {
        _center = t.apply(_center);
        _radius *= t.getUniformScale();
    }

    std::string Sphere::getType() const
    {
        return "sphere";
    }
}