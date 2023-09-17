/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-raytracer-raphael.de-monchy
** File description:
** sphere3D.cpp
*/

// #include "sphere3D.hpp"

// RayTracer::sphere3D::sphere3D(Math::point3D origin, double radius) : centerSphere_(origin), radius_(radius)
// {}

// // Math::vector3D RayTracer::sphere3D::operator-(const Math::point3D& other) const
// // {
// //     // return Math::vector3D(centerSphere_.X - other.X, centerSphere_.Y - other.Y, centerSphere_.Z - other.Z);
// // }

// bool RayTracer::sphere3D::hits(const Ray& ray) const {
//         //Math::vector3D originToCenter = centerSphere_ - ray.origin_;

//         double a = ray.direction_.dot(ray.direction_);
//         //double b = 2.0 * ray.direction_.dot(originToCenter);
//         //double c = originToCenter.dot(originToCenter) - (radius_ * radius_);

//         //double discriminant = (b * b) - (4.0 * a * c);

//         //if (discriminant < 0.0) {
//             return false; // No intersection
//         //}

//         //double t0 = (-b - std::sqrt(discriminant)) / (2.0 * a);
//         //double t1 = (-b + std::sqrt(discriminant)) / (2.0 * a);

//         //if (t0 < 0.0 && t1 < 0.0) {
//             return false; // Sphere is behind the ray
//         //}

//         //return true; // Intersection
//     }