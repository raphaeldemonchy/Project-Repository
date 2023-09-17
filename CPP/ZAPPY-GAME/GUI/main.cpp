/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "GUI/GUI.hpp"
#include "CLIENT/client.hpp"
#include "PARSER/parser.hpp"
#include <thread>

bool isRunning;


// void connect(Client *client, int P, std::string adresse)
// {
//     if (!client->connectAndIdentify(adresse, P, "GUI\n")) {
//         std::cout << "CLIENT : Erreur de connexion au serveur" << std::endl;
//     } else
//         isRunning = true;
// }

void RequestBasicInfo(Client *client, Parser *parser, Graphical *graphical)
{
    client->sendMessage("msz\n");
    parser->myBasicParser(client->receiveMessage(), graphical);
    client->sendMessage("mct\n");
    while (true) {
        parser->myBasicParser(client->receiveMessage(), graphical);
    }
}

void runClient(Parser *parser, Graphical *graphical, int P, std::string adresse)
{
    Client FluxClient(adresse, P);
    graphical->initClient(&FluxClient);

    std::string receivedMessage;
    while (isRunning != false) {
        receivedMessage = graphical->_FluxClient->receiveMessage();
        if (receivedMessage != "FAIL" && receivedMessage != "TIMEOUT") {
            parser->myParser(receivedMessage, graphical);
        }
    // receivedMessage.clear();
        // parser->pushRequestFLUX(receivedMessage);
        // std::cout << "CLIENT : Message received from server: " << receivedMessage << std::endl;
    }
}

void runBasicClient(Parser *parser, Graphical *graphical, int P, std::string adresse)
{
    Client BasicClient(adresse, P);
    BasicClient.sendMessage("msz\n");
    BasicClient.sendMessage("mct\n");
    std::string receivedMessage;
    while (receivedMessage != "TIMEOUT") {
        receivedMessage = BasicClient.receiveMessage();
        // sleep(1);
        // std::cout << "receivedMessage = " << receivedMessage << std::endl; 
        if (receivedMessage != "FAIL")
            parser->myBasicParser(receivedMessage, graphical);
        // std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // Ajouter une pause de 100 millisecondes
    }
    isRunning = true;
}

int main(int ac, char **av)
{
    std::srand(std::time(0));
    GUI *gui = new(GUI);
    Parser *parser = new(Parser);

    gui->run();             //
    isRunning = false;


    int P = std::stoi(gui->getPort());
    std::string adresse = gui->getName();
    // int P = std::stoi(av[1]);
    // std::string adresse = "127.0.0.1";

    Graphical *graphical = new Graphical(P, adresse);


    std::thread clientBasicThread(runBasicClient, parser, graphical, P, adresse);

    clientBasicThread.join();
    std::thread clientThread(runClient, parser, graphical, P, adresse);


    if (isRunning == true)
        graphical->runGraphical();
        std::cout << "maintenabt on peut run" << std::endl;


    // Attendre que le thread de la boucle de requête se termine
    clientThread.join();


}