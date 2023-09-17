/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-raytracer-raphael.de-monchy
** File description:
** rayTracer.hpp
*/

#pragma once
    #include <iostream>
    #include <string>
    #include <cmath>

#include <cmath>

namespace Math {
    class Vector3D {
    public:
        double x, y, z;

        // Default constructor
        Vector3D() : x(0), y(0), z(0) {}

        // Constructor with parameters
        Vector3D(double x, double y, double z) : x(x), y(y), z(z) {}

        // Copy constructor
        Vector3D(const Vector3D& other) = default;

        // Move constructor
        Vector3D(Vector3D&& other) noexcept = default;

        // Copy assignment operator
        Vector3D& operator=(const Vector3D& other) = default;

        // Move assignment operator
        Vector3D& operator=(Vector3D&& other) noexcept = default;

        double getVectX() { return x; }
	    double getVectY() { return y; }
	    double getVectZ() { return z; }
        // Length method
        double length() const {
            return std::sqrt(x * x + y * y + z * z);
        }

        // Arithmetic operators with Vector3D as parameter
        Vector3D operator+(const Vector3D& other) const {
            return Vector3D(x + other.x, y + other.y, z + other.z);
        }

        Vector3D& operator+=(const Vector3D& other) {
            x += other.x;
            y += other.y;
            z += other.z;
            return *this;
        }

        Vector3D operator-(const Vector3D& other) const {
            return Vector3D(x - other.x, y - other.y, z - other.z);
        }

        Vector3D& operator-=(const Vector3D& other) {
            x -= other.x;
            y -= other.y;
            z -= other.z;
            return *this;
        }

        Vector3D operator*(const Vector3D& other) const {
            return Vector3D(x * other.x, y * other.y, z * other.z);
        }

        Vector3D& operator*=(const Vector3D& other) {
            x *= other.x;
            y *= other.y;
            z *= other.z;
            return *this;
        }

        Vector3D operator/(const Vector3D& other) const {
            return Vector3D(x / other.x, y / other.y, z / other.z);
        }

        Vector3D& operator/=(const Vector3D& other) {
            x /= other.x;
            y /= other.y;
            z /= other.z;
            return *this;
        }

        // Arithmetic operators with double as parameter
        Vector3D operator*(double scalar) const {
            return Vector3D(x * scalar, y * scalar, z * scalar);
        }

        Vector3D& operator*=(double scalar) {
            x *= scalar;
            y *= scalar;
            z *= scalar;
            return *this;
        }

        Vector3D operator/(double scalar) const {
            return Vector3D(x / scalar, y / scalar, z / scalar);
        }

        Vector3D& operator/=(double scalar) {
            x /= scalar;
            y /= scalar;
            z /= scalar;
            return *this;
        }
        double mag () {
            return sqrt((x*x) + (y*y) + (z*z));
        }

        Vector3D normalize() {
            double mag = sqrt((x*x) + (y*y) + (z*z));
            return Vector3D(x/mag, y/mag, z/mag);
        }
        Vector3D neg() {
            return Vector3D (-x, -y, -z);
        }
        // Dot product method
        double dot(const Vector3D& other) const {
            return x * other.x + y * other.y + y * other.z;
        }

        Vector3D crossprod(const Vector3D &other) {
            return Vector3D (y*other.z - z * other.y, z*other.x - x * other.z, x * other.y - y * other.x);
        }

        Vector3D add (const Vector3D &other) {
            return Vector3D (x + other.x, y + other.y, z + other.z);
        }

        Vector3D mul (double s) {
            return Vector3D (x * s, y * s , z * s);
        }
    };

    class Point3D {
    public:
        double x, y, z;

        // Default constructor
        Point3D() : x(0), y(0), z(0) {}

        // Constructor with parameters
        Point3D(double x, double y, double z) : x(x), y(y), z(z) {}

        // Copy constructor
        Point3D(const Point3D& other) = default;

        // Move constructor
        Point3D(Point3D&& other) noexcept = default;

        // Copy assignment operator
        Point3D& operator=(const Point3D& other) = default;

        // Move assignment operator
        Point3D& operator=(Point3D&& other) noexcept = default;

        // Addition operator for adding a Point3D and Vector3D
        Point3D operator+(const Vector3D& vec) const {
            return Point3D(x + vec.x, y + vec.y, z + vec.z);
        }
        Vector3D operator-(const Point3D& other) const;
    };
    // Point3D Point3D::operator+(const Vector3D& vec) const {
    //     return Point3D(x + vec.x, y + vec.y, z + vec.z);
    // }
    Vector3D Point3D::operator-(const Point3D& other) const {
        return Vector3D(x - other.x, y - other.y, z - other.z);
    }
    // Vector3D Vector3D::operator-(const Vector3D& other) const {
    //     return Vector3D(x - other.x, y - other.y, z - other.z);
    // }
}