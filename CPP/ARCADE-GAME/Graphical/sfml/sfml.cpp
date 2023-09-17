/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-raphael.de-monchy
** File description:
** sfml.cpp
*/

#include "sfml.hpp"

extern "C" void initSfml() __attribute__ ((constructor));
extern "C" void closeSfml() __attribute__ ((destructor));
extern "C" arc::IDisplayModule *entryPoint();

// MANAGE LIBRAIRIE //

extern "C" void initSfml()
{
    // printf("[sfml] Loading sfml library...\n");
}

extern "C" void closeSfml()
{
    // printf("[sfml] sfml closing.\n");
}

extern "C" arc::IDisplayModule *entryPoint()
{
    // printf("[sfml] entry point !\n");
    return new sfml();
}

// CONSTRUCTOR DESTRUCTOR //

int check_lib()
{
    return 0;
}

sfml::sfml()
{
    this->_window.create(sf::VideoMode(1920, 1080), "My SFML Window", sf::Style::Resize | sf::Style::Close);
    this->_window.setFramerateLimit(60);
    this->_window.setKeyRepeatEnabled(true);
    this->_score.setFont(this->_font);
    this->_score.setCharacterSize(30);
    this->_score.setFillColor(sf::Color::White);
    if (check_lib() > 0)
        std::cout << "Load SFML librairie : failed" << std::endl;
    this->prviousValue = arc::Input::NONE;
    //
    //
}

sfml::~sfml()
{
    // sf::Listener::setGlobalVolume(0);
    //é
    //
    this->_music.stop();
    this->_window.close();
}

// WINDOW//

void sfml::init()
{
    sf::Vector2u windowSize = this->_window.getSize();
    sf::FloatRect spriteBounds = this->_sprite.getLocalBounds();
    float windowMidX = windowSize.x / 2.0f;
    float windowMidY = windowSize.y / 2.0f;
    float spriteMidX = spriteBounds.width / 2.0f;
    float spriteMidY = spriteBounds.height / 2.0f;
    float spritePosX = windowMidX - spriteMidX;
    float spritePosY = windowMidY - spriteMidY;


    if (!this->_texture.loadFromFile("assets/arcadeMenu.png") || !this->_TSnakeB.loadFromFile("assets/snakeButton.png") 
    || !this->_TsolarFoxB.loadFromFile("assets/solarFoxButton.png") || !this->_bgText.loadFromFile("assets/backBGmenu.jpg")) {
        std::cerr << "Erreur load sprite" << std::endl;
        exit(84);
    }

    // if (!this->_music.openFromFile("assets/arcadeZike.wav"))
    //     std::cerr << "fail sound " << std::endl;

    // this->_music.setVolume(100);
    // this->_music.setLoop(true);

    // 
    sf::Vector2i vector = {sfml::getSizeWindowX(), sfml::getSizeWindowY()};
    this->_menuBgSprite.setTexture(this->_bgText);
    this->_sprite.setTexture(this->_texture);
    this->_SsnakeB.setTexture(this->_TSnakeB);
    this->_SsolarFoxB.setTexture(this->_TsolarFoxB);
    //
    this->_sprite.setPosition(1920 / 4.5, -20);
    this->_SsnakeB.setPosition(720, 430);
    this->_SsolarFoxB.setPosition(990, 430);
    // this->_menuBgSprite.setPosition(1920 / 2, 1080);
    //

    this->_window.clear();
    this->_window.draw(this->_menuBgSprite);
    this->_window.draw(this->_sprite);
    this->_window.draw(this->_SsnakeB);
    this->_window.draw(this->_SsolarFoxB);
    // this->_music.play();
}

void sfml::update()
{
    // this->_window.draw(this->_score);
    this->_window.display();
}

void sfml::stop()
{
    this->_window.clear(sf::Color::Black);
}
// DISPLAY //

void sfml::display_object(arc::Obj Obj)
{
    sf::Texture actualText;
    sf::Sprite actualSprite;

    if (!actualText.loadFromFile(Obj._path)) {
        Error::err_("Erreur load sprite");
    }
    
    actualSprite.setTexture(actualText);
    actualSprite.setPosition(Obj.x, Obj.y);
    this->_window.draw(actualSprite);
    // this->_window.display();
}

void sfml::display_board(board *board)
{
    int pos_x = 0;
    int pos_y = 0;
    this->_window.clear();
    // if (!this->_font.loadFromFile("stocky.ttf")) {
    //     std::cerr << "Failed to load font" << std::endl;
    // }
    //SCORE//
    // this->_score.setPosition(10, 10);
    // board->score = "1000";
    // this->_score.setString("Score :" + board->score);
    //    //
    for (size_t i = 0; i < board->_Object.size(); i++) {
        display_object(board->_Object[i]);
    }
    // board->_Object.clear();
    // this->_window.display();
    // display_object(board->_Object[1]);
}

void sfml::display_text(std::string text, int x, int y)
{

}

// EVENT //


arc::Input sfml::handle_key()
{
    this->_window.display();
        while (this->_window.pollEvent(_event))
        {
            // sf::sleep(sf::milliseconds(150));
            if (_event.type == sf::Event::Closed) {
                this->_window.close();
                exit (0);
            }
            if (this->_event.key.code == sf::Keyboard::Up) {
                this->prviousValue = arc::Input::UP;
                return arc::Input::UP;
            }
            if (this->_event.key.code == sf::Keyboard::Down) {
                this->prviousValue = arc::Input::DOWN;
                return arc::Input::DOWN;
            }
            if (this->_event.key.code == sf::Keyboard::Left) {
                this->prviousValue = arc::Input::LEFT;
                return arc::Input::LEFT;
            }
            if (this->_event.key.code == sf::Keyboard::Right) {
                this->prviousValue = arc::Input::RIGHT;
                return arc::Input::RIGHT;
            }
            if (this->_event.key.code == sf::Keyboard::Enter) {
                this->prviousValue = arc::Input::ENTER;
                return arc::Input::ENTER;
            }
            if (this->_event.key.code == sf::Keyboard::Space) {
                this->prviousValue = arc::Input::SPACE;
                return arc::Input::SPACE;
            }
            if (this->_event.key.code == sf::Keyboard::Num1 || this->_event.key.code == sf::Keyboard::Quote) {
                this->prviousValue = arc::Input::StartSnake;
                return arc::Input::StartSnake;
            }
            if (this->_event.key.code == sf::Keyboard::Num2) {
                this->prviousValue = arc::Input::StartSfox;
                return arc::Input::StartSfox;
            }
            if (this->_event.key.code == sf::Keyboard::G) {
                this->prviousValue = arc::Input::NONE;
                return arc::Input::nextLib;
            }
            if (this->_event.key.code == sf::Keyboard::S) {
                this->prviousValue = arc::Input::NONE;
                return arc::Input::nextGame;
            }
        }
    return this->prviousValue;
}

bool sfml::gameOver()
{
    exit(2);
}

bool sfml::isOpen()
{
    return this->_window.isOpen();
}

//WSIZE//

int sfml::getSizeWindowX()
{
    int windowSize = this->_window.getSize().x;
    return windowSize;
}

int sfml::getSizeWindowY()
{
    int windowSize = this->_window.getSize().y;
    return windowSize;
}