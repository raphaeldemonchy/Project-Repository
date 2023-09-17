/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-raytracer-raphael.de-monchy
** File description:
** matrix.cpp
*/

#include "matrix.hpp"

Math::Matrix::Matrix() : origin_(), direction_()
{}

Math::Matrix::Matrix(Math::point3D origin, Math::vector3D direction) : origin_(origin), direction_(direction)
{}

