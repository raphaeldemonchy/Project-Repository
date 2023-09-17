/*
** EPITECH PROJECT, 2023
** Ipc
** File description:
** Ipc
*/

#include "Ipc.hpp"

Ipc::Ipc()
{
    _context = zmq::context_t(1);

    _context(1),
    _sender(_context, zmq::socket_type::push),
    _receiver(_context, zmq::socket_type::pull)
}

Ipc::~Ipc()
{
    _sender.close();
    _receiver.close();
    _context.close();
    _context2.close();
}

 void Ipc::createIpcReceiver()
 {
    _receiver = zmq::socket_t(_context, zmq::socket_type::pull);
    std::cout << "receiver Initialized : OK" << std::endl;
 }

 
void Ipc::createIpcSender()
{
    _sender = zmq::socket_t(_context2, zmq::socket_type::push);
    std::cout << "sender Initialized : OK" << std::endl;
    
}
void Ipc::connecteIpcSender(std::string port)
{
    std::string adresse = "tcp://localhost:" + port;
    // _receiver.connect(adresse);
    // std::cout << "Receiver connected : OK" << std::endl;
    _sender.connect(adresse);
    std::cout << "Sender connected : OK" << std::endl;

}

void Ipc::initIpcReceiver(std::string port)
{
    
}


void Ipc::sendRequest(std::string request)
{
    std::cout << "FUNC sendRequest : arg = " << request << std::endl;
    zmq::message_t message(request.size());
    memcpy(message.data(), request.data(), request.size());
    _sender.send(message, zmq::send_flags::dontwait);
    std::cout << "Request sent: " << request << std::endl;
}

std::string Ipc::receiveRequest()
{
    zmq::message_t cmdReceived;

    zmq::recv_result_t result = _receiver.recv(cmdReceived, zmq::recv_flags::dontwait);
    if (!result)
    {
        int error = zmq_errno();
        std::cerr << "Failed to receive message: " << zmq_strerror(error) << std::endl;
        std::string messageStr(static_cast<char*>(cmdReceived.data()), cmdReceived.size());
        std::cout << "cmdReceived : " << messageStr << std::endl; 
        return "";
    }
    else
    {
        std::string request(static_cast<char*>(cmdReceived.data()), cmdReceived.size());
        std::cout << "Received message: " << request << std::endl;
        return request;
    }

    std::string request(static_cast<char*>(cmdReceived.data()), cmdReceived.size());
    std::cout << "Received message: " << request << std::endl;
    return request;

}

void Ipc::bindIPC(std::string adresse)
{
    std::cout << "adresse bind IPC : " << adresse << std::endl;
    _receiver.bind(adresse);

}



    // ///////////////////////////////////////////////////////////////////////////
           // zmq::context_t* _context;
        // zmq::socket_t* _kitchenSocket;
                    //INITIALIZATION DES VARIBLE SOCKET de reception
    // _context = new zmq::context_t(1);

    // _kitchenSocket = new zmq::socket_t(*_context, zmq::socket_type::push);
    // _kitchenSocket->bind("tcp://*:4800");
    // ///////////////////////////////////////////////////////////////////////////
            // sendCommandToKitchen : 
    
    // void Reception::sendCommandToKitchen(const std::string& command)
    // {
    //     zmq::message_t message(command.size());
    //     std::cout << "commande recu dans reception :: ->" << command << std::endl;

    //     memcpy(message.data(), command.data(), command.size());

    //     zmq::send_result_t result = _kitchenSocket->send(message, zmq::send_flags::none);
  
    // }

    // ///////////////////////////////////////////////////////////////////////////
                    //KITCHEN -> recevoir les command de la socket push de la reception
    
    // void Kitchen::receiveCommandFromReception()
// {

//     zmq::message_t message;

//     zmq::recv_result_t result = _receptionSocket->recv(message, zmq::recv_flags::none);

//     std::cout << "je rentre dans la chate at me re" << std::endl;
//     std::string command(static_cast<char*>(message.data()), message.size());

//     std::cout << "COMMAND RECU -> "<< command << std::endl;
//     // Traiter la commande reçue...

// }


        // création d'une socket pour chaque cuisine 

         // zmq::socket_t _receptionSocket(*_context, zmq::socket_type::pull);
        // _receptionSocket.connect("tcp://localhost:0"); // Se connecter à la réception

            // zmq::socket_t _receptionSocket(*_context, zmq::socket_type::pull);
            // std::cout << "inf?" << std::endl;
            // _receptionSocket.connect("tcp://localhost:4800"); // Se connecter à la réception
