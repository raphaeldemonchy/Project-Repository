#pragma once
#include "iMutex.hpp"

class AMutex: IMutex {
    public :
        AMutex(){}
        ~AMutex(){}
        void lock(){_mutex.lock();}
        void unlock(){_mutex.unlock();}
        void trylock(){_mutex.try_lock();}
        std::mutex _mutex;
};