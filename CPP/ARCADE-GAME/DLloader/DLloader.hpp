/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** DLloader.hpp
*/

#pragma once
// #include "../Core/include/Core.hpp"
#include <dlfcn.h>
#include <iostream>

template <typename T>
class DLloader
{
    public :
        DLloader() {};
        ~DLloader() {};
        void openLoader(const char *src) {
            this->dynamicLib_ = dlopen(src, RTLD_LAZY);
        };
        T *getInstance() {
            typedef T* (*ptr_t)();
            ptr_t ptr = reinterpret_cast<ptr_t>(dlsym(this->dynamicLib_, "entryPoint"));
            function_ = ptr();
            return this->function_;
        };
        T* closeLoader() {
            dlclose(this->dynamicLib_);
            return nullptr;
        };

        void setFunction(void *function) {
            this->function_ = function;
        };

        T* getFunction() {
            return this->function_;
        };

        void setDynamicLib(const char *dynamic) {
            this->dynamicLib_ = dynamic;
        };

        T* getDynamicLib() {
            return this->dynamicLib_;
        };
    // protected:
        T *function_;
        void *dynamicLib_;
};