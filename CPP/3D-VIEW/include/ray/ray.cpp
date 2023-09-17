/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-raytracer-raphael.de-monchy
** File description:
** ray.cpp
*/

// #include "ray.hpp"

// RayTracer::Ray::Ray() : origin_(0, 0, 0), direction_(0, 0, 0)
// {}

// RayTracer::Ray::Ray(const Math::point3D &point, const Math::vector3D &vec) : origin_(point), direction_(vec)
// {}

// RayTracer::Ray::Ray(const RayTracer::Ray &other) : origin_(other.origin_), direction_(other.direction_)
// {}

// RayTracer::Ray::Ray(const RayTracer::Ray &&other) : origin_(std::move(other.origin_)), direction_(std::move(other.direction_))
// {}

// RayTracer::Ray &RayTracer::Ray::operator=(const RayTracer::Ray &other)
// {
//     this->origin_ = other.origin_;
//     this->direction_ = other.direction_;
//     return *this;
// }

// RayTracer::Ray &RayTracer::Ray::operator=(const RayTracer::Ray &&other)
// {
//     this->origin_ = std::move(other.origin_);
//     this->direction_ = std::move(other.direction_);
//     return *this;
// }

// Math::point3D RayTracer::Ray::getOrigin() const
// {
//     return this->origin_;
// }

// Math::vector3D RayTracer::Ray::getDirection() const
// {
//     return this->direction_;
// }