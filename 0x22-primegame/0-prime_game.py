#!/usr/bin/python3
"""0x22. Prime Game"""


def primeNumbers(n):
    """Returns prime numbers"""
    list_primes = []
    i = 1
    while i < n:
        prime = 1
        i += 1
        for num in list_primes:
            if not i % num:
                prime = 0
                break
        if prime:
            list_primes.append(i)
    return list_primes


def isWinner(x, nums):
    """Returns name of player with most wins"""
    winners = [0, 0]
    if (len(nums) < x):
        return None
    i = 0
    for n in nums:
        if i == x:
            break
        winners[len(primeNumbers(n)) % 2] += 1
        i += 1
    if winners[0] == winners[1]:
        return None
    if winners[0] < winners[1]:
        return 'Maria'
    return 'Ben'
