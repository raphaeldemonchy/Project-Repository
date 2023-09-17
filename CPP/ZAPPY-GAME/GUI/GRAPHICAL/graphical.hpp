/*
** EPITECH PROJECT, 2023
** graphical
** File description:
** graphical
*/

#pragma once
#include "../CLIENT/client.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include "../ANIMATION/animation.hpp"
#include "CAMERA/camera.hpp"
#include "ATH/ath.hpp"


////////////////////////////////////////////////////////////////////////////
//                                                                        //
//                         [MAP -> TUILE -> ITEM]                         //
//                                                                        //
////////////////////////////////////////////////////////////////////////////

struct Item {
    int FOOD = 0;
    int LINEMATE = 0;
    int DERAUMERE = 0;
    int SIBURE = 0;
    int MENDIANE = 0;
    int PHIRAS = 0;
    int THYSTAM = 0;
};

class Tuile {
    public:
        //NIQUE//
        Tuile();
        ~Tuile();
        //=====//
        void initTuileByPos(int x, int y, int q0, int q1, int q2, int q3, int q4, int q5, int q6, std::string pathTexture);
        void updateTuile(float deltaTime);

            // Si l'élément n'est pas trouvé dans le vecteur, vous pouvez choisir de l'ajouter avec la nouvelle quantité ici


        int _xposTuile;
        int _yposTuile;
        Item* _items;
        sf::Texture _Ttuile;
        sf::Sprite _Stuile;
        Animation *_animation;

        sf::RectangleShape _hitBoxILE;

        int _nbEGGS;
        int _playerPresent;


};

///==================================================================================================================///

class Map {
    public:
        //NIQUE//
        Map();
        ~Map();
        //=====//
        void initMap(int sizeX, int sizeY) {
            _xSizeMap = sizeX * 180;
            _ySizeMap = sizeY * 188;
            if (!_Tcross.loadFromFile("GRAPHICAL/assets/cross.png")) {
                std::cerr << "Erreur lors du chargement d'image" << std::endl;
            }
            _Scross.setTexture(_Tcross);
            _Scross.setPosition(_xSizeMap / 2, _ySizeMap /2);
        }


        void initNewTuileAtPos(int x, int y, int q0, int q1, int q2, int q3, int q4, int q5, int q6, std::string pathTexture);
        void updateTuileContentAtPos(int x, int y, int q0, int q1, int q2, int q3, int q4, int q5, int q6);
        void getSpriteTuile() {}
        Tuile *getTileByXY(int x, int y);
        void afficherElements()
        { 
            std::cout << "size map" << _mapElement.size() << std::endl;
            for (int i = 0; i != _mapElement.size() ; i++) {
                std::cout << "x" << _mapElement[i]->_xposTuile << std::endl;
                std::cout << "y" << _mapElement[i]->_yposTuile << std::endl;
            }
        }


        int _xSizeMap;
        int _ySizeMap;
        std::vector<Tuile *> _mapElement;

        sf::Texture _Tbackground;
        sf::Sprite _Sbackground;
        
        std::vector<sf::Texture> _animationTextures;
        //CROSSHAIR

        float _crossScaleX = 1;
        float _crossScaleY = 1;

        sf::Texture _Tcross;
        sf::Sprite _Scross;

        sf::RectangleShape _crossHitBox;

        


};

////////////////////////////////////////////////////////////////////////////
//                                                                        //
//                                [PLAYER]                                //
//                                                                        //
////////////////////////////////////////////////////////////////////////////

enum Orientation {
    Up = 1,
    Down = 3,
    Left = 4,
    right = 2,
};

enum States {
    Death = 1,
    Incantation = 2,
    Spawn = 3,
    Fork = 4,
    Take = 5,
    Set = 7
};

class Player {
    public:
        //NIQUE//
        Player();
        ~Player();
        void initPlayer(std::string uuid, int x, int y, int orientation, int lvl, std::string team, std::string imgPath);
        void refreshPlayerList();
        //INVENTORY MANAGEMENT//
        void getInfoByCross(float cross_x, float cross_y);
        

        //=====//
        Item* inventory;

        int _xPlayer;
        int _yPlayer;
        Orientation _orientation;
        int level;
        States _state;
        std::string _teamName;
        std::string _uuidPlayer;

        sf::Texture _Tplayer;
        sf::Sprite _Splayer;

        sf::RectangleShape _hitBoxPlayer;
        
};

////////////////////////////////////////////////////////////////////////////
//                                                                        //
//                           [ GRAPHICAL ]                                //
//                                                                        //
////////////////////////////////////////////////////////////////////////////

class Graphical {
    public:
        typedef struct Background_t {
            sf::Sprite sprite;
            sf::Texture texture;
            Animation *animation;
            int x, y;
        }Background;
        Graphical(int P, std::string adresse);
        ~Graphical();

        void handleRightClick();
        void handleClickManagment();
        bool crossHairContact(const sf::RectangleShape& rect1, const sf::RectangleShape& rect2);

        std::string countPlayer(int x, int y);

        void runGraphical();
        void updateMyAnimation(float deltaTime);
        void initClient(Client *client){_FluxClient = client;}
        void displayMap();
        void displayPlayer();
        void displayBackground();
        void initBackground();

        void drawInWindow(sf::Sprite _element) {
            _window.draw(_element);
        }



        bool _isRunning;

        Client *_FluxClient;
    //SFML//
        sf::RenderWindow _window;
        sf::View _cameraView;
        sf::Event _event;

        sf::Clock _clock;
        float _deltaTime;

        sf::Texture _TcameraContour;
        sf::Sprite _ScameraContour;
        float scale_contour_x = 0.52;
        float scale_contour_y = 0.92;
        float centercoeff = 1; 

    //INVENTAIRE//
        sf::Sprite _inv;

    //CAMERA//
        sf::Vector2f _mapSize;
        // Camera *_camera = new Camera(_window, _mapSize);

    //ATH//
        ATH *_Ath;

    //OBJECT//
        Map *_map;
        std::vector<Player*> _listPlayer;
        std::vector<Background *> background;

};
