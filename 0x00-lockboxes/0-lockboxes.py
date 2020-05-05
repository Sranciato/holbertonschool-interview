#!/usr/bin/python3


def canUnlockAll(list):
    """ returns true if all boxes can be unlocked """
    length = len(list)
    count = 1
    for box_index in range(length):
        for key_index in range(len(list[box_index])):
            print(key_index)
            print(list)
            try:
                nextBox = list[list[box_index][key_index]]
            except Exception as e:
                continue
            if len(nextBox) == 0 and count == length - 1:
                return True
            elif len(nextBox) == 0 and count != length - 1:
                print("HEYY {}".format(len(list[box_index])))
                # if (len(list[box_index]) == 1):
                #     return False
                continue
            try:
                del list[box_index][key_index]
                count += 1
            except Exception as e:
                pass
            box_index = nextBox
            print("after {}".format(list))

    print("FINAl list {}".format(list))
    print("final count {}".format(count))
    if (count == length):
        return True
    return False
