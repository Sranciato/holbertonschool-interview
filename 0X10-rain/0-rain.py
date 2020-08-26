#!/usr/bin/python3


def rain(walls):
    """ calculate how much water will be retained after it rains """
    if not walls:
        return 0
    res = 0
    size = len(walls)

    for i in range(1, size - 1):
        left = walls[i]
        for j in range(i):
            left = max(left, walls[j])
        right = walls[i]

        for j in range(i + 1, size):
            right = max(right, walls[j])
        res = res + (min(left, right) - walls[i])

    return res
