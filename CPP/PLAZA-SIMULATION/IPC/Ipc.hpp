/*
** EPITECH PROJECT, 2023
** Ipc
** File description:
** Ipc
*/

#pragma once
#include <zmq.hpp>
#include <string>
#include <iostream>
#include <vector>


class Ipc 
{
    public:
    Ipc();
    ~Ipc();
    void createIpcReceiver();
    void createIpcSender();
    void connecteIpcSender(std::string port);
    void initIpcReceiver(std::string port);
    void sendRequest(std::string request);
    std::string receiveRequest();
    void bindIPC(std::string adresse);

    zmq::context_t _context;
    zmq::socket_t _sender;
    zmq::socket_t _receiver;


};


class Sender : Ipc
{
    
};