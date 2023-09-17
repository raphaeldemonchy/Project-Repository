/*
** EPITECH PROJECT, 2023
** graphical
** File description:
** graphical
*/

#include "graphical.hpp"

////////////////////////////////////////////////////////////////////////////
//                                                                        //
//                           [ GRAPHICAL ]                                //
//                                                                        //
////////////////////////////////////////////////////////////////////////////

Graphical::Graphical(int P, std::string adresse)
{
    std::cout << "je rentre dans graphical" << std::endl;
    if (!_TcameraContour.loadFromFile("GRAPHICAL/assets/cameraContour.png")) {
        std::cerr << "Erreur lors du chargement d'image" << std::endl;
    }
    _ScameraContour.setTexture(_TcameraContour);
    _ScameraContour.setScale(scale_contour_x, scale_contour_y);

    // if (!_crosshairTexture.loadFromFile("GRAPHICAL/assets/cross.png")) {
    //     std::cerr << "Erreur lors du chargement d'image" << std::endl;
    // }
    // _crosshairSprite.setTexture(_crosshairTexture);

    // _crossCentre = _crosshairTexture.getSize();
    // _crosshairSprite.setOrigin(_crossCentre.x / 2.f, _crossCentre.y / 2.f);
    // _midleCameraVision = _window.getSize();

    _Ath = new ATH();
    _map = new(Map);



}

Graphical::~Graphical()
{

}

bool Graphical::crossHairContact(const sf::RectangleShape& rect1, const sf::RectangleShape& rect2)
{
    sf::FloatRect rect1Bounds = rect1.getGlobalBounds();
    sf::FloatRect rect2Bounds = rect2.getGlobalBounds();
    return rect1Bounds.intersects(rect2Bounds);
}



void Graphical::handleRightClick()
{
    if (_event.type == sf::Event::MouseButtonReleased && _event.mouseButton.button == sf::Mouse::Right) {
   
        std::cout << "Clic droit détecté à la position : " << _event.mouseButton.x << ", " << _event.mouseButton.y << std::endl;
        _window.clear();
    }
}

std::string Graphical::countPlayer(int x, int y)
{
    int counter = 0;

    for (int a = 0; _listPlayer.size() != a; a++) {
        if (_listPlayer[a]->_xPlayer == x && _listPlayer[a]->_yPlayer == y) {
            a++;
        }
    }

    return std::to_string(counter);
}


void Graphical::handleClickManagment()
{
    if (_event.type == sf::Event::MouseButtonPressed) {
        if (_event.mouseButton.button == sf::Mouse::Left) {
            if (_listPlayer.size() > 0) {
                for (int a = 0; a != _listPlayer.size(); a++) {
                    std::cout << "PLAYER POS : x = " <<_listPlayer[a]->_xPlayer<<" y = "<<_listPlayer[a]->_yPlayer << std::endl;
                    std::cout << "PLAYER POS : x =" << _listPlayer[a]->_hitBoxPlayer.getPosition().x << " y = " << _listPlayer[a]->_hitBoxPlayer.getPosition().y << std::endl;

                    if (crossHairContact(_listPlayer[a]->_hitBoxPlayer, _map->_crossHitBox)) {
                        std::cout << "my crossHair are on hitBox Player" << std::endl;
                        _FluxClient->sendMessage("pin " + _listPlayer[a]->_uuidPlayer + "\n");
                        _FluxClient->sendMessage("plv " + _listPlayer[a]->_uuidPlayer + "\n");
                        // _FluxClient->sendMessage("ppo " + _listPlayer[a]->_uuidPlayer + "\n");

                        _Ath->refreshInventory("Player", _listPlayer[a]->_uuidPlayer, _listPlayer[a]->_teamName,
                                            _listPlayer[a]->level, _listPlayer[a]->_xPlayer, _listPlayer[a]->_yPlayer,
                                            _listPlayer[a]->inventory->FOOD, _listPlayer[a]->inventory->LINEMATE, _listPlayer[a]->inventory->DERAUMERE,
                                            _listPlayer[a]->inventory->SIBURE, _listPlayer[a]->inventory->MENDIANE, _listPlayer[a]->inventory->PHIRAS,
                                            _listPlayer[a]->inventory->THYSTAM);
                        
                    }
                }
            }

            for (int a = 0; a != _map->_mapElement.size(); a++) {

                if (crossHairContact(_map->_mapElement[a]->_hitBoxILE, _map->_crossHitBox)) {
                    _FluxClient->sendMessage("bct " + std::to_string(_map->_mapElement[a]->_xposTuile) + " " + std::to_string(_map->_mapElement[a]->_yposTuile) + "\n");
                    std::cout << "my crossHair are on hitBox ILE" << std::endl;
                     _Ath->refreshInventory("Ile", countPlayer(_map->_mapElement[a]->_xposTuile,_map->_mapElement[a]->_yposTuile),
                                        std::to_string(_map->_mapElement[a]->_nbEGGS),
                                        0, _map->_mapElement[a]->_xposTuile, _map->_mapElement[a]->_yposTuile,
                                        _map->_mapElement[a]->_items->FOOD, _map->_mapElement[a]->_items->LINEMATE, _map->_mapElement[a]->_items->DERAUMERE,
                                        _map->_mapElement[a]->_items->SIBURE, _map->_mapElement[a]->_items->MENDIANE, _map->_mapElement[a]->_items->PHIRAS,
                                        _map->_mapElement[a]->_items->THYSTAM);
                        
                    }
                }
        }
    }
}



void Graphical::runGraphical()
{
    sf::VideoMode videoMode(1920, 1080);
    std::cout << "je run mon graphique" << std::endl;
    _window.create(videoMode, "Zappy");

    initBackground();
    float mapPixelSizeX = _map->_xSizeMap * 200;
    float mapPixelSizeY = _map->_ySizeMap * 200;
    Camera camera(_window, mapPixelSizeX, mapPixelSizeY);
    // _map->afficherElements();
    while (_window.isOpen()) {

        int verif = 0;

        _window.clear();

        camera._zoomFactor = 1;
        while (_window.pollEvent(_event))
        {
            if (_event.type == sf::Event::Closed) {
                _window.close();

            } else if (_event.type == sf::Event::MouseWheelScrolled) {
                verif = 1;
                if (_event.mouseWheelScroll.delta > 0) {
                    camera._zoomFactor *= 1.1,  scale_contour_x *= 1.1, scale_contour_y *= 1.1,
                    _map->_crossScaleX *= 1.1, _map->_crossScaleY *= 1.1, centercoeff *= 1.1;
                    _window.clear();

                } else if (_event.mouseWheelScroll.delta < 0) {
                    camera._zoomFactor *= 0.9,  scale_contour_x *= 0.9, scale_contour_y*= 0.9,
                    _map->_crossScaleX *= 0.9, _map->_crossScaleY *= 0.9, centercoeff *= 0.9;
                    _window.clear();

                }
            } if (_event.type == sf::Event::KeyPressed) {
                if (_event.key.code == sf::Keyboard::Z) {
                    _map->_Scross.move(0, -15);

                }
                else if (_event.key.code == sf::Keyboard::Q)
                {
                    _map->_Scross.move(-15, 0);

                }
                else if (_event.key.code == sf::Keyboard::S)
                {
                    _map->_Scross.move(0, 15);

                }
                else if (_event.key.code == sf::Keyboard::D)
                {
                    _map->_Scross.move(15, 0);

                }
            }
            handleClickManagment();
            handleRightClick();
        }
 

        sf::Vector2f posCrossOnMap = _map->_Scross.getPosition();
        _window.clear();
        
        //      CROSSHAIRE      //

        sf::Color fillColor(0, 0, 0, 0);
        _map->_crossHitBox.setFillColor(fillColor);
                
        _map->_crossHitBox.setOutlineColor(sf::Color::Red);
        _map->_crossHitBox.setOutlineThickness(2);
        _map->_crossHitBox.setOrigin(-20, -20);
        _map->_crossHitBox.setPosition(_map->_Scross.getPosition().x, _map->_Scross.getPosition().y);
        _map->_crossHitBox.setScale(_map->_crossScaleX, _map->_crossScaleY);
        sf::Vector2f newSize(10.0f, 10.0f);
        _map->_crossHitBox.setSize(newSize);
        _map->_Scross.setScale(_map->_crossScaleX, _map->_crossScaleY + 0.1);
        
        //      CAMERA      //
        _cameraView.setCenter(posCrossOnMap.x + (160 * centercoeff) , posCrossOnMap.y + (40 * centercoeff));
        _deltaTime = _clock.restart().asSeconds();
        camera.update(_deltaTime);

        updateMyAnimation(_deltaTime);

        _ScameraContour.setScale(scale_contour_x, scale_contour_y);

        //      ATH     //
        _Ath->updateScale(scale_contour_x, scale_contour_y);

        _window.setView(_cameraView);
        if (verif == 1) {
            _cameraView.zoom(camera._zoomFactor);
            _window.setView(_cameraView);
        }
       
        _window.clear();
        
        displayBackground();
        displayMap();
        _window.draw(_map->_Scross);        // + //
        displayPlayer();

        //// ELEMENT IMMOBILE //

        _ScameraContour.setOrigin(1920 / 2, 1080 / 2);
        _ScameraContour.setPosition(posCrossOnMap.x + (160 * centercoeff), posCrossOnMap.y + (40 * centercoeff));

        _Ath->updatePos(posCrossOnMap.x, posCrossOnMap.y, centercoeff);
      
            

        /////////////////DÉBUG///////
        // _window.draw(_map->_crossHitBox);
        /////////////////////////////
        _window.draw(_ScameraContour);
        _window.draw(_inv);
        _Ath->displayInventory(&_window);
        _window.display();
    }
}

void Graphical::updateMyAnimation(float deltaTime)
{
    for (int i = 0; i != background.size(); i++) {
        background[i]->animation->update(0, deltaTime);
        background[i]->sprite.setTextureRect(background[i]->animation->uvRect);
    }
}

void Graphical::displayBackground()
{
    for (int i = 0; i != background.size(); i++) {
        _window.draw(background[i]->sprite);
    }
}

void Graphical::initBackground()
{
    for (int y = 0; y <= _map->_ySizeMap + 200; y += 32) {
        for (int x = 0; x <= _map->_xSizeMap + 200; x += 32) {
            Background *tile = new(Background);
            tile->x = x;
            tile->y = y;
            tile->sprite.setPosition(x, y);
            tile->texture.loadFromFile("GRAPHICAL/assets/water.png");
            tile->sprite.setTexture(tile->texture);
            tile->animation = new Animation(&tile->texture , sf::Vector2u(15, 1), 1.2f);
            background.push_back(tile);

        }
    }
}

void Graphical::displayMap()
{
    for (int i = 0; i != _map->_mapElement.size() ; i++) {

        sf::Vector2f pos;
        pos.x = 0;
        pos.y = 0;
        _window.draw(_map->_mapElement[i]->_Stuile);

        _map->_mapElement[i]->_hitBoxILE.setOutlineColor(sf::Color::Blue);
        _map->_mapElement[i]->_hitBoxILE.setOutlineThickness(2);
        _map->_mapElement[i]->_hitBoxILE.setPosition(_map->_mapElement[i]->_Stuile.getPosition().x + 60, _map->_mapElement[i]->_Stuile.getPosition().y + 60);
        sf::Vector2f newSize(75.0f, 75.0f);
        _map->_mapElement[i]->_hitBoxILE.setSize(newSize);
        // _window.draw( _map->_mapElement[i]->_hitBoxILE);
    }
}

void Graphical::displayPlayer()
{
    for (int i = 0; i != _listPlayer.size(); i++) {
        if (_listPlayer.size() != 0) {
            _FluxClient->sendMessage("ppo " + _listPlayer[i]->_uuidPlayer + "\n");
            
            _window.draw( _listPlayer[i]->_Splayer);

            _listPlayer[i]->_hitBoxPlayer.setOutlineColor(sf::Color::Blue);
            _listPlayer[i]->_hitBoxPlayer.setOutlineThickness(2);
            _listPlayer[i]->_hitBoxPlayer.setOrigin(25.0f / 2,  25.0f / 2);
            _listPlayer[i]->_hitBoxPlayer.setPosition( _listPlayer[i]->_Splayer.getPosition());
            sf::Vector2f newSize(25.0f, 25.0f);
            _listPlayer[i]->_hitBoxPlayer.setSize(newSize);
            // _window.draw( _listPlayer[i]->_hitBoxPlayer);
            // _listPlayer[i]->getInfoByCross(_crossCentre.x, _crossCentre.y);
        }
    }
}
