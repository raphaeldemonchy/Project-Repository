##
## EPITECH PROJECT, 2022
## B-YEP-400-MAR-4-1-zappy-mehdi.bouguerra
## File description:
## ConnectAIToServer.py
##

import socket
import sys

def ConnectSocketToServer(ip, port, name):
    try:
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        sock.connect((ip, port))
        Running = True
        i = 0
        AllData = ""
        # sock.send("AI\n".encode('utf-8'))
        while Running:
            data = sock.recv(1024)
            if not data:
                return
            else:
                if data.decode('utf-8') == "ko\n":
                    sys.exit(0)
                if data.decode('utf-8') == "dead\n":
                    print("dead\n")
                    sys.exit(0)
            message = name
            if i < 1:
                sock.sendall(message.encode())
            AllData += data.decode('utf-8')
            i += 1
            if i == 2:
                Running = False
                return AllData, sock

    except ConnectionRefusedError:
        print("Error: connection refused")