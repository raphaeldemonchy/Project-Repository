/*
**
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Arcade.cpp
*/

#include <unistd.h>
#include <stdio.h>
#include "DLloader/DLloader.hpp"
#include "Core/include/Core.hpp"
#include "Game/include/IGameModule.hpp"
#include "Graphical/include/IDisplayModule.hpp"
#include "errorHandling/errorHandling.hpp"

void displayArcadeStart()
{
    std::cout << "︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻" << std::endl;
    std::cout << "          :::        :::::::::       ::::::::           :::        :::::::::       ::::::::::" << std::endl;
    std::cout << "       :+: :+:      :+:    :+:     :+:    :+:        :+: :+:      :+:    :+:      :+:        " << std::endl;
    std::cout << "     +:+   +:+     +:+    +:+     +:+              +:+   +:+     +:+    +:+      +:+          " << std::endl;
    std::cout << "   +#++:++#++:    +#++:++#:      +#+             +#++:++#++:    +#+    +:+      +#++:++#      " << std::endl;
    std::cout << "  +#+     +#+    +#+    +#+     +#+             +#+     +#+    +#+    +#+      +#+            " << std::endl;
    std::cout << " #+#     #+#    #+#    #+#     #+#    #+#      #+#     #+#    #+#    #+#      #+#             " << std::endl;
    std::cout << "###     ###    ###    ###      ########       ###     ###    #########       ##########       " << std::endl;
    std::cout << "︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼ " << std::endl;
    std::cout << "˃ Starting [ARCADE]" << std::endl;
    std::cout << "      Make by :" << std::endl;
    std::cout << "          ➫ Project Leader / Architecture     : Mohamed Mansour" << std::endl;
    std::cout << "          ➬ Game designer / Graphics designer : Raphael de Monchy" << std::endl;
    std::cout << "          ➩ Game designer / Redaction         : Noah Yekken" << std::endl;
}

void arcade(char *src)
{
    // displayArcadeStart();
    // sleep(4);
    DLloader <arc::IGameModule> loaderGa;
    DLloader <arc::IDisplayModule> loaderGr;
    arc::IDisplayModule *graph;
    arc::IGameModule *game;
    loaderGr.openLoader(src);
    graph = loaderGr.getInstance();
    board Board;
    int key = 0;
    while (1) {
        graph->init();
        key = graph->handle_key();
        if (key == arc::Input::nextLib) {
            
            if (myStrCmp(graph->getName(), "sdl2") == 0) {
                delete graph;
                loaderGr.closeLoader();
                loaderGr.openLoader("lib/arcade_ncurses.so");
            } else if (myStrCmp(graph->getName(), "ncurses") == 0) {
                delete graph;
                loaderGr.closeLoader();
                loaderGr.openLoader("lib/arcade_sfml.so");
            } else if (myStrCmp(graph->getName(), "sfml") == 0) {
                delete graph;
                loaderGr.closeLoader();
                loaderGr.openLoader("lib/arcade_sdl2.so");
            } else {
                Error::err_("Library not founding");
            }
            graph = loaderGr.getInstance();
        }
        if (key == arc::Input::StartSnake) {
            loaderGa.openLoader("lib/arcade_snake.so");
            game = loaderGa.getInstance();
            break;
        }
        if (key == arc::Input::StartSfox) {
            loaderGa.openLoader("lib/arcade_solarfox.so");
            game = loaderGa.getInstance();
            break;
        }
    }
    if (myStrCmp(game->getName(), "Snake") == 0) 
            Board.setBoardMap("Game/snake/map/snakeMap");
    if (myStrCmp(game->getName(), "solarFox") == 0)
            Board.setBoardMap("Game/solarFox/map/solarFoxMap");

    arc::Input g = arc::Input::UP;
    game->init(&Board);

    
    while (!game->gameOver()) {
        g = graph->handle_key();
            if (g == arc::Input::nextGame) {
                if (myStrCmp(game->getName(), "Snake") == 0) {
                    loaderGa.closeLoader();
                    // delete game;
                    loaderGa.openLoader("lib/arcade_solarfox.so");
                    game = loaderGa.getInstance();                   
                    Board.setBoardMap("Game/solarFox/map/solarFoxMap");
                    game->init(&Board);
                    // graph->update();
                    g = arc::Input::NONE;
                } else if (myStrCmp(game->getName(), "solarFox") == 0) {
                    loaderGa.closeLoader();
                    // delete game;
                    loaderGa.openLoader("lib/arcade_snake.so");
                    game = loaderGa.getInstance();
                    Board.setBoardMap("Game/snake/map/snakeMap");
                    game->init(&Board);
                    // graph->update();
                    g = arc::Input::NONE;

                }
                // game->update(g, &Board);
            } 
            if (g == arc::Input::nextLib) {
            if (myStrCmp(graph->getName(), "sdl2") == 0) {
                delete graph;
                loaderGr.closeLoader();
                loaderGr.openLoader("lib/arcade_ncurses.so");
            } else if (myStrCmp(graph->getName(), "ncurses") == 0) {
                delete graph;
                loaderGr.closeLoader();
                loaderGr.openLoader("lib/arcade_sfml.so");
            } else if (myStrCmp(graph->getName(), "sfml") == 0) {
                delete graph;
                loaderGr.closeLoader();
                loaderGr.openLoader("lib/arcade_sdl2.so");
            } else {
                Error::err_("Library not founding");
            }
            graph = loaderGr.getInstance();
            graph->display_board(&Board);
        } else {
            game->update(g, &Board);
            graph->update();
            graph->display_board(&Board);
        }
    }
}

int main(int ac, char **av)
{
    if (ac != 2)
        Error::err_("invalid arguments");
    arcade(av[1]);
    return 0;
}