#!/usr/bin/python3
"""method that determines if a given data set represents a valid UTF-8"""


def validUTF8(data):
    """method that determines if a given data set represents a valid UTF-8"""
    count_leading_1 = 0
    for b in data:
        b = bin(b).replace('0b', '')
        while len(b) < 8:
            b = '0' + b
        if count_leading_1 != 0:
            count_leading_1 -= 1
            if not b.startswith('10'):
                return False
        elif b[0] == '1':
            i = 0
            while b[i] == '1':
                count_leading_1 += 1
                i += 1
            count_leading_1 -= 1
    return True
