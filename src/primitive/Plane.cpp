/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Sat, May, 2026                                                     *
 * Title           - raytracer                                                          *
 * Description     -                                                                    *
 *     Plane                                                                            *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ *
 *                                                                                      *
 *       _|_|_|_|  _|_|_|    _|_|_|  _|_|_|_|_|  _|_|_|_|    _|_|_|  _|    _|           *
 *       _|        _|    _|    _|        _|      _|        _|        _|    _|           *
 *       _|_|_|    _|_|_|      _|        _|      _|_|_|    _|        _|_|_|_|           *
 *       _|        _|          _|        _|      _|        _|        _|    _|           *
 *       _|_|_|_|  _|        _|_|_|      _|      _|_|_|_|    _|_|_|  _|    _|           *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ */

#include "primitive/Plane.hpp"

namespace RayTracer {

    Plane::Plane(char axis, double position, const Color& color) : _axis(axis), _position(position), _color(color)
    {}

    HitInfo Plane::hits(const Ray& ray) const
    {
        HitInfo info;

        double denom = 0;
        double t = 0;

        switch (_axis) {
            case 'x':
                denom = ray._direction.x;
                if (std::abs(denom) < 1e-6)
                    return info;
                t = (_position - ray._origin.x) / denom;
                break;
            case 'y':
                denom = ray._direction.y;
                if (std::abs(denom) < 1e-6)
                    return info;
                t = (_position - ray._origin.y) / denom;
                break;
            case 'z':
                denom = ray._direction.z;
                if (std::abs(denom) < 1e-6)
                    return info;
                t = (_position - ray._origin.z) / denom;
                break;
            default:
                return info;
        }

        if (t < 1e-4 || t > ray.tMax)
            return info;

        info.hit = true;
        info.t = t;
        info.point = ray.at(t);

        switch (_axis) {
            case 'x': info.normal = Vector3d{(denom > 0) ? -1.0 : 1.0, 0.0, 0.0};
                break;
            case 'y': info.normal = Vector3d{0.0, (denom > 0) ? -1.0 : 1.0, 0.0};
                break;
            case 'z': info.normal = Vector3d{0.0, 0.0, (denom > 0) ? -1.0 : 1.0};
                break;
        }

        info.color = _color;

        return info;
    }

    void Plane::applyTransform(const Transform& t)
    {
        _position += t.getTranslation().y;
    }

    std::string Plane::getType() const
    {
        return "Plane";
    }
}
