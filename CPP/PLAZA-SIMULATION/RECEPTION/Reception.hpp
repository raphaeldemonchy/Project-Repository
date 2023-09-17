#pragma once
#include <iostream>
#include "../KITCHEN/PIZZA/Pizza.hpp"
#include "../KITCHEN/Kitchen.hpp"
#include <string>
#include <vector>
#include <regex>
#include <sstream>
#include <cctype>
#include <pthread.h>
#include <sys/wait.h>

#include <zmq.hpp>

// ETAT CUISINE
struct KitchenStatus
{
    int numberOfCooks;
};

class Reception
{
    public:
        Reception();
        ~Reception();
        void start(Reception *_reception);
        void Parsing_arg(int ac, char **av);
        void cmdParser(const std::string &cmd);
        void createCommandes(std::vector <std::string> cmd);
        void processPizzaOrder(const std::string& order, Reception *_reception);

        int timeMultiplier_;
        int cooksPerKitchen_;
        int ingredientReplacementTime_;
        std::vector<Pizza *> _Commandes;
        std::vector<Kitchen *> _kitchens;
        pid_t _pid;

    private:
};