#pragma once
/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** IGameModule.hpp
*/

#include <iostream>
#include "../../utils/utils.hpp"
#include "../../board/board.hpp"
#include "vector"

namespace arc {
    class IGameModule
    {
        public:
            virtual ~IGameModule() = default;
            virtual void init(board *board) = 0;
            virtual void stop() = 0;
            virtual const std::string& getName() const = 0;
            virtual bool gameOver() = 0;
            virtual void update(arc::Input, board*) = 0;
    };
};