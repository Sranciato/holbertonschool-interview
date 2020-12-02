#!/usr/bin/python3
"""returns the perimeter of the island"""


def island_perimeter(grid):
    """return the perimeter of the island"""
    count = lis = val = check = 0

    for lis in range(len(grid)):
        for val in range(len(grid[0])):
            if grid[lis][val] == 1:
                if lis - 1 == -1:
                    count += 1
                elif grid[lis - 1][val] == 0:
                    count += 1
                if val - 1 == -1:
                    count += 1
                elif grid[lis][val - 1] == 0:
                    count += 1
                if val + 1 == len(grid[0]):
                    count += 1
                elif grid[lis][val + 1] == 0:
                    count += 1
                if lis + 1 == len(grid):
                    count += 1
                elif grid[lis + 1][val] == 0:
                    count += 1

    return count
