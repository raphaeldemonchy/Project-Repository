/*
** EPITECH PROJECT, 2023
** camera
** File description:
** camera
*/

#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>


////////////////////////////////////////////////////////////////////////////
//                                                                        //
//                           [ CAMERA ]                                //
//                                                                        //
////////////////////////////////////////////////////////////////////////////

class Camera
{
public:
    Camera(sf::RenderWindow& window, float mapPixelSizeX, float mapPixelSizeY) : _window(window), _cameraView(window.getDefaultView()), _mapPixelSizeX(mapPixelSizeX), _mapPixelSizeY(mapPixelSizeY)
    {
        // Régler la vue de la caméra sur la taille de l'ATH
        
        _cameraView.setSize(_window.getSize().x, _window.getSize().y);
        _cameraView.setCenter(_window.getSize().x, _window.getSize().y);
    }

    void update(float deltaTime)
    {
        handleInput();
        updateCamera();
    }


    void handleInput()
    {

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            moveCamera(sf::Vector2f(-10, 0));
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            moveCamera(sf::Vector2f(10, 0));
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            moveCamera(sf::Vector2f(0, -10));
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            moveCamera(sf::Vector2f(0, 10));
        }
    }


    void zoom(float mult)
    {
        // Dézoomer en ajustant le facteur de zoom
        //  if (_zoomFactor *= mult >= 0)
           
    }

    void moveCamera(const sf::Vector2f& offset)
    {
        // Déplacer la caméra en ajoutant l'offset à sa position actuelle
        sf::Vector2f newPosition = _cameraView.getCenter() + offset;
        _cameraView.setCenter(newPosition);
        _window.setView(_cameraView);
    }

    void updateCamera()
    {
        _window.setView(_cameraView);
    }


    sf::RenderWindow& _window;
    sf::View _cameraView;
    float _zoomFactor = 1;
    float _mapPixelSizeX;
    float _mapPixelSizeY;
};
