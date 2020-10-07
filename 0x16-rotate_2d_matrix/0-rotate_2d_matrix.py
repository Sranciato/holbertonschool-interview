#!/usr/bin/python3
''' Rotate 2d matrix '''


def rotate_2d_matrix(matrix):
    ''' Rotates a 2D matrix 90 degrees '''
    if not matrix or len(matrix) == 0:
        return
    n = len(matrix)
    for i in range(n // 2):
        print(matrix[i])
        for j in range(i, n - i - 1):
            print(matrix[i][j])
            tmp = matrix[i][j]
            matrix[i][j] = matrix[n - j - 1][i]
            matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1]
            matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1]
            matrix[j][n - i - 1] = tmp
