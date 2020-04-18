#!/usr/bin/python3


def canUnlockAll(list):
    """ returns true if all boxes can be unlocked """
    length = len(list)
    count = 1
    for box_index in range(length):
        for key_index in range(len(list[box_index])):
            try:
                nextBox = list[list[box_index][key_index]]
            except Exception as e:
                continue
            if len(nextBox) == 0 and count == length - 1:
                return True
            try:
                del list[box_index][key_index]
                count += 1
            except Exception as e:
                pass
            box_index = nextBox
    return False
