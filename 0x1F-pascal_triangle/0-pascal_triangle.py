#!/usr/bin/python3
""" Pascal's Triangle """


def pascal_triangle(n):
    """ returns a list of lists of integers """
    list = []

    for i in range(1, n + 1, 1):
        row = [1] * i
        for j in range(i):
            if j != 0 and j != i - 1:
                row[j] = list[i - 2][j] + list[i - 2][j - 1]
        list.append(row)

    return list
