/*
EPITECH PROJECT, 2022
Arcade
File description:
lib.hpp
*/

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <dlfcn.h>
#include <iostream>
#include <ncurses.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include "../../board/board.hpp"
#include "../include/IGameModule.hpp"
#include "../../utils/utils.hpp"

#define SnakeHead "assets/snakeHeadUp.png"
#define SnakeHeadUp "assets/snakeHeadUp.png"
#define SnakeHeadRight "assets/snakeHeadRight.png"
#define SnakeHeadLeft "assets/snakeHeadLeft.png"
#define SnakeHeadDown "assets/snakeHeadDown.png"
#define SnakeBody "assets/snakeBody.png"
#define SnakeBG "assets/snakeBG.png"
#define SnakeWall "assets/snakeWall.png"
#define SnakeFood1 "assets/snakeFood1.png"
#define SnakeFood2 "assets/snakeFood2.png"
#define SnakeFood3 "assets/snakeFood3.png"


extern "C" {
    void initSnake();
    void closeSnake();
}

// Définition des constantes pour la taille de la fenêtre
const int HEIGHT = 10;
const int WIDTH = 20;


    class snake : public arc::IGameModule
    {
        public:
            snake() {
                this->gameOver_ = false;
            };
            ~snake() {};
            void char_to_object(board *board, char ptrChar, int x, int y);
            void init(board *board) override;
            void stop() override {
                exit(0);
            };
            virtual bool gameOver() override;

            const std::string& getName() const override;
            char direction; // la direction dans laquelle le serpent se déplace
            void grow() {};
            bool ate(std::vector<std::string> food) const {};
            void collision();

            std::vector<std::string> generateFood(std::vector<std::string> board)
            {
                int x = rand() % (WIDTH - 1) + 1;
                int y = rand() % (HEIGHT - 1) + 1;
                return board;
            }
            void moveUp(board*);
            void moveRight(board*);
            void moveDown(board*);
            void moveLeft(board*);
            void update(arc::Input, board*) override;
            void deleteTail(board*, int, int);
        // protected:
            int xPos;
            int yPos;
            bool gameOver_;
            std::vector<int> _lifeMob;
    };