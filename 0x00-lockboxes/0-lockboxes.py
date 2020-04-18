#!/usr/bin/python3

def canUnlockAll(list):
    length = len(list)
    count = 1
    for box_index in range(length):
        for key_index in range(len(list[box_index])):
            try:
                nextBox = list[list[box_index][key_index]]
            except:
                continue
            if len(nextBox) == 0 and count == length - 1:
                return True
            try:
                del list[box_index][key_index]
                count += 1
            except:
                pass
            box_index = nextBox
            
        
    return False
        