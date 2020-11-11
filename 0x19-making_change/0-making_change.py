#!/usr/bin/python3
"""
Given a pile of coins of different values, determine the
fewest number of coins needed to meet a given amount
"""


def makeChange(coins, total):
    """
    Find the minimum number of coins needed
    """
    count = 0
    if total <= 0: 
        return 0

    coins.sort(reverse = True)
    for coin in coins:
        if total % coin < total:
            count += total // coin
            total = total % coin
    
    if total == 0:
        return count
    return -1
