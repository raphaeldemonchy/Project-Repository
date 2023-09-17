/*
** EPITECH PROJECT, 2023
** client
** File description:
** client
*/

#pragma once

#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/select.h>
#include <unistd.h>

class Client {
    private:
        int _socketId;
        sockaddr_in serverAddress;
        int port;

    public:
        Client(const std::string &ip, int P);

        bool sendMessage(const std::string& message);
        std::string receiveMessage();

        void closeConnection();

        //      REQUEST     //
        std::string MapSizeRequest();
        std::string ContentOfTileRequest();
        std::string ContentOfMapRequest();
        std::string NameOfAllTeamRequest();

        std::string PlayerPosRequest(std::string uuidPlayer);
        std::string PlayerLvlRequest(std::string uuidPlayer);

        std::string TimeUnitRequest();
        std::string TimeUnitModifRequest();




};

