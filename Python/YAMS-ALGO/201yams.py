##
## EPITECH PROJECT, 2023
## yams
## File description:
## yams
##

import sys
from math import factorial

def print_usage():
    print("USAGE")
    print("\t./201yams d1 d2 d3 d4 d5 c")
    print("DESCRIPTION")
    print("\t d1\t  value of the first die (0 if not thrown)")
    print("\t d2\t  value of the second die (0 if not thrown)")
    print("\t d3\t  value of the third die (0 if not thrown)")
    print("\t d4\t  value of the fourth die (0 if not thrown)")
    print("\t d5\t  value of the fifth die")
    print("\t c\t  expected combination")

def calc_binomial(nb1 : int, nb2 : int) -> float:
    res = (factorial(nb1) / (factorial(nb2))) 
    res *= factorial(nb1-nb2) 
    res *= pow(1/6, nb2) * pow(5/6, nb1-nb2)

    return (res)

def function_proba(nbFind : int, nbOccurence : int) -> float:
    res = float(0)
    nb_Occurence = 5 - nbOccurence
    possibility = nbFind - nbOccurence

    for a in range(possibility, nb_Occurence + 1):
        res += calc_binomial(nb_Occurence, a)
    if nbOccurence >= nbFind:
        res = 1
        return res
    else:
        return res

def calc_proba_straight(nb : int) -> float:
    tab = set()
    tab.update([d1, d2, d3, d4, d5])
    size_tab = len(tab)

    if size_tab == 1:
        tab.add(0)
    combo = 6
    if nb in tab:
        combo = 5
    if 0 in tab:
        nbFac = factorial(combo - len(tab) + 1)
        nbPow = pow(6, combo - len(tab) + 1)
        res = nbFac / nbPow
    else:
        nbFac = factorial(combo - len(tab))
        nbPow = pow(6, combo - len(tab))
        res = nbFac / nbPow
    return res


def calc_proba_full(nb1 : int, nb2 : int) -> float:
    res = float(1)

    if (nb2 > 2):
        nb2 = 2
    if (nb1 > 3):
        nb1 = 3

    nb_rep = 5 - nb1 - nb2

    for i in range(nb_rep, nb_rep + 1):
        res *= calc_binomial(nb_rep, i)
    if res > 0.1:
        res = 0.1
    return res


def check_full(str):
    count = 0
    for char in str:
        if char == '_':
            count += 1
    return count

def verify_dice(dice):
    if len(dice) != 5:
        return 84
    for d in dice:
        if not isinstance(d, int) or d < 0 or d > 6:
            return 84
    return 0

category_func = {
    'pair',
    'three',
    'four',
    'straight',
    'full',
    'yams'
}


flag = sys.argv[0]

if len(sys.argv) > 1 and flag == "-h":
    print_usage()
    exit
else:
    try:
        d1 = sys.argv[1]
        d2 = sys.argv[2]
        d3 = sys.argv[3]
        d4 = sys.argv[4]
        d5 = sys.argv[5]

        arg6 = sys.argv[6]

    except:
        print("invalid arg use -h")
        exit(84)

    dice = [int(d1), int(d2), int(d3), int(d4), int(d5)]

    if verify_dice(dice) == 84:
        print("Invalid combination")
        exit (84)


    if (check_full(arg6) == 2):                         #for full combinations
        try:
            category, chiffre1, chiffre2 = arg6.split("_")
            if category == "full":
                nb1 = dice.count(int(chiffre1))
                nb2 = dice.count(int(chiffre2))
                probabilite = calc_proba_full(nb1, nb2)
                prob = probabilite * 100
                print("Chances to get a {} {} of {}: {:.2f}%".format(chiffre1, category,chiffre2, prob))
        except:
            print("_______________________")
            print("| Unknow combinations:|")
            print("| use [-h] for usage  |")
            print("|_____________________|")
            exit(84)


    elif (check_full(arg6) == 1):
        category, chiffre = arg6.split("_")
        nbO = dice.count(int(chiffre))
        if category not in category_func:
            print("_______________________")
            print("| Unknow combinations:|")
            print("| use [-h] for usage  |")
            print("|_____________________|")
            exit(84)
        elif category == "yams":
            probabilite = function_proba(5, nbO)
            prob = probabilite * 100
            print("Chances to get a {} {}: {:.2f}%".format(chiffre, category, prob))
            exit (0)
        elif category == "pair":
            probabilite = function_proba(2, nbO)
            prob = probabilite
            print("Chances to get a {} {}: {:.2f}%".format(chiffre, category, prob))
            exit (0)
        elif category == "three":
            probabilite = function_proba(3, nbO)
            prob = probabilite * 100
            print("Chances to get a {} {}: {:.2f}%".format(chiffre, category, prob))
            exit (0)
        elif category == "four":
            probabilite = function_proba(4, nbO)
            prob = probabilite * 100
            print("Chances to get a {} {}: {:.2f}%".format(chiffre, "four-of-a-kind", prob))
            exit (0)
        elif category == "straight":
            probabilite = calc_proba_straight(chiffre)
            prob = probabilite * 100
            print("Chances to get a {} {}: {:.2f}%".format(chiffre, category, prob))
            exit (0)
        else:
            print("fail")
            exit (84)



        #follow UP

    # factorial du nombre de dé -> 5
    # diviser par factorielle du nombre de dé a avoir * factorielle du nombre de dé donc 5 - le nombre de dé a avoir
    #resultat au dessu * 1/6 power le nombre de dé a avoir * 5∕6 puissance le nombre de dé - le nombre de dé a avoir