/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** GUI
*/

#include "GUI.hpp"

GUI::GUI()
    : _window(sf::VideoMode(1910, 1080), "Adaptation de l'arrière-plan SFML"),
      _view(sf::FloatRect(0.f, 0.f, 650.f, 611.f))
{
    if (!_backgroundTexture.loadFromFile("GRAPHICAL/assets/backMenu.png")) {
        std::cerr << "ERROR : Failed load sprite" << std::endl;
    }
    if (!_font.loadFromFile("GUI/assets/hs.ttf")) {
        std::cerr << "ERROR : Failed load font" << std::endl;
    }

    if (!_buttonOffTexture.loadFromFile("GRAPHICAL/assets/buttonMenu.png")) {
        std::cerr << "ERROR: Failed to load buttonoff.png" << std::endl;
    }

    if (!_buttonOnTexture.loadFromFile("GUI/assets/buttonOn.png")) {
        std::cerr << "ERROR: Failed to load buttonon.png" << std::endl;
    }

    _backgroundSprite.setTexture(_backgroundTexture);
    _champ1.setSize(sf::Vector2f(155, 30));
    _champ2.setSize(sf::Vector2f(155, 30));

    _text1.setFont(_font);
    _text1.setCharacterSize(15);
    _text2.setFont(_font);
    _text2.setCharacterSize(15);
    _isChamp1Selected = false;
    _isChamp2Selected = false;
                    // larg   haut
    _champ1.setPosition(915, 505);
    _champ2.setPosition(910, 546);

    _text1.setPosition(915, 505);
    _text2.setPosition(910, 546);
    //BUTTON LUNCH//
    _buttonOffSprite.setTexture(_buttonOffTexture);
    _buttonOnSprite.setTexture(_buttonOnTexture);

    _buttonOffSprite.setPosition(850, 750);
    _buttonOnSprite.setPosition(850, 750);

    _isButtonOn = false;

    draw_GUI();
    _isOn = true;

}

void GUI::setColor_GUI()
{
    const sf::Color selectedColor = sf::Color(128, 128, 128);
    const sf::Color defaultColor = sf::Color::White;

    _text1.setFillColor(_isChamp1Selected ? sf::Color::Blue : selectedColor);
    _text2.setFillColor(_isChamp2Selected ? sf::Color::Blue : selectedColor);

    _champ1.setFillColor(_isChamp1Selected ? selectedColor : defaultColor);
    _champ2.setFillColor(_isChamp2Selected ? selectedColor : defaultColor);
}

void GUI::text_zone()
{
    sf::Vector2f textSize1(_champ1.getSize().x, _champ1.getSize().y);
    while (_text1.getLocalBounds().width > textSize1.x || _text1.getLocalBounds().height > textSize1.y) {
        unsigned int characterSize = _text1.getCharacterSize();
        _text1.setCharacterSize(characterSize - 1);
    }
    
    sf::Vector2f textSize2(_champ2.getSize().x, _champ2.getSize().y);
    while (_text2.getLocalBounds().width > textSize2.x || _text2.getLocalBounds().height > textSize2.y) {
        unsigned int characterSize = _text2.getCharacterSize();
        _text2.setCharacterSize(characterSize - 1);
    }

    if (_event.type == sf::Event::TextEntered && _event.text.unicode == '\b') {
        if (_isChamp1Selected && !_portEnter.empty()) {
            _portEnter.pop_back();
        } else if (_isChamp2Selected && !_machineEnter.empty()) {
            _machineEnter.pop_back();
        }
        
        _text1.setCharacterSize(15);
        _text2.setCharacterSize(15);
    }

    if (_event.type == sf::Event::TextEntered) {
        if (_event.text.unicode < 128) {
            if (_isChamp1Selected) {
                if (_event.text.unicode == '\b' && !_portEnter.empty()) {
                    _portEnter.pop_back();
                } else if (_event.text.unicode != '\b') {
                    _portEnter += static_cast<char>(_event.text.unicode);
                }
            } else if (_isChamp2Selected) {
                if (_event.text.unicode == '\b' && !_machineEnter.empty()) {
                    _machineEnter.pop_back();
                } else if (_event.text.unicode != '\b') {
                    _machineEnter += static_cast<char>(_event.text.unicode);
                }
            }
        }
    }
    if (_event.type == sf::Event::MouseButtonPressed) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(_window);
        if (_champ1.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            _isChamp1Selected = true;
            _isChamp2Selected = false;
        } else if (_champ2.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            _isChamp1Selected = false;
            _isChamp2Selected = true;
        }
        setColor_GUI();
        draw_GUI();
    }
}

void GUI::draw_GUI()
{
    _window.clear();
    _window.setView(_view);
    _window.draw(_backgroundSprite);
    _window.draw(_champ1);
    _window.draw(_champ2);
    _window.draw(_text1);
    _window.draw(_text2);

    if (_isButtonOn) {
        _window.draw(_buttonOnSprite);
    } else {
        _window.draw(_buttonOffSprite);
    }
    _window.display();
}

void GUI::buttonEvent()
{
    if (_event.type == sf::Event::MouseButtonPressed) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(_window);
        if (_buttonOffSprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            _isButtonOn = !_isButtonOn;
            lunch_action();
        }  
    }
}

void GUI::lunch_action()
{
    _window.close();
    _music.stop();
    _isOn = false;
    std::cout << "ACTION LANCÉ" << std::endl;
}


void GUI::run()
{
    if (!_music.openFromFile("GRAPHICAL/assets/intro.ogg")) {
        std::cout << "fail load music" << std::endl;
    }
    while (_window.isOpen()) {
        _music.play();
        while (_window.pollEvent(_event)) {
            if (_event.type == sf::Event::Closed) {
                _window.close();
            }
            text_zone();
            buttonEvent();
        }

        _text1.setString(_portEnter);
        _text2.setString(_machineEnter);

        // RECENTRER IMG //
        sf::Vector2f windowSize(_window.getSize().x, _window.getSize().y);
        _view.setSize(windowSize);
        _view.setCenter(windowSize.x / 2, windowSize.y / 2);
        //===============//

        draw_GUI();
        if (_isOn == false) {
            break;
        }
    }
}


