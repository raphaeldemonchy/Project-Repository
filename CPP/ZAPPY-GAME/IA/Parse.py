##
## EPITECH PROJECT, 2022
## B-YEP-400-MAR-4-1-zappy-mehdi.bouguerra
## File description:
## Parse.py
##
## AI
## File description:
## Parse.py
##

import sys

class ParsingArgs:
    def __init__(self):
        if len(sys.argv) == 2 and sys.argv[1] == "-help":
            ParsingArgs.printHelp(0)

    def printHelp(ret):
        #print("Usage")
        sys.exit(ret)

    def parseArgs(self):
        if len(sys.argv) != 3 and len(sys.argv) != 5 and len(sys.argv) != 7:
            sys.exit("Invalid arguments")

        ip = None
        port = None
        name = None

        for i in range(1, len(sys.argv), 2):
            if sys.argv[i] == "-h":
                ip = sys.argv[i+1]
            elif sys.argv[i] == "-n":
                name = sys.argv[i+1] + "\n"
            elif sys.argv[i] == "-p":
                port = int(sys.argv[i+1])

        if ip is None and port is None and name is None:
            ParsingArgs.printHelp(-1)

        if ip is None:
            ip = "localhost"

        if port is None:
            port = 4242

        if name is None:
            ParsingArgs.printHelp(-1)

        return ip, port, name