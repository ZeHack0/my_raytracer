/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Tue, May, 2026                                                     *
 * Title           - raytracer                                                          *
 * Description     -                                                                    *
 *     Cone                                                                             *
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

#include "IPrimitive.hpp"
#include "../math/Vector3d.hpp"
#include "../math/Color.hpp"
#include "../math/Ray.hpp"
#include "../math/HitInfo.hpp"

class Cone : public IPrimitive {

    public:
        Cone(const Vec3& apex, double angle, const Color& color);

        HitInfo hits(const Ray& ray) const override;
        void applyTransform(const Transform& t) override;
        std::string getType() const override;

    private:
        HitInfo hitBody(const Ray& ray) const;
        HitInfo hitCap(const Ray& ray) const;

        Vec3 _apex;
        double _angle;
        double _height;
        Color _color;
};