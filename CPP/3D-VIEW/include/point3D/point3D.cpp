/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-raytracer-raphael.de-monchy
** File description:
** point3D.cpp
*/

// #include "point3D.hpp"

// Math::point3D::point3D() : X(0), Y(0), Z(0)
// {}

// Math::point3D::point3D(double x, double y, double z) :  X(x), Y(y), Z(z)
// {}

// Math::point3D::point3D(const point3D &other) : X(other.X), Y(other.Y), Z(other.Z)
// {}

// Math::point3D::point3D(point3D &&other) : X(std::move(other.X)), Y(std::move(other.Y)), Z(std::move(other.Z))
// {}

// Math::point3D& Math::point3D::operator=(const point3D& other)
// {
//     this->X = other.X;
//     this->Y = other.Y;
//     this->Z = other.Z;
//     return *this;
// }

// Math::point3D& Math::point3D::operator=(const point3D&& other)
// {
//     this->X = std::move(other.X);
//     this->Y = std::move(other.Y);
//     this->Z = std::move(other.Z);
//     return *this;
// }

// Math::point3D Math::point3D::operator+(const Math::vector3D &vector)
// {
//     return Math::point3D(this->X + vector.X, this->Y + vector.Y, this->Z + vector.Z);
// }

// Math::point3D &Math::point3D::operator+(const point3D &other)
// {
//     this->X += other.X;
//     this->Y += other.Y;
//     this->Z += other.Z;
//     return *this;
// }

// Math::point3D &Math::point3D::operator+(const point3D &&other)
// {
//     this->X += std::move(other.X);
//     this->Y += std::move(other.Y);
//     this->Z += std::move(other.Z);
//     return *this;
// }

// Math::point3D &Math::point3D::operator+=(const point3D &other)
// {
//     this->X += other.X;
//     this->Y += other.Y;
//     this->Z += other.Z;
//     return *this;
// }

// Math::point3D &Math::point3D::operator+=(const point3D &&other)
// {
//     this->X += std::move(other.X);
//     this->Y += std::move(other.Y);
//     this->Z += std::move(other.Z);
//     return *this;
// }

// Math::point3D &Math::point3D::operator-(const point3D &other)
// {
//     this->X -= other.X;
//     this->Y -= other.Y;
//     this->Z -= other.Z;
//     return *this;
// }

// Math::point3D &Math::point3D::operator-(const point3D &&other)
// {
//     this->X -= std::move(other.X);
//     this->Y -= std::move(other.Y);
//     this->Z -= std::move(other.Z);
//     return *this;
// }

// Math::point3D &Math::point3D::operator-=(const point3D &other)
// {
//     this->X -= other.X;
//     this->Y -= other.Y;
//     this->Z -= other.Z;
//     return *this;
// }

// Math::point3D &Math::point3D::operator-=(const point3D &&other)
// {
//     this->X -= std::move(other.X);
//     this->Y -= std::move(other.Y);
//     this->Z -= std::move(other.Z);
//     return *this;
// }

// Math::point3D &Math::point3D::operator*(const point3D &other)
// {
//     this->X *= other.X;
//     this->Y *= other.Y;
//     this->Z *= other.Z;
//     return *this;
// }

// Math::point3D &Math::point3D::operator*(const point3D &&other)
// {
//     this->X *= std::move(other.X);
//     this->Y *= std::move(other.Y);
//     this->Z *= std::move(other.Z);
//     return *this;
// }

// Math::point3D &Math::point3D::operator*=(const point3D &other)
// {
//     this->X *= other.X;
//     this->Y *= other.Y;
//     this->Z *= other.Z;
//     return *this;
// }

// Math::point3D &Math::point3D::operator*=(const point3D &&other)
// {
//     this->X *= std::move(other.X);
//     this->Y *= std::move(other.Y);
//     this->Z *= std::move(other.Z);
//     return *this;
// }

// Math::point3D &Math::point3D::operator/(const point3D &other)
// {
//     this->X /= other.X;
//     this->Y /= other.Y;
//     this->Z /= other.Z;
//     return *this;
// }

// Math::point3D &Math::point3D::operator/(const point3D &&other)
// {
//     this->X /= std::move(other.X);
//     this->Y /= std::move(other.Y);
//     this->Z /= std::move(other.Z);
//     return *this;
// }

// Math::point3D &Math::point3D::operator/=(const point3D &other)
// {
//     this->X /= other.X;
//     this->Y /= other.Y;
//     this->Z /= other.Z;
//     return *this;
// }

// Math::point3D &Math::point3D::operator/=(const point3D &&other)
// {
//     this->X /= std::move(other.X);
//     this->Y /= std::move(other.Y);
//     this->Z /= std::move(other.Z);
//     return *this;
// }

// Math::vector3D &Math::point3D::operator-(const RayTracer::Ray ray)
// {

// }