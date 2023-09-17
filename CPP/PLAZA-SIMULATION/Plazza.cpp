#include "Plazza.hpp"
#include "RECEPTION/Reception.hpp"
#include "IPC/Ipc.hpp"

int main(int argc, char **argv)
{
    Reception *_reception = new Reception;
    _reception->Parsing_arg(argc, argv);
    _reception->start(_reception);
    // std::string port = argv[1];
    // std::string adrr = "ipc://localhost:";
    // Ipc *receiver = new Ipc;
    // Ipc *sender = new Ipc;
    // receiver->createIpcReceiver();
    // sender->createIpcSender();
    // receiver->bindIPC(adrr + port);
    // sender->connecteIpcSender(port);

    // // while(1) {
    //     sender->sendRequest("regina");
    //     std::cout << "request sended : OK" << std::endl << "request received -> " << receiver->receiveRequest() << std::endl;

    // // }
    return 0;
}