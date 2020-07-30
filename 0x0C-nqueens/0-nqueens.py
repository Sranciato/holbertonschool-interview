#!/usr/bin/python3
"""N Queens"""
import sys


def solve_NQ(n):
    grid = []
    for row in range(0, n):
        solve(n, 0, row, grid)
    for solution in grid:
        print(solution)


def solve(n, col, row, grid, sol=[]):
    if safe(col, row, sol) is False:
        return
    s = sol.copy()
    s.append([col, row])
    if col == n - 1:
        grid.append(s)
    for i in range(0, n):
        solve(n, col + 1, i, grid, s)


def safe(col, row, sol):
    for index in sol:
        if index[0] == col or index[1] == row:
            return False
        if index[0] - index[1] == col - row:
            return False
        if index[0] + index[1] == col + row:
            return False
    return True


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        exit(1)
    try:
        n = int(sys.argv[1])
    except Exception:
        print("N must be a number")
        exit(1)
    if n < 4:
        print("N must be at least 4")
        exit(1)
    solve_NQ(n)
