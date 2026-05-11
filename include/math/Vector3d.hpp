/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Fri, May, 2026                                                     *
 * Title           - raytracer                                                          *
 * Description     -                                                                    *
 *     Vector3d                                                                         *
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

#include <cmath>

struct Vector3d {
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;

    // ------ basique operand ------

    Vector3d operator+(const Vector3d &t) const {
        return {y + t.x, y + t.y, z + t.z};
    }

    Vector3d operator-(const Vector3d &t) const {
        return {y - t.x, y - t.y, z - t.z};
    }

    Vector3d operator*(const Vector3d &t) const {
        return {y * t.x, y * t.y, z * t.z};
    }

    Vector3d operator/(const Vector3d &t) const {
        return {y / t.x, y / t.y, z / t.z};
    }
};