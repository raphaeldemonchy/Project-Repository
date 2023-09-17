##
## EPITECH PROJECT, 2023
## Math
## File description:
## 203hotline
##

import sys
from math import *
from time import time
from math import factorial

#_________________________________________________________________#
#--------------------------MATH FUNC------------------------------#
def my_binomial(n: int, k: int) -> int:
    res = factorial(n) // (factorial(k) * factorial(n - k))
    return (res)

def my_overload(l: list) -> float:
    return 1 - sum(l[:26])

#_________________________________________________________________#
#--------------------------FOR1-----------------------------------#


def bi_distrib(input: int, p: float, timer: float):
    max = 320
    bi_list = [my_binomial(3500, a) * p**a * (1-p)**(3500-a) for a in range(0, (50 + 1))]
    for a, bi_value in enumerate(bi_list):
        print(f"{a:d} -> {bi_value:.3f}", end="")
        if (a+1) % 5 == 0:
            print()
        elif a != 50:
            print("\t", end="")
    if input > max:
        print("\nOverload: 100%")
    else:
        print(f"\nOverload: {my_overload(bi_list) * 100:.1f}%")
    print(f"Computation time: {(time()-timer) * 100:.2f} ms")

def po_distrib(p: float, timer: float):
    max = 320
    bi_list = []
    for a, a_a in enumerate(range(0, (50 + 1))):
        bi_list.append(exp(-p) * pow(p, a) / factorial(a))
        print("{:d} -> {:0.3f}".format(a, bi_list[-1]), end='')
        if (a + 1) % 5 == 0:
            print()
        elif a != 50:
            print("\t", end='')
    if max > 320:
        print("\nOverload: 100%")
    else:
        print(f"\nOverload: {my_overload(bi_list) * 100:.1f}%")
    print(f"Computation time: {(time()-timer) * 100:.2f} ms")

def for1arg(arg1 : int):
    n = arg1
    timer = time()
    p_b = n / (3600 * 8)
    p_p = 3500 * (n / (3600 * 8))
    print("Binomial distribution:")
    bi_distrib(n, p_b, timer)
    print()
    print("Poisson distribution:")
    po_distrib(p_p, timer)


#_________________________________________________________________#
#------------------------------FOR2-------------------------------#

def for2arg(arg1 : int, arg2 : int) -> int:
    res = my_binomial(int(arg1), int(arg2))
    print(f"{arg2}-combinations of a set of size {arg1}:")
    print(res)

#________________________________________________________________________________________#
#------------------------------MAIN FUNC-------------------------------------------------#
def usage():
    print("USAGE")
    print("\t./203hotline [n k | d]\n")
    print("DESCRIPTION")
    print("\tn\tn value for the computation of C(n, k)")
    print("\tk\tk value for the computation of C(n, k)")
    print("\td\taverage duration of calls (in seconds)")

if __name__ == "__main__":
    try:
        if len(sys.argv) == 2:
            if sys.argv[1] == "-h":
                usage()
            else:
                try:
                    arg = int(sys.argv[1])
                    for1arg(arg)
                except ValueError:
                    raise BaseException("ERROR : Argument must be an integer")
        elif len(sys.argv) == 3:
            for2arg(int(sys.argv[1]), int(sys.argv[2]))
        else:
            raise BaseException("ERROR : Invalid arg : use [-h]")
    except BaseException as error:
        print(str(error))
        sys.exit(84)
        