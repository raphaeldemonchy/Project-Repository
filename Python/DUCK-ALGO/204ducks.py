##
## EPITECH PROJECT, 2023
## 204ducks
## File description:
## 204ducks
##

import sys
import math

#========================MATH FUNCTION===========================#

def my_formule(arg, t, mode=False):
    if mode == False:
        return -arg * math.exp(-t) - (4 - 3 * arg) / 2 * math.exp(-2 * t) - (2 * arg - 4) / 4 * math.exp(-4 * t)
    else:
        return arg * math.exp(-t) + (4 - 3 * arg) * math.exp(-2 * t) + (2 * arg - 4) * math.exp(-4 * t)


#========================MainFUNCTION===========================#

def avrgReturnTime(arg: float) -> float:
    UneSecond = 0.001 

    res = 0.00
    time = 0.00

    while time < 1000:
        res += my_formule(arg, time, True) * time / 1000
        time += UneSecond
    return res

def standarDeviation(arg : float, avrgRT : float) -> float:
    UneSecond = 0.001 

    res = 0.00
    time = 0.00

    while time < 1000:
        proba = my_formule(arg, time, 1)
        res += (time - avrgRT) ** 2 * proba * UneSecond
        time += 0.001
    return res

def timeForRetDucks(arg, p):
    t = 0.0
    while t < 1000:
        if my_formule(arg, t / 60) - my_formule(arg, 0) >= p:
            return t
        t += 0.002
    print("Fail, ducks is lost :(")
    return None

def timeFor99ducks(arg : float):
    return 0

def backAfter1(arg : float):
    return 0

def backAfter2(arg : float):
    return 0


#_________________________________________________________________#
#------------------------------ERROR HANDLING---------------------#

# def check_arg(arg):
#     try:
#         arg = float(arg)
#         if arg < 0 or arg > 2.5:
#             sys.exit(84)
#     except (ValueError, TypeError):
#         sys.exit(84)


#_________________________________________________________________#
#-----------------------PRINT RESULLT-----------------------------#

def myDuck(arg : float):
    # print(arg)
    # print("============")

    v1 = avrgReturnTime(arg)
    minutes = int(v1)
    seconds = math.ceil((v1 - minutes) * 60)
    chaine1 = "Average return time: {}m {:02d}s".format(minutes, seconds)
    print(chaine1)

    v2 = standarDeviation(arg, v1)
    v2 = math.sqrt(v2)
    chaine2 = f"Standard deviation: {v2:.3f}"
    print(chaine2)

    v3 = timeForRetDucks(arg, 0.5)
    minutes3 = int(v3/60)
    seconds3 = int(v3%60)
    chaine3 = "Time after which 50% of the ducks come back: {}m {:02d}s".format(minutes3, seconds3)
    print(chaine3)

    v4 = timeForRetDucks(arg, 0.99)
    minutes4 = int(v4/60)
    seconds4 = int(v4%60)
    chaine4 = "Time after which 99% of the ducks come back: {}m {:02d}s".format(minutes4, seconds4)
    print(chaine4)




#========================MainFUNCTION===========================#

def usage():
    print("USAGE")
    print("\t./204ducks a\n")
    print("DESCRIPTION")
    print("\ta\t constant (between 0 and 2.5)")

if __name__ == "__main__":
    try:
        if len(sys.argv) == 2:
            if sys.argv[1] == "-h":
                usage()
            else:
                try:
                    arg = float(sys.argv[1])
                    myDuck(arg)
                except ValueError:
                    raise BaseException("ERROR : Argument must be an integer")
        else:
            raise BaseException("ERROR : Invalid arg : use [-h]")
    except BaseException as error:
        print(str(error))
        sys.exit(84)
        