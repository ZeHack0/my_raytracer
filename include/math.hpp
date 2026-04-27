/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Wed, Apr, 2026                                                     *
 * Title           - bootstrap                                                          *
 * Description     -                                                                    *
 *     math                                                                             *
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

namespace Math {

    class Vector3D {
        
        public:
            Vector3D() : X(0), Y(0), Z(0) {}
            Vector3D(double x, double y, double z) : X(x), Y(y), Z(z) {}
            ~Vector3D() = default;

            double X;
            double Y;
            double Z;

            double length() const {
                return sqrt(X * X + Y * Y + Z * Z);
            }

            double dot(const Vector3D& other) const {
                return (X * other.X) + (Y * other.Y) + (Z * other.Z);
            }

            Vector3D operator+(const Vector3D& other) const  {
                return Vector3D(X + other.X, Y + other.Y, Z + other.Z);
            }

            Vector3D operator+=(const Vector3D& other) {
                X += other.X;
                Y += other.Y;
                Z += other.Z;

                return *this;
            }

            Vector3D operator-(const Vector3D& other) const {
                return Vector3D(X - other.X, Y - other.Y, Z - other.Z);
            }

            Vector3D operator-=(const Vector3D& other) {
                X -= other.X;
                Y -= other.Y;
                Z -= other.Z;
                
                return *this;
            }

            Vector3D operator*(const Vector3D& other) const {
                return Vector3D(X * other.X, Y * other.Y, Z * other.Z);
            }

            Vector3D operator*=(const Vector3D& other) {
                X *= other.X;
                Y *= other.Y;
                Z *= other.Z;
                
                return *this;
            }

            Vector3D operator/(const Vector3D& other) const {
                return Vector3D(X / other.X, Y / other.Y, Z / other.Z);
            }

            Vector3D operator/=(const Vector3D& other) {
                X /= other.X;
                Y /= other.Y;
                Z /= other.Z;
                
                return *this;
            }
            
            double operator_less() const {
                return X - X;
            }

            Vector3D double_mul_operator(double other) const {
                return Vector3D(X * other, Y * other, Z * other);
            }

            Vector3D double_mul_equal_operator(double other) {
                X *= other;
                Y *= other;
                Z *= other;
                
                return *this;
            }

            Vector3D double_div_operator(double other) const {
                return Vector3D(X / other, Y / other, Z / other);
            }

            Vector3D double_div_equal_operator(double other) {
                X /= other;
                Y /= other;
                Z /= other;
                
                return *this;
            }
    };

    class Point3D {

        public:
            Point3D() : X(0), Y(0), Z(0) {}
            Point3D(double x, double y, double z): X(x), Y(y), Z(z) {}
            ~Point3D() = default;

            double X;
            double Y;
            double Z;

            Point3D operator+(const Vector3D& v) const {
                return Point3D(X + v.X, Y + v.Y, Z + v.Z);
            }
    };

}