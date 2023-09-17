#include "Reception.hpp"


Reception::Reception()
{
    _pid = fork();
    int status;
        if (_pid != 0)
            pid_t childPid = waitpid(_pid, &status, 0);

}

Reception::~Reception()
{

}

void Reception::Parsing_arg(int ac, char **av)
{
    Reception::timeMultiplier_ = std::stoi(av[1]);
    Reception::cooksPerKitchen_ = std::stoi(av[2]);
    Reception::ingredientReplacementTime_ = std::stoi(av[3]);
}


void afficherVector(std::vector<std::string> vec)
{
    std::cout << "debug sa mere" << std::endl;
    for (size_t i = 0; i != vec.size(); i++) {
        std::string tmp = vec[i];
        std::cout << vec[i] << std::endl;
    }
    std::cout << "=============" << std::endl;
}

std::string convertStrtoMin(std::string str)
{
    for (char& c : str)
        c = std::tolower(c);
    return str;
}

bool checkDigits(const std::string& str)
{
    for (int i = 0; i != str.size() - 1; i++) {
        if (!isdigit(str[i]))
            return false;
    }
    return true;
}

void afficherCommandes(const std::vector<Pizza*>& commandes)
{
    std::cout << "======== Nouvelle commande recu !==============" << std::endl;
    for (const auto& commande : commandes)
    {
        std::cout << "PizzaType: " << commande->_pizzaType << ", ";
        std::cout << "PizzaSize: " << commande->_pizzaSize << ", ";
        std::cout << "Time: " << commande->_time << std::endl;
    }
}

void Reception::createCommandes(std::vector <std::string> cmd)
{
    for (size_t i = 0; i != cmd.size(); i++) {
        Pizza *pizza = new Pizza;
        pizza->_time = 0;
        std::stringstream cmdTab(convertStrtoMin(cmd[i]));
        std::string mot;
        int occur = 0;
        while (cmdTab >> mot) {
            //LA FORET DES IF :)
            if (mot == "regina")
                pizza->_pizzaType = PizzaType::Regina, pizza->_time = 2;
            if (mot == "margarita")
                pizza->_pizzaType = PizzaType::Margarita, pizza->_time = 1;
            if (mot == "americana")
                pizza->_pizzaType = PizzaType::Americana, pizza->_time = 2;
            if (mot == "fantasia")
                pizza->_pizzaType = PizzaType::Fantasia, pizza->_time = 4;
            if (mot == "s")
                pizza->_pizzaSize = PizzaSize::S;
            if (mot == "m")
                pizza->_pizzaSize = PizzaSize::M;
            if (mot == "l")
                pizza->_pizzaSize = PizzaSize::L;
            if (mot == "xl")
                pizza->_pizzaSize = PizzaSize::XL;
            if (mot == "xxl")
                pizza->_pizzaSize = PizzaSize::XXL;
            if (checkDigits(mot.substr(1, mot.size() - 1)) == true && mot[0] == 'x' &&
            mot[1] >= '0' && mot[1] <= '9')
                occur = std::stoi(mot.substr(1, mot.size() - 1));
            for (int j  = 0; j !=  occur; j++)
                _Commandes.push_back(pizza);
        }
    }
}

void Reception::cmdParser(const std::string& cmd)
{
    std::string validCmd;
    std::string tmp;
    std::vector <std::string> cmdTab;
    for (size_t i = 0; i < cmd.size() + 1; i++) {
        if (cmd[i] == ' ') {
            tmp += cmd[i];
            for (; cmd[i] == ' ' ; i++);
        }
        tmp += cmd[i];
    }
    for (size_t i = 0; i < tmp.size() + 1; i++) {
        if (tmp[i] == ';' || i == tmp.size() - 1) {
            for (; tmp[i] == ' ' ; i++);
            if (i == tmp.size() - 1)
                validCmd += tmp[i];
            cmdTab.push_back(validCmd);
            validCmd.clear();
            i+= 2;
        }
        validCmd += tmp[i];
    }
    createCommandes(cmdTab);
    //
    afficherCommandes(_Commandes);
    //
    // _Commandes.clear();
}


void Reception::processPizzaOrder(const std::string& order, Reception *_reception)
{
    std::cout << "======== Prise en charge de la commande =========" << std::endl;
    while (_Commandes.size() > (cooksPerKitchen_ * _kitchens.size() * 2)) {
        Kitchen* newKitchen = new Kitchen;
        newKitchen->newKitchen(cooksPerKitchen_,ingredientReplacementTime_, timeMultiplier_);
        _kitchens.push_back(newKitchen);
    }
    int numKitchens = _kitchens.size();
    int numCommands = _Commandes.size();
    int commandsPerKitchen = numCommands / numKitchens;
    int remainingCommands = numCommands % numKitchens;

    int commandIndex = 0;
    for (int kitchenIndex = 0; kitchenIndex < numKitchens; kitchenIndex++) {
        int numCommandsToSend = commandsPerKitchen;
        if (remainingCommands > 0) {
            numCommandsToSend++;
            remainingCommands--;
        }

        for (int i = 0; i < numCommandsToSend; i++) {
            Pizza* pizza = _Commandes[commandIndex];
            PizzaSerialized serializedPizza;


            commandIndex++;
        }
    }
}

void Reception::start(Reception *_reception)
{
    while (true) {
        std::string command;
        std::cout << "Enter a pizza order (e.g., 'regina XXL x2;'): ";
        std::getline(std::cin, command);

        if (command == "status") {
            std::cout << "status kitchen" << std::endl;
            // displayKitchenStatus();
        } else {
            cmdParser(command);
            processPizzaOrder(command, _reception);
            for (int i = 0; i !=  _kitchens.size(); i++) {
                _kitchens[i]->_clock->start();
                std::cout<< "Cuisine " << i << " is runing since "<<_kitchens[i]->getActiveTime() << " sec."<<std::endl;
            }
        }
    }
}
