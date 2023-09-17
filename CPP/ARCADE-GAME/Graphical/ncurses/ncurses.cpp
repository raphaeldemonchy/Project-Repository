/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-raphael.de-monchy
** File description:
** ncurses.cpp
*/

#include "ncurses.hpp"

extern "C" void initNcurses() __attribute__((constructor));
extern "C" void closeNcurses() __attribute__((destructor));
extern "C" arc::IDisplayModule *entryPoint();

// // MANAGE LIBRAIRIE //


extern "C" void initNcurses()
{
    // printf("[ncurses] Loading ncurses library...\n");
}

extern "C" void closeNcurses()
{
    // printf("[ncurses] ncurses closing.\n");
}

extern "C" arc::IDisplayModule *entryPoint()
{
    // printf("[ncurses] entry point !\n");
    return new ncurses();
}

//CONSTRUCOT DESTRUCTOR//

ncurses::ncurses()
{
    initscr();
    nodelay(stdscr, true);
    noecho();
    keypad(stdscr, true);
    this->is_Open = true;
    curs_set(0);
    init_color();
    this->prviousValue = arc::Input::NONE;
}

ncurses::~ncurses()
{
    wclear(stdscr);
    endwin();
}


//INIT NCURSES ELEMENT //

const std::string& ncurses::getName() const {
            static const std::string name = "ncurses";
            return name;
}

void ncurses::init_color()
{
    if (!has_colors()) {
        // la console ne supporte pas les couleurs
        return;
    }

    start_color();  // initialisation des couleurs
    init_pair(0, COLOR_BLACK, COLOR_BLACK);
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_CYAN, COLOR_BLACK);
    init_pair(7, COLOR_WHITE, COLOR_BLACK);
}

//WINDOW//

void ncurses::init()
{
    // ncurses::display_text("MENU", 10, 10);
    // clear();
    const char *titleA = "ARCADE";
    const char *titleS = "[1]Snake";
    const char *titleSF = "[2] -> SolarFOX";
    refresh();

    int windowHeight, windowWidth;
    getmaxyx(stdscr, windowHeight, windowWidth);

    // Calcule la position de chaque élément du menu
    int titleX = (windowWidth - 30) / 2; // Centre le titre
    int titleY = (windowHeight - 6) / 3;
    int promptX = (windowWidth - 23) / 2; // Centre la prompt
    int promptY = titleY + 4;
    int snakeX = promptX - 10;
    int snakeY = promptY + 2;
    int solarFoxX = promptX + 6;
    int solarFoxY = promptY + 2;

    // Affiche le titre
    mvprintw(titleY, titleX, "/##################################\\");
    mvprintw(titleY + 1, titleX, "#               ARCADE             #");
    mvprintw(titleY + 2, titleX, "#----------------------------------#");
    mvprintw(titleY + 3, titleX, "#                _____             #");
    mvprintw(titleY + 4, titleX, "#                Press             #");
    mvprintw(titleY + 5, titleX, "#        [1]                [2]    #");
    mvprintw(titleY + 6, titleX, "#      Snake             SolarFox  #");
    mvprintw(titleY + 7, titleX, "#                                  #");
    mvprintw(titleY + 8, titleX, "\\##################################/");
    mvprintw(titleY + 9, titleX, "=[MENU]=>==>==>==>==>==>==>==>==>=>=");
}

void ncurses::update()
{
    wrefresh(stdscr);
}

void ncurses::stop()
{
    wclear(stdscr);
    exit(0);
}

// //DISPLAY//


void ncurses::display_board(board* Game)
{
    erase();
    for (int i = 0; i < Game->boardMap.size(); i += 1) {
        for (int j = 0; j < Game->boardMap[j].size(); j += 1) {
            if (Game->boardMap[i][j] == 'R' || Game->boardMap[i][j] == 'D' || Game->boardMap[i][j] == 'L')
                Game->boardMap[i][j] = 'O';
            if (Game->boardMap[i][j] == '1' || Game->boardMap[i][j] == '2')
                Game->boardMap[i][j] = '|';
            if (Game->boardMap[i][j] == '3' || Game->boardMap[i][j] == '4')
                Game->boardMap[i][j] = '-';
        }
    }
    for (int i = 0; const auto &j: Game->boardMap) {
        mvprintw(i, 30, j.c_str());
        i += 1;
    }
    refresh();
}

void ncurses::display_text(std::string text, int x, int y)
{
    mvprintw(ncurses::getSizeWindowY() / 2, ncurses::getSizeWindowY() / 2, text.c_str());
}

// EVENT //

arc::Input ncurses::handle_key()
{
    int c = getch();
    if (c == KEY_UP) {
        if (this->prviousValue == arc::Input::DOWN)
            return arc::Input::DOWN;
        this->prviousValue = arc::Input::UP;
        return arc::Input::UP;
    }
    if (c == KEY_DOWN) {
        if (this->prviousValue == arc::Input::UP)
            return arc::Input::UP;
        this->prviousValue = arc::Input::DOWN;
        return arc::Input::DOWN;
    }
    if (c == KEY_LEFT) {
        if (this->prviousValue == arc::Input::RIGHT)
            return arc::Input::RIGHT;
        this->prviousValue = arc::Input::LEFT;
        return arc::Input::LEFT;
    }
    if (c == KEY_RIGHT) {
        if (this->prviousValue == arc::Input::LEFT)
            return arc::Input::LEFT;
        this->prviousValue = arc::Input::RIGHT;
        return arc::Input::RIGHT;
    }
    if (c == 10) {
        this->prviousValue = arc::Input::ENTER;
        return arc::Input::ENTER;
    }
    if (c == 32) {
        return arc::Input::SPACE;
    }
    if (c == 49 || c == '&') {
        this->prviousValue = arc::Input::StartSnake;
        return arc::Input::StartSnake;
    }
    if (c == 50) {
        this->prviousValue = arc::Input::StartSfox;
        return arc::Input::StartSfox;
    }
    if (c == 'g') {
        this->prviousValue = arc::Input::nextLib;
        return arc::Input::nextLib;
    }
    if (c == 115) {
        this->prviousValue = arc::Input::NONE;
        return arc::Input::nextGame;
    }
    return this->prviousValue;
}

bool ncurses::gameOver()
{
    return false;
}

bool ncurses::isOpen()
{
    return this->is_Open;
}

int ncurses::getSizeWindowX()
{
    int max_y, max_x;
    getmaxyx(stdscr, max_y, max_x);
    return max_x;
}

int ncurses::getSizeWindowY()
{
    int max_y, max_x;
    getmaxyx(stdscr, max_y, max_x);
    return max_y;
}