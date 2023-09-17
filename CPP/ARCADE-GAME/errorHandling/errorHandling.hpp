/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-raphael.de-monchy
** File description:
** errorhabdling.hpp
*/

#include <iostream>
#pragma once

class Error: public std::exception
{
    public:
        Error(const std::string& msg) : _msg(msg) {};
        const char* what() const noexcept override {
            return _msg.c_str();
        };
        static void err_(std::string msg)
        {
            try {
                throw Error(msg);
            } catch (Error &err) {
                std::cout << "Error: " << err.what() << std::endl;
                exit (84);
            }
        };
    private:
        std::string _msg;
};