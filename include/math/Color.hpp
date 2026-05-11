/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Fri, May, 2026                                                     *
 * Title           - raytracer                                                          *
 * Description     -                                                                    *
 *     Color                                                                            *
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

#include <algorithm>

struct Color {
    int r = 0;
    int g = 0;
    int b = 0;

    Color operator+(const Color& o) const
    {
        return {r + o.r, g + o.g, b + o.b};
    }

    Color operator*(double t) const
    {
        return {
            static_cast<int>(r * t),
            static_cast<int>(g * t),
            static_cast<int>(b * t)
        };
    }

    Color operator*(const Color& o) const
    {
        return {
            static_cast<int>(r * o.r / 255.0),
            static_cast<int>(g * o.g / 255.0),
            static_cast<int>(b * o.b / 255.0)
        };
    }

    Color clamp() const
    {
        return {
            std::clamp(r, 0, 255),
            std::clamp(g, 0, 255),
            std::clamp(b, 0, 255)
        };
    }

    static Color black() { return {0,   0,   0  }; }
    static Color white() { return {255, 255, 255}; }
};