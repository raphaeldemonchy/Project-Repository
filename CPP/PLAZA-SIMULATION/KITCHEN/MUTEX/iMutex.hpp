#pragma once
#include <mutex>
#include <cstdlib>
#include <new>

class IMutex {
    public :
        virtual ~IMutex () = default;
        virtual void lock () = 0;
        virtual void unlock () = 0;
        virtual void trylock () = 0;
};