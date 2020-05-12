#!/usr/bin/python3
""" function for returning min operations """
def minOperations(n):
    """ returns min operations """
    res = 0

    for i in range(2, n):
        while n % i == 0:
            res += i
            n = n / i
    return res