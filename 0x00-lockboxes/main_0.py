#!/usr/bin/python3

canUnlockAll = __import__('0-lockboxes').canUnlockAll

# boxes = [[1], [-5, 2], [3], [4], []]
# print(canUnlockAll(boxes))

# boxes = [[1, 4, 6], [2], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6]]
# print(canUnlockAll(boxes))

# boxes = [[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]]
# print(canUnlockAll(boxes))

boxes = [[3], [2], [], [1]]
print(canUnlockAll(boxes))

# boxes = [[1,3,5], [0, 4, 1], [], [], [], [1]]
# print(canUnlockAll(boxes))