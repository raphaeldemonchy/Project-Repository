/*
** EPITECH PROJECT, 2022
** PLAZZA
** File description:
** thread.cpp
*/
#include "thread.hpp"

Thread::Thread(ThreadArgs *args) {_data = args;}

void Thread::Thread_init(int cooksPerKitchens, int ingredientReplacementTime_, int timeMultiplier_, std::vector <Pizza *> _commands, Fridge *fridge, Chrono *_clock)
{
    _data->cooksPerKitchen_ = cooksPerKitchens;
    _data->timeMultiplier_ = timeMultiplier_;
    _data->ingredientReplacementTime_ = ingredientReplacementTime_;
    _data->assignedCommands = _commands;
    _data->fridge = fridge;
    _data->clock = _clock;
    std::thread t_init(std::bind(&Thread::_threadFunction, this, _data));
    _thread = std::move(t_init);
    uuid_generate(_uuid);
    uuid_unparse(_uuid, _Cuuid);
}

void Thread::Thread_join()
{
    if (_thread.joinable())
        _thread.join();
}
Thread::~Thread(){}

void *Thread::_threadFunction(ThreadArgs *args)
{
    for (Pizza* command : args->assignedCommands) {
        // Retrieve the required ingredients for the pizza
        std::vector<std::string> requiredIngredients = getRequiredIngredients(command->_pizzaType);

        // Check if there are enough ingredients in the fridge
        bool hasEnoughIngredients = true;
        for (const std::string& ingredient : requiredIngredients) {
            if (args->fridge->getIngredientStock(ingredient) < 1) {
                hasEnoughIngredients = false;
                break;
            }
        }

        // If there are enough ingredients, cook the pizza
        if (hasEnoughIngredients) {
            // Deduct the ingredients from the fridge
            for (const std::string& ingredient : requiredIngredients) {
                args->fridge->deductIngredient(ingredient, 1);
            }
        }
        _clock->start();
        int clocktime = command->_time * args->timeMultiplier_;
        if (_clock->_elapsedTime >= clocktime) {
            std::cout << "preparation terminée" << std::endl;
        }
        _clock->_startTime = _clock->_curentTime;
    }
    return NULL;
}