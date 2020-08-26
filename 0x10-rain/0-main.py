#!/usr/bin/python3
"""
0_main
"""
rain = __import__('0-rain').rain

if __name__ == "__main__":
    walls = [1, 0, 0, 2, 0, 3, 0, 4]
    print(rain(walls))
