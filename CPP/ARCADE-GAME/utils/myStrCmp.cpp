/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** myStrCmp.cpp
*/

#include "utils.hpp"

int myStrCmp(const std::string src1, const std::string src2)
{
    for (int i = 0; src1[i] != '\0'; i += 1)
        if (src1[i] != src2[i])
            return -1;
    return 0;
}