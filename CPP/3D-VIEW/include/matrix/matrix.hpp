/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-raytracer-raphael.de-monchy
** File description:
** matrix.hpp
*/

#pragma once
#include "../ray/ray.hpp"

namespace Math {
    class Matrix {
        Matrix();
        Matrix(Math::point3D, Math::vector3D);
        Math::point3D origin_;
        Math::vector3D direction_;
    };
}