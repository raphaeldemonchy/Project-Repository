/*
** EPITECH PROJECT, 2023
** parser
** File description:
** parser
*/

#include "parser.hpp"

Parser::Parser()
{
    
}

Parser::~Parser()
{
}

void Parser::myParser(const std::string &request, Graphical *graphical)
{
    std::istringstream iss(request);
    std::string word;
    std::vector<std::string> parsedRequest;

        
    while (std::getline(iss, word, '\n')) {
        std::istringstream wordStream(word);
        std::string subWord;
        while (wordStream >> subWord) {
            parsedRequest.push_back(subWord);
        }
        execAllBasicCmd(parsedRequest, graphical, 1);
        parsedRequest.clear();
    }

}

void Parser::myBasicParser(const std::string &request, Graphical *graphical)
{
    std::istringstream iss(request);
    std::string word;
    std::vector<std::string> parsedRequest;

    while (std::getline(iss, word, '\n')) {
        std::istringstream wordStream(word);
        std::string subWord;
        while (wordStream >> subWord) {
            parsedRequest.push_back(subWord);
        }
        execAllBasicCmd(parsedRequest, graphical, 0);
        parsedRequest.clear();
    }
}

////////////////////////////////
//       { CMD func}        //
//////////////////////////////


void Parser::mszCMD(std::vector<std::string> parsedRequest, Graphical *graphical, int opt)
{
    int x = std::stoi(parsedRequest[1]);
    int y = std::stoi(parsedRequest[2]);
    graphical->_map->initMap(x, y);

}
void Parser::bctCMD(std::vector<std::string> parsedRequest, Graphical *graphical, int opt)
{
        int x = std::stoi(parsedRequest[1]);
        int y = std::stoi(parsedRequest[2]);
        int q0 = std::stoi(parsedRequest[3]);
        int q1 = std::stoi(parsedRequest[4]);
        int q2 = std::stoi(parsedRequest[5]);
        int q3 = std::stoi(parsedRequest[6]);
        int q4 = std::stoi(parsedRequest[7]);
        int q5 = std::stoi(parsedRequest[8]);
        int q6 = std::stoi(parsedRequest[9]);
    if (graphical->_map->_mapElement.size() < (graphical->_map->_xSizeMap / 180) * (graphical->_map->_ySizeMap / 180)) {
        std::string randomNumber = std::to_string(std::rand() % 29);

        // std::string imgpath =  "GRAPHICAL/assets/Tiles/tile_map" + std::string(".png");
        std::string imgpath =  "GRAPHICAL/assets/Tiles/tile_map" + randomNumber + std::string(".png");
        graphical->_map->initNewTuileAtPos(x, y, q0, q1, q2, q3, q4, q5, q6, imgpath);

        } else {
    
            // for (int i = 0; i != graphical->_map->_mapElement.size(); i++) {
            //     if (graphical->_map->_mapElement[i]->_xposTuile == x && graphical->_map->_mapElement[i]->_yposTuile == y) {
            //         graphical->_map->_mapElement[i]->_items->FOOD = q0;
            //         graphical->_map->_mapElement[i]->_items->LINEMATE = q1;
            //         graphical->_map->_mapElement[i]->_items->DERAUMERE = q2;
            //         graphical->_map->_mapElement[i]->_items->SIBURE = q3;
            //         graphical->_map->_mapElement[i]->_items->MENDIANE = q4;
            //         graphical->_map->_mapElement[i]->_items->PHIRAS = q5;
            //         graphical->_map->_mapElement[i]->_items->THYSTAM = q6;
            //     }
            // }
            if (graphical->_map->getTileByXY(x,y) != NULL) {
                graphical->_map->getTileByXY(x,y)->_items->FOOD = q0;
                graphical->_map->getTileByXY(x,y)->_items->LINEMATE = q1;
                graphical->_map->getTileByXY(x,y)->_items->DERAUMERE = q2;
                graphical->_map->getTileByXY(x,y)->_items->SIBURE = q3;
                graphical->_map->getTileByXY(x,y)->_items->MENDIANE = q4;
                graphical->_map->getTileByXY(x,y)->_items->PHIRAS = q5;
                graphical->_map->getTileByXY(x,y)->_items->THYSTAM = q6;
            }
        }

        
}

void Parser::pnwCMD(std::vector<std::string> parsedRequest, Graphical *graphical, int opt)
{
    Player *player = new(Player);
    player->initPlayer(parsedRequest[1], std::stoi(parsedRequest[2]), std::stoi(parsedRequest[3]),
    std::stoi(parsedRequest[4]), std::stoi(parsedRequest[5]), parsedRequest[6], "GRAPHICAL/assets/object/equipe1/up.png");
    graphical->_listPlayer.push_back(player);
}
void Parser::ppoCMD(std::vector<std::string> parsedRequest, Graphical *graphical, int opt)
{
    for (int i = 0; i != graphical->_listPlayer.size();i++) {
        if (parsedRequest[1].compare(graphical->_listPlayer[i]->_uuidPlayer) == 0) {
            graphical->_listPlayer[i]->_xPlayer = std::stoi(parsedRequest[2]) * 180;
            graphical->_listPlayer[i]->_yPlayer = std::stoi(parsedRequest[3]) * 188;
            if (parsedRequest[4].compare("1") == 0)
                 graphical->_listPlayer[i]->_Tplayer.loadFromFile("GRAPHICAL/assets/object/equipe1/up.png");
            if (parsedRequest[4].compare("2") == 0)
                 graphical->_listPlayer[i]->_Tplayer.loadFromFile("GRAPHICAL/assets/object/equipe1/right.png");
            if (parsedRequest[4].compare("3") == 0)
                graphical->_listPlayer[i]-> _Tplayer.loadFromFile("GRAPHICAL/assets/object/equipe1/down.png");
            if (parsedRequest[4].compare("4") == 0)
                graphical->_listPlayer[i]->_Tplayer.loadFromFile("GRAPHICAL/assets/object/equipe1/left.png");
            graphical->_listPlayer[i]->_Splayer.setTexture( graphical->_listPlayer[i]->_Tplayer);
            graphical->_listPlayer[i]->_Splayer.setPosition( graphical->_listPlayer[i]->_xPlayer,  graphical->_listPlayer[i]->_yPlayer);
        }
    }
}
void Parser::pdiCMD(std::vector<std::string> parsedRequest, Graphical *graphical, int opt)
{
    for (int i = 0; graphical->_listPlayer.size() != i; i++) {
        if (graphical->_listPlayer[i]->_uuidPlayer.compare(parsedRequest[1]) == 0 && graphical->_listPlayer.size() != 0) {
            graphical->_listPlayer.erase(graphical->_listPlayer.begin() + i);
            std::cout << graphical->_listPlayer.size() << std::endl;
            break;
        }
    }
}
void Parser::tnaCMD(std::vector<std::string> parsedRequest, Graphical *graphical, int opt){}

void Parser::plvCMD(std::vector<std::string> parsedRequest, Graphical *graphical, int opt){}

void Parser::pinCMD(std::vector<std::string> parsedRequest, Graphical *graphical, int opt)
{
    for (int a = 0; graphical->_listPlayer.size() != a; a++) {
        if (graphical->_listPlayer[a]->_uuidPlayer == parsedRequest[1]) {
            graphical->_listPlayer[a]->_xPlayer = std::stoi(parsedRequest[2]);
            graphical->_listPlayer[a]->_yPlayer = std::stoi(parsedRequest[3]);
            graphical->_listPlayer[a]->inventory->FOOD = std::stoi(parsedRequest[4]);
            graphical->_listPlayer[a]->inventory->LINEMATE = std::stoi(parsedRequest[5]);
            graphical->_listPlayer[a]->inventory->DERAUMERE = std::stoi(parsedRequest[6]);
            graphical->_listPlayer[a]->inventory->SIBURE = std::stoi(parsedRequest[7]);
            graphical->_listPlayer[a]->inventory->MENDIANE = std::stoi(parsedRequest[8]);
            graphical->_listPlayer[a]->inventory->PHIRAS = std::stoi(parsedRequest[9]);
            graphical->_listPlayer[a]->inventory->THYSTAM = std::stoi(parsedRequest[10]);
        }
    }

}

void Parser::pexCMD(std::vector<std::string> parsedRequest, Graphical *graphical, int opt){}

void Parser::pbcCMD(std::vector<std::string> parsedRequest, Graphical *graphical, int opt){}

void Parser::picCMD(std::vector<std::string> parsedRequest, Graphical *graphical, int opt){}

void Parser::pieCMD(std::vector<std::string> parsedRequest, Graphical *graphical, int opt){}

void Parser::pfkCMD(std::vector<std::string> parsedRequest, Graphical *graphical, int opt){}

void Parser::pdrCMD(std::vector<std::string> parsedRequest, Graphical *graphical, int opt){}

void Parser::pgtCMD(std::vector<std::string> parsedRequest, Graphical *graphical, int opt){}

void Parser::enwCMD(std::vector<std::string> parsedRequest, Graphical *graphical, int opt)
{
    for (int a = 0; graphical->_map->_mapElement.size() != a; a++) {
        if (graphical->_map->_mapElement[a]->_xposTuile == std::stoi(parsedRequest[2])
        && graphical->_map->_mapElement[a]->_yposTuile == std::stoi(parsedRequest[3])) {
            graphical->_map->_mapElement[a]->_nbEGGS++;
        }
    }
}

void Parser::eboCMD(std::vector<std::string> parsedRequest, Graphical *graphical, int opt){}

void Parser::ediCMD(std::vector<std::string> parsedRequest, Graphical *graphical, int opt){}

void Parser::sgtCMD(std::vector<std::string> parsedRequest, Graphical *graphical, int opt){}

void Parser::sstCMD(std::vector<std::string> parsedRequest, Graphical *graphical, int opt){}

void Parser::segCMD(std::vector<std::string> parsedRequest, Graphical *graphical, int opt){}

void Parser::smgCMD(std::vector<std::string> parsedRequest, Graphical *graphical, int opt){}

void Parser::sucCMD(std::vector<std::string> parsedRequest, Graphical *graphical, int opt){}

void Parser::sbpCMD(std::vector<std::string> parsedRequest, Graphical *graphical, int opt){}

void Parser::execAllBasicCmd(std::vector<std::string> parsedRequest, Graphical *graphical, int opt)
{
    if (parsedRequest[0].compare("msz") == 0)
        mszCMD(parsedRequest, graphical, opt);
    if (parsedRequest[0].compare("bct") == 0)
        bctCMD(parsedRequest, graphical, opt);
    // if (parseRequest[0] == "tna")
    if (parsedRequest[0].compare("pnw") == 0)
        pnwCMD(parsedRequest, graphical, opt);
    if (parsedRequest[0].compare("ppo") == 0)
        ppoCMD(parsedRequest, graphical, opt);
    if (parsedRequest[0].compare("pdi") == 0) {
        pdiCMD(parsedRequest, graphical, opt);
    }
    if (parsedRequest[0].compare("enw") == 0) {
        enwCMD(parsedRequest, graphical, opt);
    }
    if (parsedRequest[0].compare("pin") == 0) {
        pinCMD(parsedRequest, graphical, opt);
    }

    // if (parseRequest[0] == "plv")
    // if (parseRequest[0] == "pex")
    // if (parseRequest[0] == "pbc")
    // if (parseRequest[0] == "pic")
    // if (parseRequest[0] == "pie")
    // if (parseRequest[0] == "pfk")
    // if (parseRequest[0] == "pdr")
    // if (parseRequest[0] == "pgt")
    // if (parseRequest[0] == "ebo")
    // if (parseRequest[0] == "edi")
    // if (parseRequest[0] == "sgt")
    // if (parseRequest[0] == "sst")
    // if (parseRequest[0] == "seg")
    // if (parseRequest[0] == "smg")
    // if (parseRequest[0] == "suc")
    // if (parseRequest[0] == "sbp")
}