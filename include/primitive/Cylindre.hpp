/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Tue, May, 2026                                                     *
 * Title           - raytracer                                                          *
 * Description     -                                                                    *
 *     Cylindre                                                                         *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ *
 *                                                                                      *
 *       ▄▀▀█▄▄▄▄  ▄▀▀▄▀▀▀▄  ▄▀▀█▀▄    ▄▀▀▀█▀▀▄  ▄▀▀█▄▄▄▄  ▄▀▄▄▄▄   ▄▀▀▄ ▄▄             *
 *      ▐  ▄▀   ▐ █   █   █ █   █  █  █    █  ▐ ▐  ▄▀   ▐ █ █    ▌ █  █   ▄▀            *
 *        █▄▄▄▄▄  ▐  █▀▀▀▀  ▐   █  ▐  ▐   █       █▄▄▄▄▄  ▐ █      ▐  █▄▄▄█             *
 *        █    ▌     █          █        █        █    ▌    █         █   █             *
 *       ▄▀▄▄▄▄    ▄▀        ▄▀▀▀▀▀▄   ▄▀        ▄▀▄▄▄▄    ▄▀▄▄▄▄▀   ▄▀  ▄▀             *
 *       █    ▐   █         █       █ █          █    ▐   █     ▐   █   █               *
 *       ▐        ▐         ▐       ▐ ▐          ▐        ▐         ▐   ▐               *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ */

#pragma once

#include "IPrimitive.hpp"
#include "../math/Vector3d.hpp"
#include "../math/Color.hpp"
#include "../math/Ray.hpp"
#include "../math/HitInfo.hpp"

class Cylinder : public IPrimitive {

    public:
        Cylinder(const Vector3d& center, double radius,
                double height, const Color& color);

        HitInfo hits(const Ray& ray) const override;
        void applyTransform(const Transform& t) override;
        std::string getType() const override;

    private:
        HitInfo hitBody(const Ray& ray) const;
        HitInfo hitCaps(const Ray& ray) const;

        Vector3d _center;
        double _radius;
        double _height;
        Color _color;
};
