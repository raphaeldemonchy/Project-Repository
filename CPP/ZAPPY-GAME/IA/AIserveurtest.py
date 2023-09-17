import Parse
import ConnectAIToServer
import sys
import threading
import uuid

thread_string = ""

class AIAction:
    def generate_unique_string():
        unique_string = str(uuid.uuid4())
        return unique_string
    def ParseServerCmdLook(Level, SockAI, Rsp):
        # print("Rsp -> ", Rsp)
        # print("ParseLookLevel: %d\n" % Level)
        if (Rsp == "dead\n"):
            print("dead on look\n")
            sys.exit(0)
        if "message" in Rsp:
            AIAction.BroadTraiter(Level, Rsp, SockAI)
        Delete = "123456789fod, linematrusbphy"
        check = "[]\n123456789,fodlinematrusbphy "
        for el in Rsp:
            if el not in check:
                print("dead new dead last dead look\n")
                SockAI.close()
                sys.exit(0)
        tmp = "".join(char for char in Rsp if char in Delete)
        Rsplit = tmp.split(",")
        # print("look splited -> a la ligne\n\n", Rsplit)
        return Rsplit

    def Look(Level, SockAI):
        # print("Look lvl:%d\n" % Level)
        msg = "Look\n"
        try:
            SockAI.sendall(msg.encode())
            ServerResponse = SockAI.recv(1024)
        except ConnectionError as e:
            print("dead new dead\n")
            SockAI.close()
            sys.exit(0)
        sr2 = ServerResponse.decode('utf-8')
        while "message" in sr2:
            AIAction.BroadTraiter(Level, sr2, SockAI)
            try:
                ServerResponse = SockAI.recv(1024)
            except ConnectionError as e:
                print("dead new dead\n")
                SockAI.close()
                sys.exit(0)
            sr2 = ServerResponse.decode('utf-8')
        if (ServerResponse.decode('utf-8') == "dead\n"):
            print("dead on look\n")
            SockAI.close()
            sys.exit(0)
        return ServerResponse.decode('utf-8')

    def ParseServerCmdInv(Level, Rsp, SockAI):
        # print("ParseServerCmdInv lvl:%d\n" % Level)
        while "message" in Rsp:
            AIAction.BroadTraiter(Level, Rsp, SockAI)
            try:
                Rsp = SockAI.recv(1024)
            except ConnectionError as e:
                print("dead new dead\n")
                SockAI.close()
                sys.exit(0)
        if (Rsp == "dead\n"):
            print("dead on parseinventory\n")
        Delete = "[]\nfodlinematrusbphy "
        # print("\n\nINV --> %s\n\n" % Rsp)
        tmp = "".join(char for char in Rsp if char not in Delete)
        Rsplit = tmp.split(",")
        # print("Rsplit value: %s\n" % Rsplit)
        for el in Rsplit:
            if el.isnumeric() == False:
                print("dead new dead last dead\n")
                SockAI.close()
                sys.exit(0)
        return Rsplit

    def Inventory(Level, SockAI):
        # print("Inventory lvl:%d\n" % Level)
        msg = "Inventory\n"
        try:
            SockAI.sendall(msg.encode())
            ServerResponse = SockAI.recv(1024)
        except ConnectionError as e:
            print("dead new dead\n")
            SockAI.close()
            sys.exit(0)
        sr2 = ServerResponse.decode('utf-8')
        while "message" in sr2:
            AIAction.BroadTraiter(Level, sr2, SockAI)
            try:
                ServerResponse = SockAI.recv(1064)
            except ConnectionError as e:
                print("dead new dead\n")
                SockAI.close()
                sys.exit(0)
        if (ServerResponse.decode('utf-8') == "dead\n"):
            print("dead on inventory\n")
            SockAI.close()
            sys.exit(0)
        parsed = AIAction.ParseServerCmdInv(Level, ServerResponse.decode('utf-8'), SockAI)
        return parsed

    def Fork(Level, SockAI):
        # print("Fork lvl:%d\n" % Level)
        msg = "Fork\n"
        try:
            SockAI.sendall(msg.encode())
            Rsp = SockAI.recv(1024)
        except ConnectionError as e:
            print("dead new dead\n")
            SockAI.close()
            sys.exit(0)
        # print("send : ", msg)
        Rsp2 = Rsp.decode('utf-8')
        # print("rsp fork :", Rsp2)
        while "message" in Rsp2:
            AIAction.BroadTraiter(Level, Rsp2, SockAI)
            try:
                Rsp = SockAI.recv(1024)
            except ConnectionError as e:
                print("dead new dead\n")
                SockAI.close()
                sys.exit(0)
            Rsp2 = Rsp.decode('utf-8')
        if (Rsp.decode('utf-8') == "dead\n"):
            print("dead on fork\n")
            SockAI.close()
            sys.exit(0)
        # print("Received: ", Rsp.decode('utf-8'))
        thread = threading.Thread(target=initAi)
        thread.start()

    def SetObject(Level, SockAI, Object_):
        # print("Setting object lvl: %d\n" % Level)
        msg = "Set " + Object_
        try:
            SockAI.sendall(msg.encode())
            Rsp = SockAI.recv(1024)
        except ConnectionError as e:
            print("dead new dead\n")
            SockAI.close()
            sys.exit(0)
        Rsp2 = Rsp.decode('utf-8')
        if "message" in Rsp2:
            AIAction.BroadTraiter(Level, Rsp2, SockAI)
            try:
                Rsp = SockAI.recv(1064)
            except ConnectionError as e:
                print("dead new dead\n")
                SockAI.close()
                sys.exit(0)
            Rsp2 = Rsp.decode('utf-8')
        if (Rsp.decode('utf-8') == "dead\n"):
            print("dead on setObject\n")
            SockAI.close()
            sys.exit(0)

    def Incantation(Level, SockAI):
        # print("incantation lvl: %d\n" % Level)
        msg = "Incantation\n"
        try:
            SockAI.sendall(msg.encode())
            check = SockAI.recv(1024)
        except ConnectionError as e:
            print("dead new dead\n")
            SockAI.close()
            sys.exit(0)
        check2 = check.decode('utf-8')
        while "message" in check2:
            AIAction.BroadTraiter(Level, check2, SockAI)
            try:
                check = SockAI.recv(1024)
            except ConnectionError as e:
                print("dead new dead\n")
                SockAI.close()
                sys.exit(0)
            check2 = check.decode('utf-8')
        if (check.decode('utf-8') == "dead\n"):
            print("dead on incant1\n")
            SockAI.close()
            sys.exit(0)
        if check.decode('utf-8') == "ko\n":
            return False
        try:
            Rsp = SockAI.recv(1024)
        except ConnectionError as e:
            print("dead new dead\n")
            SockAI.close()
            sys.exit(0)
        if (Rsp.decode('utf-8') == "dead\n"):
            print("dead on incant2\n")
            SockAI.close()
            return
        Rsp2 = Rsp.decode('utf-8')
        while "message" in Rsp2:
            AIAction.BroadTraiter(Level, Rsp2, SockAI)
        return True

    def CoNbr(Level, SockAI):
        # print("CoNbr level: %d\n" % Level)
        msg = "Connect_nbr\n"
        try:
            SockAI.sendall(msg.encode())
            Rsp = SockAI.recv(1024)
        except ConnectionError as e:
            print("dead new dead\n")
            SockAI.close()
            sys.exit(0)
        # print("send: ", msg)
        Rsp2 = Rsp.decode('utf-8')
        while "message" in Rsp2:
            AIAction.BroadTraiter(Level, Rsp2, SockAI)
            try:
                Rsp = SockAI.recv(1024)
            except ConnectionError as e:
                print("dead new dead\n")
                SockAI.close()
                sys.exit(0)
            Rsp2 = Rsp.decode('utf-8')
        if (Rsp.decode('utf-8') == "dead\n"):
            print("dead on connectnbr\n")
            SockAI.close()
            sys.exit(0)
        # print("recv: ", Rsp.decode('utf-8'))
        return Rsp2

    def Right(Level, SockAI):
        # print("Right level: %d\n" % Level)
        msg = "Right\n"
        try:
            SockAI.sendall(msg.encode())
            ServerResponse = SockAI.recv(1024)
        except ConnectionError as e:
            print("dead new dead\n")
            SockAI.close()
            sys.exit(0)
        sr2 = ServerResponse.decode('utf-8')
        while "message" in sr2:
            AIAction.BroadTraiter(Level, sr2, SockAI)
            try:
                ServerResponse = SockAI.recv(1024)
            except ConnectionError as e:
                print("dead new dead\n")
                SockAI.close()
                sys.exit(0)
            sr2 = ServerResponse.decode('utf-8')
        if ServerResponse.decode('utf-8') == "ok\n":
            return
        if (ServerResponse.decode('utf-8') == "dead\n"):
            print("dead on right\n")
            SockAI.close()
            sys.exit(0)
        else:
            sys.exit(-1)

    def Left(Level, SockAI):
        # print("Left level: %d\n" % Level)
        msg = "Left\n"
        try:
            SockAI.sendall(msg.encode())
            ServerResponse = SockAI.recv(1024)
        except ConnectionError as e:
            print("dead new dead\n")
            SockAI.close()
            sys.exit(0)
        ServerResponse2 = ServerResponse.decode('utf-8')
        while "message" in ServerResponse2:
            AIAction.BroadTraiter(Level, ServerResponse2, SockAI)
            try:
                ServerResponse = SockAI.recv(1024)
            except ConnectionError as e:
                print("dead new dead\n")
                SockAI.close()
                sys.exit(0)
            ServerResponse2 = ServerResponse.decode('utf-8')
        if ServerResponse.decode('utf-8') == "dead\n":
            print("dead on left\n")
            SockAI.close()
            sys.exit(0)
        if ServerResponse.decode('utf-8') == "ok\n":
            return
        else:
            sys.exit(-1)

    def TakeObject(Level, Object, SockAI):
        # print("take object: %d\n" Level)
        msg = "Take " + Object
        try:
            SockAI.sendall(msg.encode())
            ServerResponse = SockAI.recv(1024)
        except ConnectionError as e:
            print("dead new dead\n")
            SockAI.close()
            sys.exit(0)
        sr2 = ServerResponse.decode('utf-8')
        while "message" in sr2:
            AIAction.BroadTraiter(Level, sr2, SockAI)
            try:
                ServerResponse = SockAI.recv(1024)
            except ConnectionError as e:
                print("dead new dead\n")
                SockAI.close()
                sys.exit(0)
            sr2 = ServerResponse.decode('utf-8')
        if "message" in sr2:
            print("dead on takeobject\n")
            SockAI.close()
            sys.exit(0)
        if ServerResponse.decode('utf-8') == "ok\n":
            return

    def CheckPlayer(src, nbplayer):
        if isinstance(src, str):
            word_to_count = "player"
            count = src.count(word_to_count)
            if count >= nbplayer:
                return 0
            return 1
        else:
            return -1

    def Forward(Level, SockAI):
        # print("Forwarding level: %d\n" % Level)
        msg = "Forward\n"
        try:
            SockAI.sendall(msg.encode())
            ServerResponse = SockAI.recv(1024)
        except ConnectionError as e:
            print("dead new dead\n")
            SockAI.close()
            sys.exit(0)
        sr2 = ServerResponse.decode('utf-8')
        while "message" in sr2:
            AIAction.BroadTraiter(Level, sr2, SockAI)
            try:
                ServerResponse = SockAI.recv(1024)
            except ConnectionError as e:
                print("dead new dead\n")
                SockAI.close()
                sys.exit(0)
            sr2 = ServerResponse.decode('utf-8')
        if (ServerResponse.decode('utf-8') == "dead\n"):
            print("dead on forward\n")
            SockAI.close()
            sys.exit(0)
        if ServerResponse.decode('utf-8') == "ok\n":
            return
        else:
            SockAI.close()
            sys.exit()

    def BroadCastInc(Level, Object, SockAI):
        N = 0
        msg = "Broadcast " + Object
        try:
            SockAI.sendall(msg.encode())
            rsp = SockAI.recv(1024)
        except ConnectionError as e:
            print("dead new dead\n")
            SockAI.close()
            sys.exit(0)
        if "ok\n" in rsp.decode('utf-8'):
            try:
                print("OUIIIIIIIIIIIIIIIIIIIIII\n")
                rsp = SockAI.recv(1024)
                print("NOOOOONNNNNNNNNNNNNNNNNNNNNNNN\n")
            except ConnectionError as e:
                print("ntm\n")
                print("dead new dead\n")
                SockAI.close()
                sys.exit(0)
            while "message" in rsp.decode('utf-8'):
                if "2:I search you" in rsp.decode('utf-8'):
                    N += 1
                if N == 1:
                    rsplit = rsp.decode('utf-8').split(",")
                    newstring = rsplit[2]
                    deleteMsg = "message "
                    position = "".join(char for char in rsplit[0] if char not in deleteMsg)
                    N += 1
                    msg = "Broadcast 2:Come, " + newstring + "\n"
                    try:
                        SockAI.sendall(msg.encode())
                        rsp = SockAI.recv(1024)
                        while "message" in rsp.decode('utf-8'):
                            try:
                                rsp = SockAI.recv(1024)
                            except ConnectionError as e:
                                print("dead new dead\n")
                                SockAI.close()
                                sys.exit(0)
                    except ConnectionError as e:
                        print("dead new dead\n")
                        SockAI.close()
                        sys.exit(0)
                try:
                    rsp = SockAI.recv(1024)
                    while "message" in rsp.decode('utf-8'):
                        try:
                            rsp = SockAI.recv(1024)
                        except ConnectionError as e:
                            print("dead new dead\n")
                            SockAI.close()
                            sys.exit(0)
                except ConnectionError as e:
                    print("dead new dead\n")
                    SockAI.close()
                    sys.exit(0)
        else:
            while "message" in rsp.decode('utf-8'):
                if "2:I search you" in rsp.decode('utf-8'):
                    N += 1
                if N == 1:
                    rsplit = rsp.decode('utf-8').split(",")
                    newstring = rsplit[2]
                    deleteMsg = "message "
                    position = "".join(char for char in rsplit[0] if char not in deleteMsg)
                    N += 1
                msg = "Broadcast Come, " + newstring + "\n"
                try:
                    SockAI.sendall(msg.encode())
                    rsp = SockAI.recv(1024)
                    while "message" in rsp.decode('utf-8'):
                        try:
                            rsp = SockAI.recv(1024)
                            if (rsp.decode('utf-8').recv(1064) == "dead/n"):
                                SockAI.close()
                                sys.exit(0)
                        except ConnectionError as e:
                            print("dead new dead\n")
                            SockAI.close()
                            sys.exit(0)
                except ConnectionError as e:
                    print("dead new dead\n")
                    SockAI.close()
                    sys.exit(0)
        print("newstring: ", newstring)
        AIAction.BroadFounder(newstring, position, SockAI, Level)
        return

    def BroadFounder(newstring, position, SockAI, Level):
        while (position != '0'):
            print("turentres ?")
            look_ = AIAction.ParseServerCmdLook(3, SockAI, AIAction.Look(3, SockAI))
            count = look_[0].count("food")
            if count > 0:
                while count != 0:
                    AIAction.TakeObject(2, "food\n", SockAI)
                    count -= 1
            if position == '1':
                AIAction.Forward(2, SockAI)
            if position == '2':
                AIAction.Forward(2, SockAI)
            if position == '3':
                AIAction.Left(2, SockAI)
            if position == '4':
                AIAction.Left(2, SockAI)
            if position == '5':
                AIAction.Left(2, SockAI)
                AIAction.Left(2, SockAI)
            if position == '6' or position[0] == '7' or position[0] == '8':
                AIAction.Right(2, SockAI)
            if position == '0':
                return
            msg = "Broadcast 2:" + thread_string + "\n"
            try:
                SockAI.sendall(msg.encode())
                print("msg : ", msg)
                ServerResponse = SockAI.recv(1024)
                while "message" in ServerResponse.decode('utf-8'):
                    try:
                        ServerResponse = SockAI.recv(1024)
                    except ConnectionError as e:
                        print("dead new dead\n")
                        SockAI.close()
                        sys.exit(0)
            except ConnectionError as e:
                print("dead new dead\n")
                SockAI.close()
                sys.exit(0)
        return

    def BroadCast(Level, Object, SockAI):
        N = 0
        # print("Broadcasting level: %d\n" % Level)
        global thread_string
        msg = "Broadcast " + Object
        try:
            SockAI.sendall(msg.encode())
            rsp = SockAI.recv(1024)
        except ConnectionError as e:
            print("dead new dead\n")
            SockAI.close()
            sys.exit(0)
        if rsp.decode('utf-8') == "ok\n":
            return
        print("rsp :    ", rsp.decode('utf-8') + "fin")
        # print("sending broadcast: ", msg)
        if (rsp.decode('utf-8') == "dead\n"):
            print("dead on broadcast : %s\n" % Object)
            SockAI.close()
            sys.exit(0)
        # if (rsp.decode('utf-8') == "ok\n"):
        #     return
        while "message" in rsp.decode('utf-8'):
            AIAction.BroadTraiter(Level, rsp.decode('utf-8'), SockAI)
            if thread_string in rsp.decode('utf-8'):
                # print(thread_string)
                N += 1
            try:
                rsp = SockAI.recv(1024)
            except ConnectionError as e:
                print("dead new dead\n")
                SockAI.close()
                sys.exit(0)
            if (rsp.decode('utf-8') == "dead\n"):
                print("dead on broadcast : %s\n" % Object)
                SockAI.close()
                sys.exit(0)
            if (rsp.decode('utf-8') == "ok\n"):
                try:
                    rsp = SockAI.recv(1024)
                except ConnectionError as e:
                    print("dead new dead\n")
                    SockAI.close()
                    sys.exit(0)
        print("NTMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM")
        if N > 1:
            print("oui1")
            AIAction.JoinPlayer(Level, rsp.decode('utf-8'), SockAI)
            return
        # print("broad rsp: ", rsp.decode('utf-8'))

    def JoinPlayer(Level, Object, SockAI):
        print("level = ", Object)
        global thread_string
        Split = Object.split(",")
        deleteMsg = "message "
        position = "".join(char for char in Split[0] if char not in deleteMsg)
        while (position[0] != '0' and Split[0][0] == Level):
            print("dedans?")
            look_ = AIAction.ParseServerCmdLook(3, SockAI, AIAction.Look(3, SockAI))
            count = look_[0].count("food")
            if count > 0:
                while count != 0:
                    AIAction.TakeObject(2, "food\n", SockAI)
                    count -= 1
            if position[0] == '1':
                AIAction.Forward(2, SockAI)
            if position[0] == '2':
                AIAction.Forward(2, SockAI)
            if position[0] == '3':
                AIAction.Left(2, SockAI)
            if position[0] == '4':
                AIAction.Left(2, SockAI)
            if position[0] == '5':
                AIAction.Left(2, SockAI)
                AIAction.Left(2, SockAI)
            if position[0] == '6' or position[0] == '7' or position[0] == '8':
                AIAction.Right(2, SockAI)
            if position[0] == '0' and Split[1][0] == Level:
                return
            msg = "Broadcast 2:" + thread_string + "\n"
            try:
                SockAI.sendall(msg.encode())
                ServerResponse = SockAI.recv(1024)
                print("msg : ", msg)
                while "message" in ServerResponse.decode('utf-8'):
                    try:
                        ServerResponse = SockAI.recv(1024)
                    except ConnectionError as e:
                        print("dead new dead\n")
                        SockAI.close()
                        sys.exit(0)
            except ConnectionError as e:
                print("dead new dead\n")
                SockAI.close()
                sys.exit(0)

    def BroadLvl2(Object, SockAI):
        global thread_string
        # print("broadlvl2\n")
        # print("IN BROAD LVL2 --> ", Object)
        Split = Object.split(",")
        deleteMsg = "message "
        position = "".join(char for char in Split[0] if char not in deleteMsg)
        crewMsg = Split[1]
        searchYou = "2:I search you," + thread_string + "\n"
        # print(thread_string)
        # print("Obj = ", crewMsg)
        if "2:ComeCrew" in Object:
            AIAction.BroadCast(2, searchYou, SockAI)
            if position[0] == '1':
                p = "player"
                f = "food"
                i = 0
                look_ = AIAction.ParseServerCmdLook(2, SockAI, AIAction.Look(2, SockAI))
                print("I see on broad --> ", look_)
                if f in look_[0]:
                    AIAction.TakeObject(2, "food\n", SockAI)
                    AIAction.Forward(2, SockAI)
                    if f in look_[2]:
                        AIAction.TakeObject(2, "food\n", SockAI)
                    if p in look_[2]:
                        AIAction.BroadCast(2, "2:Let's go?, broad\n", SockAI)
                    return
                if p in look_[6]:
                    AIAction.Forward(2, SockAI)
                    if f in look_[2]:
                        AIAction.TakeObject(2, "food\n", SockAI)
                        AIAction.Forward(2, SockAI)
                    if f in look_[6]:
                        AIAction.TakeObject(2, "food\n", SockAI)
                        AIAction.BroadCast(2, "2:Let's go?, broad\n", SockAI)
                        return
                    AIAction.Forward(2, SockAI)
                    AIAction.Forward(2, SockAI)
                    i+=1
        if position[0] == '2':
            AIAction.Forward(2, SockAI)
        if position[0] == '3':
            AIAction.Left(2, SockAI)
        if position[0] == '4':
            AIAction.Left(2, SockAI)
        if position[0] == '5':
            AIAction.Left(2, SockAI)
            AIAction.Left(2, SockAI)
        if position[0] == '6' or position[0] == '7' or position[0] == '8':
            AIAction.Right(2, SockAI)
        if position[0] == '0':
            AIAction.SetObject(2, SockAI, "linemate\n")
            AIAction.SetObject(2, SockAI, "deraumere\n")
            AIAction.SetObject(2, SockAI, "sibur\n")
            if AIAction.Incantation(2, SockAI) == True:
                print("incantation lvl2->lvl3!!!\n")
                return
        # if "2:Let's go?" in Object:
        #     if position == "0":
        #         AIAction.SetObject(2, SockAI, "linemate\n")
        #         AIAction.SetObject(2, SockAI, "deraumere\n")
        #         AIAction.SetObject(2, SockAI, "sibur\n")
        #         if AIAction.Incantation(2, SockAI) == True:
        #             print("incantation lvl2->lvl3!!!\n")
        # else:
        #     AIAction.BroadCast(2, "2:I search you again, broad\n", SockAI)

    def BroadLvl3(Object, SockAI):
        # print("broadlvl3\n")
        # print("IN BROAD LVL3 --> ", Object)
        Split = Object.split(",")
        deleteMsg = "message "
        position = "".join(char for char in Split[0] if char not in deleteMsg)
        crewMsg = Split[1]
        # print("crewMsg = ", crewMsg)
        # if "3:imlvl3" in Object:
        #     return
        if "3:ComeCrew" in Object or "3:I search you" in Object:
            AIAction.BroadCast(3, "3:I search you, broad\n", SockAI)
            if position[0] == '1':
                p = "player"
                f = "food"
                i = 0
                while i < 5:
                    look_ = AIAction.ParseServerCmdLook(3, SockAI, AIAction.Look(3, SockAI))
                    print("I see on broad --> ", look_)
                    if f in look_[0]:
                        AIAction.TakeObject(3, "food\n", SockAI)
                    if p in look_[2]:
                        AIAction.Forward(3, SockAI)
                        if f in look_[2]:
                            AIAction.TakeObject(3, "food\n", SockAI)
                        AIAction.BroadCast(3, "3:Let's go?, broad\n", SockAI)
                        return
                    if p in look_[6]:
                        AIAction.Forward(3, SockAI)
                        if f in look_[2]:
                            AIAction.TakeObject(3, "food\n", SockAI)
                        AIAction.Forward(3, SockAI)
                        if f in look_[6]:
                            AIAction.TakeObject(3, "food\n", SockAI)
                        AIAction.BroadCast(3, "3:Let's go?, broad\n", SockAI)
                        return
                    AIAction.Forward(3, SockAI)
                    AIAction.Forward(3, SockAI)
                    i+=1
        if position[0] == '2':
            AIAction.Forward(3, SockAI)
        if position[0] == '3':
            AIAction.Left(3, SockAI)
        if position[0] == '4':
            AIAction.Left(3, SockAI)
        if position[0] == '5':
            AIAction.Left(3, SockAI)
            AIAction.Left(3, SockAI)
        if position[0] == '6' or position[0] == '7' or position[0] == '8':
            AIAction.Right(3, SockAI)
        if position[0] == '0':
            AIAction.SetObject(3, SockAI, "linemate\n")
            AIAction.SetObject(3, SockAI, "linemate\n")
            AIAction.SetObject(3, SockAI, "phiras\n")
            AIAction.SetObject(3, SockAI, "phiras\n")
            AIAction.SetObject(3, SockAI, "sibur\n")
            if AIAction.Incantation(3, SockAI) == True:
                print("incantation lvl3->lvl4!!!\n")
                return
        if "3:Let's go?" in Object:
            if position == "0":
                AIAction.SetObject(3, SockAI, "linemate\n")
                AIAction.SetObject(3, SockAI, "linemate\n")
                AIAction.SetObject(3, SockAI, "phiras\n")
                AIAction.SetObject(3, SockAI, "phiras\n")
                AIAction.SetObject(3, SockAI, "sibur\n")
                if AIAction.Incantation(3, SockAI) == True:
                    print("incantation lvl3->lvl3!!!\n")
        else:
            AIAction.BroadCast(3, "3:I search you again, broad\n", SockAI)

    def BroadTraiter(Level, Object, SockAI):
        if Level < 2:
            return
        if Level == 2:
            AIAction.BroadLvl2(Object, SockAI)
        if Level == 3:
            AIAction.BroadLvl3(Object, SockAI)
        return

    def Level3(SockAI):
        print("lvl3")
        AIAction.BroadCast(2, "2:imlvl3, broad\n", SockAI)
        lvl = 3
        fork = 0
        while (lvl == 3):
            inventory = AIAction.Inventory(3, SockAI)
            inventory_0_num = int(inventory[0])
            inventory_1_num = int(inventory[1])
            inventory_2_num = int(inventory[5])
            inventory_3_num = int(inventory[3])
            # print("INVENTORY --> ", inventory)
            # Nb = AIAction.CoNbr(2, SockAI)
            if inventory_0_num > 7 and fork == 0:
                AIAction.Fork(3, SockAI)
                fork += 1
            Rsp = AIAction.ParseServerCmdLook(3, SockAI, AIAction.Look(3, SockAI))
            i = 0
            j = 0
            if AIAction.CheckPlayer(Rsp[0], 2) == 0 and inventory_1_num >= 2 and inventory_2_num >= 1 and inventory_3_num >= 2:
                AIAction.BroadCast(3, "3:ComeCrew, broad\n", SockAI)
                AIAction.SetObject(3, SockAI, "linemate\n")
                AIAction.SetObject(3, SockAI, "linemate\n")
                AIAction.SetObject(3, SockAI, "phiras\n")
                AIAction.SetObject(3, SockAI, "phiras\n")
                AIAction.SetObject(3, SockAI, "sibur\n")
                AIAction.Incantation(3, SockAI)
                return 4
            for i, element in enumerate(Rsp):
                if i == 0:
                    count = Rsp[0].count("food")
                    while count != 0:
                        AIAction.TakeObject(3, "food\n", SockAI)
                        count -= 1
                    if "linemate" in element and inventory_1_num == 0:
                        AIAction.TakeObject(3, "linemate\n", SockAI)
                    if "phiras" in element and inventory_2_num == 0:
                        AIAction.TakeObject(3, "phiras\n", SockAI)
                    if "sibur" in element and inventory_3_num == 0:
                        AIAction.TakeObject(3, "sibur\n", SockAI)
                elif i == 1:
                    if "player" in element and inventory_0_num >= 3 and inventory_1_num >= 1 and inventory_2_num >= 2 and inventory_3_num >= 1:
                        AIAction.Forward(3, SockAI)
                        AIAction.Left(3, SockAI)
                        AIAction.Forward(3, SockAI)
                        count = Rsp[1].count("food")
                        while count != 0:
                            AIAction.TakeObject(3, "food\n", SockAI)
                            count -= 1
                        j+=1
                    if "linemate" in element and inventory_1_num == 0 and j == 0:
                        AIAction.Forward(3, SockAI)
                        AIAction.Left(3, SockAI)
                        j+=1
                        AIAction.Forward(3, SockAI)
                        count = Rsp[1].count("food")
                        while count != 0:
                            AIAction.TakeObject(3, "food\n", SockAI)
                            count -= 1
                        AIAction.TakeObject(3, "linemate\n", SockAI)
                    if "phiras" in element and inventory_2_num == 0 and j == 0:
                        AIAction.Forward(3, SockAI)
                        AIAction.Left(3, SockAI)
                        j+=1
                        AIAction.Forward(3, SockAI)
                        count = Rsp[1].count("food")
                        while count != 0:
                            AIAction.TakeObject(3, "food\n", SockAI)
                            count -= 1
                        AIAction.TakeObject(3, "phiras\n", SockAI)
                    if "sibur" in element and inventory_3_num == 0 and j == 0:
                        AIAction.Forward(3, SockAI)
                        AIAction.Left(3, SockAI)
                        j+=1
                        AIAction.Forward(3, SockAI)
                        count = Rsp[1].count("food")
                        while count != 0:
                            AIAction.TakeObject(3, "food\n", SockAI)
                            count -= 1
                        AIAction.TakeObject(3, "sibur\n", SockAI)
                elif i == 2:
                    if "player" in element and inventory_0_num >= 3 and inventory_1_num >= 2 and inventory_2_num >= 2 and inventory_3_num >= 1 and j == 0:
                        AIAction.Forward(3, SockAI)
                        count = Rsp[2].count("food")
                        while count != 0:
                            AIAction.TakeObject(3, "food\n", SockAI)
                            count -= 1
                        j+=1
                    if "linemate" in element and inventory_1_num == 0 and j == 0:
                        AIAction.Forward(3, SockAI)
                        j+=1
                        AIAction.TakeObject(3, "linemate\n", SockAI)
                        count = Rsp[2].count("food")
                        while count != 0:
                            AIAction.TakeObject(3, "food\n", SockAI)
                            count -= 1
                    if "phiras" in element and inventory_2_num == 0 and j == 0:
                        AIAction.Forward(3, SockAI)
                        j+=1
                        AIAction.TakeObject(3, "phiras\n", SockAI)
                        count = Rsp[2].count("food")
                        while count != 0:
                            AIAction.TakeObject(3, "food\n", SockAI)
                            count -= 1
                    if "sibur" in element and inventory_3_num == 0 and j == 0:
                        AIAction.Forward(3, SockAI)
                        j+=1
                        AIAction.TakeObject(3, "sibur\n", SockAI)
                        count = Rsp[2].count("food")
                        while count != 0:
                            AIAction.TakeObject(3, "food\n", SockAI)
                            count -= 1
                elif i == 3:
                    if "player" in element and inventory_0_num >= 3 and inventory_1_num >= 2 and inventory_2_num >= 2 and inventory_3_num >= 1 and j == 0:
                        AIAction.Forward(3, SockAI)
                        AIAction.Right(3, SockAI)
                        j+=1
                        AIAction.Forward(3, SockAI)
                        count = Rsp[3].count("food")
                        while count != 0:
                            AIAction.TakeObject(3, "food\n", SockAI)
                            count -= 1
                    if "linemate" in element and inventory_1_num == 0 and j == 0:
                        AIAction.Forward(3, SockAI)
                        AIAction.Right(3, SockAI)
                        j+=1
                        AIAction.Forward(3, SockAI)
                        count = Rsp[3].count("food")
                        while count != 0:
                            AIAction.TakeObject(3, "food\n", SockAI)
                            count -= 1
                        AIAction.TakeObject(3, "linemate\n", SockAI)
                    if "phiras" in element and inventory_2_num == 0 and j == 0:
                        AIAction.Forward(3, SockAI)
                        AIAction.Right(3, SockAI)
                        j+=1
                        AIAction.Forward(3, SockAI)
                        count = Rsp[3].count("food")
                        while count != 0:
                            AIAction.TakeObject(3, "food\n", SockAI)
                            count -= 1
                        AIAction.TakeObject(3, "phiras\n", SockAI)
                    if "sibur" in element and inventory_3_num == 0 and j == 0:
                        AIAction.Forward(3, SockAI)
                        AIAction.Right(3, SockAI)
                        j+=1
                        AIAction.Forward(3, SockAI)
                        count = Rsp[3].count("food")
                        while count != 0:
                            AIAction.TakeObject(3, "food\n", SockAI)
                            count -= 1
                        AIAction.TakeObject(3, "sibur\n", SockAI)
                elif i == 4:
                    if "player" in element and j == 0:
                        j += 1
                        AIAction.Forward(3, SockAI)
                        AIAction.Forward(3, SockAI)
                        AIAction.Left(3, SockAI)
                        AIAction.Forward(3, SockAI)
                        AIAction.Forward(3, SockAI)
                        count = Rsp[4].count("food")
                        while count != 0:
                            AIAction.TakeObject(3, "food\n", SockAI)
                            count -= 1
                    if "linemate" in element and inventory_1_num == 0 and inventory_0_num > 4 and j == 0:
                        j += 1
                        AIAction.Forward(3, SockAI)
                        AIAction.Forward(3, SockAI)
                        AIAction.Left(3, SockAI)
                        AIAction.Forward(3, SockAI)
                        AIAction.Forward(3, SockAI)
                        AIAction.TakeObject(3, "linemate\n", SockAI)
                        count = Rsp[4].count("food")
                        while count != 0:
                            AIAction.TakeObject(3, "food\n", SockAI)
                            count -= 1
                    if "phiras" in element and inventory_2_num == 0 and inventory_0_num > 4 and j == 0:
                        j += 1
                        AIAction.Forward(3, SockAI)
                        AIAction.Forward(3, SockAI)
                        AIAction.Left(3, SockAI)
                        AIAction.Forward(3, SockAI)
                        AIAction.Forward(3, SockAI)
                        AIAction.TakeObject(3, "phiras\n", SockAI)
                        count = Rsp[4].count("food")
                        while count != 0:
                            AIAction.TakeObject(3, "food\n", SockAI)
                            count -= 1
                    if "sibur" in element and inventory_3_num == 0 and inventory_0_num > 4 and j == 0:
                        j += 1
                        AIAction.Forward(3, SockAI)
                        AIAction.Forward(3, SockAI)
                        AIAction.Left(3, SockAI)
                        AIAction.Forward(3, SockAI)
                        AIAction.Forward(3, SockAI)
                        AIAction.TakeObject(3, "sibur\n", SockAI)
                        count = Rsp[4].count("food")
                        while count != 0:
                            AIAction.TakeObject(3, "food\n", SockAI)
                            count -= 1
                elif i == 5:
                    if "player" in element and j == 0:
                        j += 1
                        AIAction.Forward(3, SockAI)
                        AIAction.Forward(3, SockAI)
                        AIAction.Left(3, SockAI)
                        AIAction.Forward(3, SockAI)
                        AIAction.TakeObject(3, "food\n", SockAI)
                        count = Rsp[5].count("food")
                        while count != 0:
                            AIAction.TakeObject(3, "food\n", SockAI)
                            count -= 1
                    if "linemate" in element and inventory_1_num == 0 and inventory_0_num > 4 and j == 0:
                        j += 1
                        AIAction.Forward(3, SockAI)
                        AIAction.Forward(3, SockAI)
                        AIAction.Left(3, SockAI)
                        AIAction.Forward(3, SockAI)
                        AIAction.TakeObject(3, "linemate\n", SockAI)
                        count = Rsp[5].count("food")
                        while count != 0:
                            AIAction.TakeObject(3, "food\n", SockAI)
                            count -= 1
                    if "phiras" in element and inventory_2_num == 0 and inventory_0_num > 4 and j == 0:
                        j += 1
                        AIAction.Forward(3, SockAI)
                        AIAction.Forward(3, SockAI)
                        AIAction.Left(3, SockAI)
                        AIAction.Forward(3, SockAI)
                        AIAction.TakeObject(3, "phiras\n", SockAI)
                        count = Rsp[5].count("food")
                        while count != 0:
                            AIAction.TakeObject(3, "food\n", SockAI)
                            count -= 1
                    if "sibur" in element and inventory_3_num == 0 and inventory_0_num > 4 and j == 0:
                        j += 1
                        AIAction.Forward(3, SockAI)
                        AIAction.Forward(3, SockAI)
                        AIAction.Left(3, SockAI)
                        AIAction.Forward(3, SockAI)
                        AIAction.TakeObject(3, "sibur\n", SockAI)
                        count = Rsp[5].count("food")
                        while count != 0:
                            AIAction.TakeObject(3, "food\n", SockAI)
                            count -= 1
                elif i == 6:
                    if "player" in element and j == 0:
                        j += 1
                        AIAction.Forward(3, SockAI)
                        AIAction.Forward(3, SockAI)
                        count = Rsp[6].count("food")
                        while count != 0:
                            AIAction.TakeObject(3, "food\n", SockAI)
                            count -= 1
                    if "linemate" in element and inventory_1_num == 0 and j == 0:
                        j += 1
                        AIAction.Forward(3, SockAI)
                        AIAction.Forward(3, SockAI)
                        AIAction.TakeObject(3, "linemate\n", SockAI)
                        count = Rsp[6].count("food")
                        while count != 0:
                            AIAction.TakeObject(3, "food\n", SockAI)
                            count -= 1
                    if "phiras" in element and inventory_2_num == 0 and j == 0:
                        j += 1
                        AIAction.Forward(3, SockAI)
                        AIAction.Forward(3, SockAI)
                        AIAction.TakeObject(3, "phiras\n", SockAI)
                        count = Rsp[6].count("food")
                        while count != 0:
                            AIAction.TakeObject(3, "food\n", SockAI)
                            count -= 1
                    if "sibur" in element and inventory_3_num == 0 and j == 0:
                        j += 1
                        AIAction.Forward(3, SockAI)
                        AIAction.Forward(3, SockAI)
                        AIAction.TakeObject(3, "sibur\n", SockAI)
                        count = Rsp[6].count("food")
                        while count != 0:
                            AIAction.TakeObject(3, "food\n", SockAI)
                            count -= 1
                elif i == 7:
                    if "player" in element and j == 0:
                        j += 1
                        AIAction.Forward(3, SockAI)
                        AIAction.Forward(3, SockAI)
                        AIAction.Right(3, SockAI)
                        AIAction.Forward(3, SockAI)
                        count = Rsp[7].count("food")
                        while count != 0:
                            AIAction.TakeObject(3, "food\n", SockAI)
                            count -= 1
                    if "linemate" in element and inventory_1_num == 0 and inventory_0_num > 4 and j == 0:
                        j += 1
                        AIAction.Forward(3, SockAI)
                        AIAction.Forward(3, SockAI)
                        AIAction.Right(3, SockAI)
                        AIAction.Forward(3, SockAI)
                        AIAction.TakeObject(3, "linemate\n", SockAI)
                        count = Rsp[7].count("food")
                        while count != 0:
                            AIAction.TakeObject(3, "food\n", SockAI)
                            count -= 1
                    if "phiras" in element and inventory_2_num == 0 and inventory_0_num > 4 and j == 0:
                        j += 1
                        AIAction.Forward(3, SockAI)
                        AIAction.Forward(3, SockAI)
                        AIAction.Right(3, SockAI)
                        AIAction.Forward(3, SockAI)
                        AIAction.TakeObject(3, "phiras\n", SockAI)
                        count = Rsp[7].count("food")
                        while count != 0:
                            AIAction.TakeObject(3, "food\n", SockAI)
                            count -= 1
                    if "sibur" in element and inventory_3_num == 0 and inventory_0_num > 4 and j == 0:
                        j += 1
                        AIAction.Forward(3, SockAI)
                        AIAction.Forward(3, SockAI)
                        AIAction.Right(3, SockAI)
                        AIAction.Forward(3, SockAI)
                        AIAction.TakeObject(3, "sibur\n", SockAI)
                        count = Rsp[7].count("food")
                        while count != 0:
                            AIAction.TakeObject(3, "food\n", SockAI)
                            count -= 1
                elif i == 8:
                    if "player" in element and j == 0:
                        j += 1
                        AIAction.Forward(3, SockAI)
                        AIAction.Forward(3, SockAI)
                        AIAction.Right(3, SockAI)
                        AIAction.Forward(3, SockAI)
                        AIAction.Forward(3, SockAI)
                        count = Rsp[8].count("food")
                        while count != 0:
                            AIAction.TakeObject(3, "food\n", SockAI)
                            count -= 1
                    if "linemate" in element and inventory_1_num == 0 and inventory_0_num > 4 and j == 0:
                        j += 1
                        AIAction.Forward(3, SockAI)
                        AIAction.Forward(3, SockAI)
                        AIAction.Forward(3, SockAI)
                        AIAction.Right(3, SockAI)
                        AIAction.Forward(3, SockAI)
                        AIAction.Forward(3, SockAI)
                        AIAction.TakeObject(3, "linemate\n", SockAI)
                        count = Rsp[8].count("food")
                        while count != 0:
                            AIAction.TakeObject(3, "food\n", SockAI)
                            count -= 1
                    if "phiras" in element and inventory_2_num == 0 and inventory_0_num > 4 and j == 0:
                        j += 1
                        AIAction.Forward(3, SockAI)
                        AIAction.Forward(3, SockAI)
                        AIAction.Right(3, SockAI)
                        AIAction.Forward(3, SockAI)
                        AIAction.Forward(3, SockAI)
                        AIAction.TakeObject(3, "phiras\n", SockAI)
                        count = Rsp[8].count("food")
                        while count != 0:
                            AIAction.TakeObject(3, "food\n", SockAI)
                            count -= 1
                    if "sibur" in element and inventory_3_num == 0 and inventory_0_num > 4 and j == 0:
                        j += 1
                        AIAction.Forward(3, SockAI)
                        AIAction.Forward(3, SockAI)
                        AIAction.Right(3, SockAI)
                        AIAction.Forward(3, SockAI)
                        AIAction.Forward(3, SockAI)
                        AIAction.TakeObject(3, "sibur\n", SockAI)
                        count = Rsp[8].count("food")
                        while count != 0:
                            AIAction.TakeObject(3, "food\n", SockAI)
                            count -= 1
                if j == 0:
                    AIAction.Forward(3, SockAI)

    def Level2(SockAI):
        global thread_string
        print("In level 2\n")
        lvl = 2
        fork = 0
        while (lvl == 2):
            inventory = AIAction.Inventory(2, SockAI)
            inventory_0_num = int(inventory[0])
            inventory_1_num = int(inventory[1])
            inventory_2_num = int(inventory[2])
            inventory_3_num = int(inventory[3])
            # print("INVENTORY --> ", inventory)
            # Nb = AIAction.CoNbr(2, SockAI)
            # if Nb != 0 and inventory_0_num > 5:
            if inventory_0_num >= 5:
                AIAction.Fork(2, SockAI)
                fork += 1
            Rsp = AIAction.ParseServerCmdLook(2, SockAI, AIAction.Look(2, SockAI))
            i = 0
            j = 0
            if inventory_0_num >= 4 and inventory_1_num >= 1 and inventory_2_num >= 1 and inventory_3_num >= 1:
                AIAction.BroadCastInc(2, "2:ComeCrew, broad\n", SockAI)
                print("PUTAIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIN\n")
                AIAction.Incantation(2, SockAI)
                return 3
            for i, element in enumerate(Rsp):
                if i == 0:
                    count = Rsp[0].count("food")
                    if count > 0:
                        while count != 0:
                            AIAction.TakeObject(2, "food\n", SockAI)
                            count -= 1
                        if "linemate" in element and inventory_1_num == 0:
                            AIAction.TakeObject(2, "linemate\n", SockAI)
                        if "deraumere" in element and inventory_2_num == 0:
                            AIAction.TakeObject(2, "deraumere\n", SockAI)
                        if "sibur" in element and inventory_3_num == 0:
                            AIAction.TakeObject(2, "sibur\n", SockAI)
                elif i == 1:
                    if "player" in element and inventory_0_num >= 3 and inventory_1_num >= 1 and inventory_2_num >= 1 and inventory_3_num >= 1:
                        AIAction.Forward(2, SockAI)
                        AIAction.Left(2, SockAI)
                        AIAction.Forward(2, SockAI)
                        count = Rsp[1].count("food")
                        while count != 0:
                            AIAction.TakeObject(2, "food\n", SockAI)
                            count -= 1
                        j+=1
                    if "linemate" in element and inventory_1_num == 0 and j == 0:
                        AIAction.Forward(2, SockAI)
                        AIAction.Left(2, SockAI)
                        j+=1
                        AIAction.Forward(2, SockAI)
                        count = Rsp[1].count("food")
                        while count != 0:
                            AIAction.TakeObject(2, "food\n", SockAI)
                            count -= 1
                        AIAction.TakeObject(2, "linemate\n", SockAI)
                    if "deraumere" in element and inventory_2_num == 0 and j == 0:
                        AIAction.Forward(2, SockAI)
                        AIAction.Left(2, SockAI)
                        j+=1
                        AIAction.Forward(2, SockAI)
                        count = Rsp[1].count("food")
                        while count != 0:
                            AIAction.TakeObject(2, "food\n", SockAI)
                            count -= 1
                        AIAction.TakeObject(2, "deraumere\n", SockAI)
                    if "sibur" in element and inventory_3_num == 0 and j == 0:
                        AIAction.Forward(2, SockAI)
                        AIAction.Left(2, SockAI)
                        j+=1
                        AIAction.Forward(2, SockAI)
                        count = Rsp[1].count("food")
                        while count != 0:
                            AIAction.TakeObject(2, "food\n", SockAI)
                            count -= 1
                        AIAction.TakeObject(2, "sibur\n", SockAI)
                elif i == 2:
                    if "player" in element and inventory_0_num >= 3 and inventory_1_num >= 1 and inventory_2_num >= 1 and inventory_3_num >= 1 and j == 0:
                        AIAction.Forward(2, SockAI)
                        count = Rsp[2].count("food")
                        while count != 0:
                            AIAction.TakeObject(2, "food\n", SockAI)
                            count -= 1
                        j+=1
                    if "linemate" in element and inventory_1_num == 0 and j == 0:
                        AIAction.Forward(2, SockAI)
                        j+=1
                        AIAction.TakeObject(2, "linemate\n", SockAI)
                        count = Rsp[2].count("food")
                        while count != 0:
                            AIAction.TakeObject(2, "food\n", SockAI)
                            count -= 1
                    if "deraumere" in element and inventory_2_num == 0 and j == 0:
                        AIAction.Forward(2, SockAI)
                        j+=1
                        AIAction.TakeObject(2, "deraumere\n", SockAI)
                        count = Rsp[2].count("food")
                        while count != 0:
                            AIAction.TakeObject(2, "food\n", SockAI)
                            count -= 1
                    if "sibur" in element and inventory_3_num == 0 and j == 0:
                        AIAction.Forward(2, SockAI)
                        j+=1
                        AIAction.TakeObject(2, "sibur\n", SockAI)
                        count = Rsp[2].count("food")
                        while count != 0:
                            AIAction.TakeObject(2, "food\n", SockAI)
                            count -= 1
                elif i == 3:
                    if "player" in element and inventory_0_num >= 3 and inventory_1_num >= 1 and inventory_2_num >= 1 and inventory_3_num >= 1 and j == 0:
                        AIAction.Forward(2, SockAI)
                        AIAction.Right(2, SockAI)
                        j+=1
                        AIAction.Forward(2, SockAI)
                        count = Rsp[3].count("food")
                        while count != 0:
                            AIAction.TakeObject(2, "food\n", SockAI)
                            count -= 1
                    if "linemate" in element and inventory_1_num == 0 and j == 0:
                        AIAction.Forward(2, SockAI)
                        AIAction.Right(2, SockAI)
                        j+=1
                        AIAction.Forward(2, SockAI)
                        count = Rsp[3].count("food")
                        while count != 0:
                            AIAction.TakeObject(2, "food\n", SockAI)
                            count -= 1
                        AIAction.TakeObject(2, "linemate\n", SockAI)
                    if "deraumere" in element and inventory_2_num == 0 and j == 0:
                        AIAction.Forward(2, SockAI)
                        AIAction.Right(2, SockAI)
                        j+=1
                        AIAction.Forward(2, SockAI)
                        count = Rsp[3].count("food")
                        while count != 0:
                            AIAction.TakeObject(2, "food\n", SockAI)
                            count -= 1
                        AIAction.TakeObject(2, "deraumere\n", SockAI)
                    if "sibur" in element and inventory_3_num == 0 and j == 0:
                        AIAction.Forward(2, SockAI)
                        AIAction.Right(2, SockAI)
                        j+=1
                        AIAction.Forward(2, SockAI)
                        count = Rsp[3].count("food")
                        while count != 0:
                            AIAction.TakeObject(2, "food\n", SockAI)
                            count -= 1
                        AIAction.TakeObject(2, "sibur\n", SockAI)
                elif i == 4:
                    if "player" in element and j == 0:
                        j += 1
                        AIAction.Forward(2, SockAI)
                        AIAction.Forward(2, SockAI)
                        AIAction.Left(2, SockAI)
                        AIAction.Forward(2, SockAI)
                        AIAction.Forward(2, SockAI)
                        count = Rsp[4].count("food")
                        while count != 0:
                            AIAction.TakeObject(2, "food\n", SockAI)
                            count -= 1
                    if "linemate" in element and inventory_1_num == 0 and inventory_0_num > 4 and j == 0:
                        j += 1
                        AIAction.Forward(2, SockAI)
                        AIAction.Forward(2, SockAI)
                        AIAction.Left(2, SockAI)
                        AIAction.Forward(2, SockAI)
                        AIAction.Forward(2, SockAI)
                        AIAction.TakeObject(2, "linemate\n", SockAI)
                        count = Rsp[4].count("food")
                        while count != 0:
                            AIAction.TakeObject(2, "food\n", SockAI)
                            count -= 1
                    if "deraumere" in element and inventory_2_num == 0 and inventory_0_num > 4 and j == 0:
                        j += 1
                        AIAction.Forward(2, SockAI)
                        AIAction.Forward(2, SockAI)
                        AIAction.Left(2, SockAI)
                        AIAction.Forward(2, SockAI)
                        AIAction.Forward(2, SockAI)
                        AIAction.TakeObject(2, "deraumere\n", SockAI)
                        count = Rsp[4].count("food")
                        while count != 0:
                            AIAction.TakeObject(2, "food\n", SockAI)
                            count -= 1
                    if "sibur" in element and inventory_3_num == 0 and inventory_0_num > 4 and j == 0:
                        j += 1
                        AIAction.Forward(2, SockAI)
                        AIAction.Forward(2, SockAI)
                        AIAction.Left(2, SockAI)
                        AIAction.Forward(2, SockAI)
                        AIAction.Forward(2, SockAI)
                        AIAction.TakeObject(2, "sibur\n", SockAI)
                        count = Rsp[4].count("food")
                        while count != 0:
                            AIAction.TakeObject(2, "food\n", SockAI)
                            count -= 1
                elif i == 5:
                    if "player" in element and j == 0:
                        j += 1
                        AIAction.Forward(2, SockAI)
                        AIAction.Forward(2, SockAI)
                        AIAction.Left(2, SockAI)
                        AIAction.Forward(2, SockAI)
                        AIAction.TakeObject(2, "food\n", SockAI)
                        count = Rsp[5].count("food")
                        while count != 0:
                            AIAction.TakeObject(2, "food\n", SockAI)
                            count -= 1
                    if "linemate" in element and inventory_1_num == 0 and inventory_0_num > 4 and j == 0:
                        j += 1
                        AIAction.Forward(2, SockAI)
                        AIAction.Forward(2, SockAI)
                        AIAction.Left(2, SockAI)
                        AIAction.Forward(2, SockAI)
                        AIAction.TakeObject(2, "linemate\n", SockAI)
                        count = Rsp[5].count("food")
                        while count != 0:
                            AIAction.TakeObject(2, "food\n", SockAI)
                            count -= 1
                    if "deraumere" in element and inventory_2_num == 0 and inventory_0_num > 4 and j == 0:
                        j += 1
                        AIAction.Forward(2, SockAI)
                        AIAction.Forward(2, SockAI)
                        AIAction.Left(2, SockAI)
                        AIAction.Forward(2, SockAI)
                        AIAction.TakeObject(2, "deraumere\n", SockAI)
                        count = Rsp[5].count("food")
                        while count != 0:
                            AIAction.TakeObject(2, "food\n", SockAI)
                            count -= 1
                    if "sibur" in element and inventory_3_num == 0 and inventory_0_num > 4 and j == 0:
                        j += 1
                        AIAction.Forward(2, SockAI)
                        AIAction.Forward(2, SockAI)
                        AIAction.Left(2, SockAI)
                        AIAction.Forward(2, SockAI)
                        AIAction.TakeObject(2, "sibur\n", SockAI)
                        count = Rsp[5].count("food")
                        while count != 0:
                            AIAction.TakeObject(2, "food\n", SockAI)
                            count -= 1
                elif i == 6:
                    if "player" in element and j == 0:
                        j += 1
                        AIAction.Forward(2, SockAI)
                        AIAction.Forward(2, SockAI)
                        count = Rsp[6].count("food")
                        while count != 0:
                            AIAction.TakeObject(2, "food\n", SockAI)
                            count -= 1
                    if "linemate" in element and inventory_1_num == 0 and j == 0:
                        j += 1
                        AIAction.Forward(2, SockAI)
                        AIAction.Forward(2, SockAI)
                        AIAction.TakeObject(2, "linemate\n", SockAI)
                        count = Rsp[6].count("food")
                        while count != 0:
                            AIAction.TakeObject(2, "food\n", SockAI)
                            count -= 1
                    if "deraumere" in element and inventory_2_num == 0 and j == 0:
                        j += 1
                        AIAction.Forward(2, SockAI)
                        AIAction.Forward(2, SockAI)
                        AIAction.TakeObject(2, "deraumere\n", SockAI)
                        count = Rsp[6].count("food")
                        while count != 0:
                            AIAction.TakeObject(2, "food\n", SockAI)
                            count -= 1
                    if "sibur" in element and inventory_3_num == 0 and j == 0:
                        j += 1
                        AIAction.Forward(2, SockAI)
                        AIAction.Forward(2, SockAI)
                        AIAction.TakeObject(2, "sibur\n", SockAI)
                        count = Rsp[6].count("food")
                        while count != 0:
                            AIAction.TakeObject(2, "food\n", SockAI)
                            count -= 1
                elif i == 7:
                    if "player" in element and j == 0:
                        j += 1
                        AIAction.Forward(2, SockAI)
                        AIAction.Forward(2, SockAI)
                        AIAction.Right(2, SockAI)
                        AIAction.Forward(2, SockAI)
                        count = Rsp[7].count("food")
                        while count != 0:
                            AIAction.TakeObject(2, "food\n", SockAI)
                            count -= 1
                    if "linemate" in element and inventory_1_num == 0 and inventory_0_num > 4 and j == 0:
                        j += 1
                        AIAction.Forward(2, SockAI)
                        AIAction.Forward(2, SockAI)
                        AIAction.Right(2, SockAI)
                        AIAction.Forward(2, SockAI)
                        AIAction.TakeObject(2, "linemate\n", SockAI)
                        count = Rsp[7].count("food")
                        while count != 0:
                            AIAction.TakeObject(2, "food\n", SockAI)
                            count -= 1
                    if "deraumere" in element and inventory_2_num == 0 and inventory_0_num > 4 and j == 0:
                        j += 1
                        AIAction.Forward(2, SockAI)
                        AIAction.Forward(2, SockAI)
                        AIAction.Right(2, SockAI)
                        AIAction.Forward(2, SockAI)
                        AIAction.TakeObject(2, "deraumere\n", SockAI)
                        count = Rsp[7].count("food")
                        while count != 0:
                            AIAction.TakeObject(2, "food\n", SockAI)
                            count -= 1
                    if "sibur" in element and inventory_3_num == 0 and inventory_0_num > 4 and j == 0:
                        j += 1
                        AIAction.Forward(2, SockAI)
                        AIAction.Forward(2, SockAI)
                        AIAction.Right(2, SockAI)
                        AIAction.Forward(2, SockAI)
                        AIAction.TakeObject(2, "sibur\n", SockAI)
                        count = Rsp[7].count("food")
                        while count != 0:
                            AIAction.TakeObject(2, "food\n", SockAI)
                            count -= 1
                elif i == 8:
                    if "player" in element and j == 0:
                        j += 1
                        AIAction.Forward(2, SockAI)
                        AIAction.Forward(2, SockAI)
                        AIAction.Right(2, SockAI)
                        AIAction.Forward(2, SockAI)
                        AIAction.Forward(2, SockAI)
                        count = Rsp[8].count("food")
                        while count != 0:
                            AIAction.TakeObject(2, "food\n", SockAI)
                            count -= 1
                    if "linemate" in element and inventory_1_num == 0 and inventory_0_num > 4 and j == 0:
                        j += 1
                        AIAction.Forward(2, SockAI)
                        AIAction.Forward(2, SockAI)
                        AIAction.Forward(2, SockAI)
                        AIAction.Right(2, SockAI)
                        AIAction.Forward(2, SockAI)
                        AIAction.Forward(2, SockAI)
                        AIAction.TakeObject(2, "linemate\n", SockAI)
                        count = Rsp[8].count("food")
                        while count != 0:
                            AIAction.TakeObject(2, "food\n", SockAI)
                            count -= 1
                    if "deraumere" in element and inventory_2_num == 0 and inventory_0_num > 4 and j == 0:
                        j += 1
                        AIAction.Forward(2, SockAI)
                        AIAction.Forward(2, SockAI)
                        AIAction.Right(2, SockAI)
                        AIAction.Forward(2, SockAI)
                        AIAction.Forward(2, SockAI)
                        AIAction.TakeObject(2, "deraumere\n", SockAI)
                        count = Rsp[8].count("food")
                        while count != 0:
                            AIAction.TakeObject(2, "food\n", SockAI)
                            count -= 1
                    if "sibur" in element and inventory_3_num == 0 and inventory_0_num > 4 and j == 0:
                        j += 1
                        AIAction.Forward(2, SockAI)
                        AIAction.Forward(2, SockAI)
                        AIAction.Right(2, SockAI)
                        AIAction.Forward(2, SockAI)
                        AIAction.Forward(2, SockAI)
                        AIAction.TakeObject(2, "sibur\n", SockAI)
                        count = Rsp[8].count("food")
                        while count != 0:
                            AIAction.TakeObject(2, "food\n", SockAI)
                            count -= 1
                if j == 0:
                    AIAction.Forward(2, SockAI)

    def Level1(SockAI):
        while True:
            Rsp = AIAction.ParseServerCmdLook(1, SockAI, AIAction.Look(1, SockAI))
            # print("lvl1: Look: ", Rsp)
            i = 0
            j = 0
            Inventory = AIAction.Inventory(1, SockAI)
            InventoryTmp = Inventory
            try:
                inventory_0_num = int(Inventory[0])
                inventory_1_num = int(Inventory[1])
            except (ValueError, IndexError):
                Inventory = InventoryTmp
                inventory_0_num = inventory_0_numtmp
                inventory_1_num = inventory_1_numtmp
            if inventory_0_num >= 3 and inventory_1_num >= 1:
                AIAction.SetObject(1, SockAI, "linemate\n")
                if AIAction.Incantation(1, SockAI) == True:
                    return 2
            for i, element in enumerate(Rsp):
                i = 0
                if "food" in element:
                    AIAction.TakeObject(1, "food\n", SockAI)
                    j+=1
                if "linemate" in element:
                    AIAction.TakeObject(1, "linemate\n", SockAI)
                    j+=1
                i = 2
                if "linemate" in element:
                    AIAction.Forward(1, SockAI)
                    j+=1
                    AIAction.TakeObject(1, "linemate\n", SockAI)
                i = 1
                if "linemate" in element:
                    AIAction.Forward(1, SockAI)
                    AIAction.Left(1, SockAI)
                    j+=1
                    AIAction.Forward(1, SockAI)
                    AIAction.TakeObject(1, "linemate\n", SockAI)
                i = 3
                if "linemate" in element:
                    AIAction.Forward(1, SockAI)
                    AIAction.Right(1, SockAI)
                    j+=1
                    AIAction.Forward(1, SockAI)
                    AIAction.TakeObject(1, "linemate\n", SockAI)
                if j == 0:
                    AIAction.Forward(1, SockAI)
            inventory_0_numtmp = inventory_0_num
            inventory_1_numtmp = inventory_1_num

def myAI(SockAI, NbPlayer):
    Level = 1
    if Level == 1:
        Level = AIAction.Level1(SockAI)
    if Level == 2:
        Level = AIAction.Level2(SockAI)
    if Level == 3:
        Level = AIAction.Level3(SockAI)
    print("im lvl 4\n")
    
    while(True):
        AIAction.Forward(4, SockAI)
    # SockAI.close()
    sys.exit()
    # if Level == 2:
    #     Level = AIAction.Level2(SockAI, NbPlayer)
    # if Level == 4:
    #     Level = AIAction.Level4(SockAI, NbPlayer)


def initAi():
    global thread_string
    thread_string = AIAction.generate_unique_string()
    parser = Parse.ParsingArgs()
    ip, port, name = parser.parseArgs()
    connection_result = ConnectAIToServer.ConnectSocketToServer(ip, port, name)
    if connection_result is None:
        return
    AllData, SockAI = connection_result
    DataStock = AllData.split("\n")
    NbPlayer = DataStock[1]
    print("NbPlayerNeedBeingConnect:", NbPlayer)
    SizeFieldX, SizeFieldY = DataStock[2].split(" ")
    print("Size Field X:", SizeFieldX)
    print("Size Field Y:", SizeFieldY)
    myAI(SockAI, NbPlayer)

def main():
    # initAi()
    thread = threading.Thread(target=initAi)
    thread.start()
    thread.join()

if __name__ == "__main__":
    try:
        main()
    except KeyboardInterrupt:
        print("Program stopped by user")