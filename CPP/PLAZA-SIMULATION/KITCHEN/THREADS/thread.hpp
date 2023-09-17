#pragma once
#include <pthread.h>
#include <thread>
#include <iostream>
#include <functional>
#include <uuid/uuid.h>
// #include "../../CLOCK/Clock.hpp"
#include "../MUTEX/AMutex.hpp"
#include "../PIZZA/Pizza.hpp"
#include "../FRIDGE/Fridge.hpp"
// #include "../Kitchen.hpp"
class GlobalInfo
{
    public :
    GlobalInfo(){_counter = 0;}
    int _counter;
    AMutex print;
};

class ThreadArgs
{
    public :
    ThreadArgs(){ _all = new GlobalInfo;}
    GlobalInfo *_all;
    int pipefd;
    int cooksPerKitchen_;
    int timeMultiplier_;
    int ingredientReplacementTime_;
    std::vector <Pizza *> assignedCommands;
    int commandCount;
    Chrono* clock;
    void *_current;
    Fridge *fridge;
};

typedef void (*FunctionPtr)(ThreadArgs);

class Thread
{
    public :
    Thread(ThreadArgs *args);
    void *_threadFunction(ThreadArgs *args);
    void Thread_init(int cooksPerKitchens, int ingredientReplacementTime_, int timeMultiplier_, std::vector <Pizza *> _commands, Fridge *fridge, Chrono *_clock);
    void Thread_join();
    char *get_Thread_Uuid();
    ~Thread();
    std::thread _thread;
    ThreadArgs *_data;
    uuid_t _uuid;
    FunctionPtr _function;
    char _Cuuid[37];
    Chrono *_clock = new Chrono;

void assignCommand(Pizza* command) {
    // Add the command to the assigned commands list
        _data->assignedCommands.push_back(command);
    // Increment the command count
        _data->commandCount++;
    }
    int getCommandCount() const {
        return _data->commandCount;
    }
std::vector<std::string> getRequiredIngredients(PizzaType& pizzaType) {
        std::string pizzaName;

        switch (pizzaType) {
            case PizzaType::Margarita:
                pizzaName = "Margarita";
                break;
            case PizzaType::Regina:
                pizzaName = "Regina";
                break;
            case PizzaType::Americana:
                pizzaName = "Americana";
                break;
            case PizzaType::Fantasia:
                pizzaName = "Fantasia";
                break;
            default:
                break;
        }

    // Return the required ingredients based on the pizza type
        if (pizzaName == "Margarita") {
            return {"dough", "tomato", "gruyere"};
        } else if (pizzaName == "Regina") {
            return {"dough", "tomato", "gruyere", "ham", "mushrooms"};
        } else if (pizzaName == "Americana") {
            return {"dough", "tomato", "gruyere", "steak"};
        } else if (pizzaName == "Fantasia") {
            return {"dough", "tomato", "eggplant", "goat cheese", "chief love"};
        } else {
            return {};  // Empty vector for unknown pizza type
        }
    }
};