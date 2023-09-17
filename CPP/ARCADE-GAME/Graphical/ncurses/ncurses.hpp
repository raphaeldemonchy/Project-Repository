/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** ncurses.hpp
*/

#include "../include/IDisplayModule.hpp"
#include <ncurses.h>
#pragma once

class ncurses : public arc::IDisplayModule
{
    public:
        ncurses();
        ~ncurses();
        const std::string& getName() const override;
        int getCmd()
        {
            return this->cmd_;
        };
        //INIT COLOR//
        void init_color();

        //WINDOW//
        void init() override;
        void update() override;
        void stop() override;

        //DISPLAY//
        void display_board(board*) override;
        void display_text(std::string text, int x, int y) override;

        //EVENT//
        arc::Input handle_key() override;
        bool gameOver() override;
        bool isOpen() override;
    
        //WSIZE//
        int getSizeWindowX() override;
        int getSizeWindowY() override;
        arc::Input prviousValue;
    protected:
        bool is_Open;
        bool is_GameOver;
        int cmd_;
};
