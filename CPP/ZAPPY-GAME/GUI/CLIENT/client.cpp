/*
** EPITECH PROJECT, 2023
** client
** File description:
** client
*/

#include "client.hpp"

Client::Client(const std::string &ip, int P)
{
    std::cout << "CLIENT : Constructor" << std::endl;
    _socketId = socket(AF_INET, SOCK_STREAM, 0);
    if (_socketId == -1) {
        std::cerr << "CLIENT : Erreur lors de la création de la socket." << std::endl;
    }
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(P);
    if (inet_pton(AF_INET, ip.c_str(), &(serverAddress.sin_addr)) <= 0) {
        std::cerr << "CLIENT : Adresse IP invalide." << std::endl;
    }
    if (connect(_socketId, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        std::cerr << "Erreur lors de la connexion au serveur." << std::endl;
        exit(1);
    }
    // Configurer le socket en mode non bloquant
    int flags = fcntl(_socketId , F_GETFL, 0);
    fcntl(_socketId, F_SETFL, flags | O_NONBLOCK);
    sendMessage("GUI\n");
    std::string rM = receiveMessage();
    std::cout << "reponse of GUI -> " << rM << std::endl;

}


bool Client::sendMessage(const std::string& message)
{
    // std::cout << "CLIENT : MESSAGE SENDED -> " << message << std::endl;
    if (send(_socketId, message.c_str(), message.size(), 0) < 0) {
        std::cerr << "CLIENT : Erreur lors de l'envoi du message." << std::endl;
        return false;
    }

    return true;
}

        
std::string Client::receiveMessage()
{
    char buffer[1000000];
    memset(buffer, 0, sizeof(buffer));

    fd_set readSet;
    FD_ZERO(&readSet);
    FD_SET(_socketId, &readSet);

    timeval timeout;
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    int ready = select(_socketId + 1, &readSet, nullptr, nullptr, &timeout);
    if (ready < 0) {
        return "FAIL";
    }
    else if (ready == 0) {
        return "TIMEOUT";
    }

    if (FD_ISSET(_socketId, &readSet)) {
        int bytesRead = recv(_socketId, buffer, sizeof(buffer), 0);
        if (bytesRead < 0) {
            return "FAIL";
        }
        else if (bytesRead == 0) {
            return "CLOSED";
        }
        // std::cout << "CLIENT : recv = " << buffer << std::endl;
        // if (bytesRead > 0) {
        //     return std::string(buffer, bytesRead);
        // }
        return std::string(buffer, bytesRead);
    }

    return "FAIL"; // Autre erreur inattendue
}

void Client::closeConnection()
{
    close(_socketId);
}


//          REQUEST             //

std::string Client::MapSizeRequest()
{
    std::string request = "msz\n";
    if (!sendMessage(request)) {
        std::cerr << "CLIENT : request failed" << std::endl;
    }

    std::string mapSize = receiveMessage();
    return mapSize;
}

std::string Client::ContentOfTileRequest()
{
    std::string request = "bct X Y\n";
    if (!sendMessage(request)) {
        std::cerr << "CLIENT : request failed" << std::endl;
    }

    std::string ContentOfTile = receiveMessage();
    return ContentOfTile;
}

std::string Client::ContentOfMapRequest()
{
    std::string request = "mct\n";
    if (!sendMessage(request)) {
        std::cerr << "CLIENT : request failed" << std::endl;
    }

    std::string ContentOfMap = receiveMessage();
    return ContentOfMap;
}

std::string Client::NameOfAllTeamRequest()
{
    std::string request = "tna\n";
    if (!sendMessage(request)) {
        std::cerr << "CLIENT : request failed" << std::endl;
    }

    std::string NameOfAllTeam = receiveMessage();
    return NameOfAllTeam;
}

std::string Client::PlayerPosRequest(std::string uuidPlayer)
{
    std::string request = "ppo " + uuidPlayer + "\n";
    if (!sendMessage(request)) {
        std::cerr << "CLIENT : request failed" << std::endl;
    }

    std::string PlayerPos = receiveMessage();
    return PlayerPos;
}

std::string Client::PlayerLvlRequest(std::string uuidPlayer)
{
    std::string request = "plv " + uuidPlayer + "\n";
    if (!sendMessage(request)) {
        std::cerr << "CLIENT : request failed" << std::endl;
    }

    std::string PlayerLvl = receiveMessage();
    return PlayerLvl;
}

std::string Client::TimeUnitRequest()
{
    std::string request = "sgt\n";
    if (!sendMessage(request)) {
        std::cerr << "CLIENT : request failed" << std::endl;
    }

    std::string TimeUnit = receiveMessage();
    return TimeUnit;
}

std::string Client::TimeUnitModifRequest()     // remplacer T par le timeunit 
{
    std::string request = "sst T\n";
    if (!sendMessage(request)) {
        std::cerr << "CLIENT : request failed" << std::endl;
    }

    std::string TimeUnitModif = receiveMessage();
    return TimeUnitModif;
}
