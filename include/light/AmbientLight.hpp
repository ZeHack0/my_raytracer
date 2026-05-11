/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Tue, May, 2026                                                     *
 * Title           - raytracer                                                          *
 * Description     -                                                                    *
 *     AmbientLight                                                                     *
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

#include "ILight.hpp"

class AmbientLight : public ILight {

    public:
        explicit AmbientLight(double intensity,
                            const Color& color = {255, 255, 255});
        Color  illuminate(const Vector3d& point,
                        const Vector3d& normal) const override;
        bool   inShadow(const Vector3d& point,
                        const Scene& scene)  const override;
        Color  getColor() const override;
        double getIntensity() const override;

    private:
        double _intensity;
        Color _color;
};
