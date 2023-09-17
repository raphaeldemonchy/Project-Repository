/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-raytracer-raphael.de-monchy
** File description:
** vector3D.cpp
*/

// #include "vector3D.hpp"

// Math::vector3D::vector3D() : X(0), Y(0), Z(0)
// {};

// Math::vector3D::vector3D(double x, double y, double z) : X(x), Y(y), Z(z)
// {};

// Math::vector3D::vector3D(const vector3D &cpy) : X(cpy.X), Y(cpy.Y), Z(cpy.Z)
// {};

// Math::vector3D::vector3D(vector3D &&other) : X(std::move(other.X)), Y(std::move(other.Y)), Z(std::move(other.Z))
// {};

// double Math::vector3D::dot(const vector3D& other) const {
//     return (X * other.X) + (Y * other.Y) + (Z * other.Z);
// }

// Math::vector3D &Math::vector3D::operator=(const vector3D& other)
// {
//     this->X = other.X;
//     this->Y = other.Y;
//     this->Z = other.Z;
//     return *this;
// }

// Math::vector3D &Math::vector3D::operator=(const vector3D &&other)
// {
//     this->X = std::move(other.X);
//     this->Y = std::move(other.Y);
//     this->Z = std::move(other.Z);
//     return *this;
// }

// Math::vector3D &Math::vector3D::operator+(const vector3D &other)
// {
//     this->X += other.X;
//     this->Y += other.Y;
//     this->Z += other.Z;
//     return *this;
// }

// Math::vector3D &Math::vector3D::operator+(const vector3D &&other)
// {
//     this->X += std::move(other.X);
//     this->Y += std::move(other.Y);
//     this->Z += std::move(other.Z);
//     return *this;
// }

// Math::vector3D &Math::vector3D::operator+=(const vector3D &other)
// {
//     this->X += other.X;
//     this->Y += other.Y;
//     this->Z += other.Z;
//     return *this;
// }

// Math::vector3D &Math::vector3D::operator+=(const vector3D &&other)
// {
//     this->X += std::move(other.X);
//     this->Y += std::move(other.Y);
//     this->Z += std::move(other.Z);
//     return *this;
// }

// Math::vector3D &Math::vector3D::operator-(const vector3D &other)
// {
//     this->X -= other.X;
//     this->Y -= other.Y;
//     this->Z -= other.Z;
//     return *this;
// }

// Math::vector3D &Math::vector3D::operator-(const vector3D &&other)
// {
//     this->X -= std::move(other.X);
//     this->Y -= std::move(other.Y);
//     this->Z -= std::move(other.Z);
//     return *this;
// }

// Math::vector3D &Math::vector3D::operator-=(const vector3D &other)
// {
//     this->X -= other.X;
//     this->Y -= other.Y;
//     this->Z -= other.Z;
//     return *this;
// }

// Math::vector3D &Math::vector3D::operator-=(const vector3D &&other)
// {
//     this->X -= std::move(other.X);
//     this->Y -= std::move(other.Y);
//     this->Z -= std::move(other.Z);
//     return *this;
// }

// Math::vector3D &Math::vector3D::operator*(const vector3D &other)
// {
//     this->X *= other.X;
//     this->Y *= other.Y;
//     this->Z *= other.Z;
//     return *this;
// }

// Math::vector3D &Math::vector3D::operator*(const vector3D &&other)
// {
//     this->X *= std::move(other.X);
//     this->Y *= std::move(other.Y);
//     this->Z *= std::move(other.Z);
//     return *this;
// }

// Math::vector3D &Math::vector3D::operator*=(const vector3D &other)
// {
//     this->X *= other.X;
//     this->Y *= other.Y;
//     this->Z *= other.Z;
//     return *this;
// }

// Math::vector3D &Math::vector3D::operator*=(const vector3D &&other)
// {
//     this->X *= std::move(other.X);
//     this->Y *= std::move(other.Y);
//     this->Z *= std::move(other.Z);
//     return *this;
// }

// Math::vector3D &Math::vector3D::operator/(const vector3D &other)
// {
//     this->X /= other.X;
//     this->Y /= other.Y;
//     this->Z /= other.Z;
//     return *this;
// }

// Math::vector3D &Math::vector3D::operator/(const vector3D &&other)
// {
//     this->X /= std::move(other.X);
//     this->Y /= std::move(other.Y);
//     this->Z /= std::move(other.Z);
//     return *this;
// }

// Math::vector3D &Math::vector3D::operator/=(const vector3D &other)
// {
//     this->X /= other.X;
//     this->Y /= other.Y;
//     this->Z /= other.Z;
//     return *this;
// }

// Math::vector3D &Math::vector3D::operator/=(const vector3D &&other)
// {
//     this->X /= std::move(other.X);
//     this->Y /= std::move(other.Y);
//     this->Z /= std::move(other.Z);
//     return *this;
// }

// double Math::vector3D::lenght() const
// {
//     return std::sqrt(X*X + Y*Y + Z*Z);
// }