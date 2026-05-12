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

    // ── Arithmétique vecteur / vecteur ──────────────────────────

    Vector3d operator+(const Vector3d& o) const
    {
        return {x + o.x, y + o.y, z + o.z};
    }

    Vector3d operator-(const Vector3d& o) const
    {
        return {x - o.x, y - o.y, z - o.z};
    }

    Vector3d operator*(const Vector3d& o) const
    {
        return {x * o.x, y * o.y, z * o.z};
    }

    Vector3d operator-() const
    {
        return {-x, -y, -z};
    }

    // ── Arithmétique vecteur / scalaire ─────────────────────────

    Vector3d operator*(double t) const
    {
        return {x * t, y * t, z * t};
    }

    Vector3d operator/(double t) const
    {
        return {x / t, y / t, z / t};
    }

    // ── Assignation ─────────────────────────────────────────────

    Vector3d& operator+=(const Vector3d& o)
    {
        x += o.x; y += o.y; z += o.z;
        return *this;
    }

    Vector3d& operator-=(const Vector3d& o)
    {
        x -= o.x; y -= o.y; z -= o.z;
        return *this;
    }

    Vector3d& operator*=(double t)
    {
        x *= t; y *= t; z *= t;
        return *this;
    }

    // ── Produits ────────────────────────────────────────────────

    double dot(const Vector3d& o) const
    {
        return x * o.x + y * o.y + z * o.z;
    }

    Vector3d cross(const Vector3d& o) const
    {
        return {
            y * o.z - z * o.y,
            z * o.x - x * o.z,
            x * o.y - y * o.x
        };
    }

    // ── Longueur / normalisation ─────────────────────────────────

    double length() const
    {
        return std::sqrt(x*x + y*y + z*z);
    }

    double lengthSquared() const
    {
        return x*x + y*y + z*z;
    }

    Vector3d normalize() const
    {
        double len = length();
        if (len < 1e-12)
            return {0, 0, 0};
        return *this / len;
    }

    // ── Utilitaires ──────────────────────────────────────────────

    // Réflexion de ce vecteur autour d'une normale n (normalisée)
    Vector3d reflect(const Vector3d& n) const
    {
        return *this - n * (2.0 * dot(n));
    }

    // Distance entre deux points
    static double distance(const Vector3d& a, const Vector3d& b)
    {
        return (a - b).length();
    }
};

// ── Opérateur scalaire * vecteur (ordre inversé) ────────────────
inline Vector3d operator*(double t, const Vector3d& v)
{
    return v * t;
}