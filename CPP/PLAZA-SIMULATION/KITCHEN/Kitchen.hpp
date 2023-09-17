#pragma once
#include <vector>
#include <iostream>
#include <unistd.h>
#include "PIZZA/Pizza.hpp"
#include "THREADS/thread.hpp"
#include "MUTEX/AMutex.hpp"
#include <sys/wait.h>
// #include "../CLOCK/Clock.hpp"
#include "FRIDGE/Fridge.hpp"

class Kitchen {
    public :
        Kitchen() {}
        ~Kitchen(){}
        void newKitchen(int _nrOfProducers,int ingredientReplacementTime_, int timeMultiplier_);
        void destroyKitchen();
        float getActiveTime(){return _clock->_elapsedTime;}
        Fridge *fridge;
        std::vector<Thread *> _Producters;
        std::vector<Pizza*> _commands;
        Chrono *_clock = new Chrono();
        pid_t _pid;
        int _pipefd[2];
        int getWriteFd() const;

        // zmq::context_t* _context;
        // zmq::socket_t* _receptionSocket;

        // void receiveCommandFromReception();

};