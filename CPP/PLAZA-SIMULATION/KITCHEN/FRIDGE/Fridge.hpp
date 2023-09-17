#pragma once
#include "../../CLOCK/Clock.hpp"
#include <vector>
#include <iostream>
#include <unistd.h>
#include <unordered_map>
#include <string>
class Fridge {
public:

    Fridge();
    void regenerateStock(int ingredientReplacementTime_);
    bool hasEnoughIngredients(const std::vector<std::string>& ingredients);
    void consumeIngredients(const std::vector<std::string>& ingredients);

    std::unordered_map<std::string, int> stock_;
    Chrono *_clock = new Chrono;
    int getIngredientStock(const std::string& ingredient) const {
        auto it = stock_.find(ingredient);
        if (it != stock_.end()) {
            return it->second;
        } else {
            return 0;
        }
    }
    void deductIngredient(const std::string& ingredient, int quantity) {
        auto it = stock_.find(ingredient);
        if (it != stock_.end()) {
            it->second -= quantity;
            if (it->second < 0) {
                it->second = 0;
            }
        }
    }
};