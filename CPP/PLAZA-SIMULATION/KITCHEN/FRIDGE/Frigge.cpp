#include "Fridge.hpp"

Fridge::Fridge() {
        // Initialize the stock with 5 units of each ingredient
    stock_["dough"] = 5;
    stock_["tomato"] = 5;
    stock_["gruyere"] = 5;
    stock_["ham"] = 5;
    stock_["mushrooms"] = 5;
    stock_["steak"] = 5;
    stock_["eggplant"] = 5;
    stock_["goat cheese"] = 5;
    stock_["chief love"] = 5;
}

void Fridge::regenerateStock(int ingredientReplacementTime_) {
    int count = 0;
    int i = 0;
    _clock->start();
    if (_clock->_elapsedTime >= ingredientReplacementTime_ / 1000) {
        for (auto& ingredient : stock_) {
            if (ingredient.second < 5) {
                ingredient.second += 1;
            }
        }
        _clock->_startTime = _clock->_curentTime;
        // if (i == 0)
        //     std::cout << "refill in " << ingredientReplacementTime_ / 1000 << " sec!" << std::endl, i++;
    }
}

bool Fridge::hasEnoughIngredients(const std::vector<std::string>& ingredients) {
    for (const auto& ingredient : ingredients) {
        if (stock_[ingredient] < 1) {
            return false;
        }
    }
    return true;
}

void Fridge::consumeIngredients(const std::vector<std::string>& ingredients) {
    if (hasEnoughIngredients(ingredients) == true) {
        for (const auto& ingredient : ingredients) {
            stock_[ingredient] -= 1;
        }
    }
}