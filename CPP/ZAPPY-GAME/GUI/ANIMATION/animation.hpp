/*
** EPITECH PROJECT, 2023
** anmation
** File description:
** animation
*/

#pragma once

#include <SFML/Graphics.hpp>

class Animation
{
private:
    //variables
    sf::Vector2u imageCount;
    sf::Vector2u currentImage;

    float totalTime;
    float switchTime;

    //functions


public:
    //variables
    sf::IntRect uvRect;

    //constructor && destructor
    Animation(sf::Texture *texture, sf::Vector2u imageCount, float switchTime);
    virtual ~Animation();

    void update(int row, float deltaTime);

};
