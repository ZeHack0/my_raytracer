/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Tue, May, 2026                                                     *
 * Title           - raytracer                                                          *
 * Description     -                                                                    *
 *     ILight                                                                           *
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

#pragma once

#include "../math/Vector3d.hpp"
#include "../math/Color.hpp"

class Scene;

class ILight {
    public:
        virtual ~ILight() = default;
        virtual Color illuminate(const Vector3d& point,
                                const Vector3d& normal) const = 0;
        virtual bool inShadow(const Vector3d& point,
                            const Scene& scene) const = 0;
        virtual Color getColor() const = 0;
        virtual double getIntensity() const = 0;
};
