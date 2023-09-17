#pragma once

enum PizzaType
{
    Regina = 1 ,
    Margarita = 2 ,
    Americana = 4 ,
    Fantasia = 8
};
enum PizzaSize
{
    S = 1 ,
    M = 2 ,
    L = 4 ,
    XL = 8 ,
    XXL = 16
};

class Pizza
{
public:
    Pizza(){};
    ~Pizza(){};
    PizzaType _pizzaType;
    PizzaSize _pizzaSize;
    int _time;
};

struct PizzaSerialized {
    PizzaType _pizzaType;
    PizzaSize _pizzaSize;
    int _time;
};
