/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** sdl2.hpp
*/

#pragma once
#include <map>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "../../utils/utils.hpp"
#include "../include/IDisplayModule.hpp"

class sdl2 : public arc::IDisplayModule
{
    public:
        sdl2();
        ~sdl2();
        void stop() override;
        const std::string& getName() const override;
        void init() override;
        void update() override;
        bool gameOver() override;
        bool isOpen() override;
        arc::Input handle_key() override;
        arc::Input prviousValue;
        //DISPLAY//
        void display_text(std::string text, int x, int y) override {};
        void display_board(board *board) override;
        void display_object(arc::Obj obj);
        int getSizeWindowX() override {};
        int getSizeWindowY() override {};
    
    protected:
        // MENU //
        SDL_Window *window_;
        SDL_Renderer *renderer_;
        SDL_Texture* texture_;

        TTF_Font *font_;
        Mix_Music *music_;

        // TITLE //
        SDL_Color colorW_ = { 255, 255, 255 };
        SDL_Surface* surfaceMessage_;
        SDL_Texture* message_;
        SDL_Rect rectMessage_;

        //DISPLAY OBJECT //
        SDL_Texture* Otexture_;
        SDL_Surface* Osurface_;
        SDL_Rect destRect_;
};