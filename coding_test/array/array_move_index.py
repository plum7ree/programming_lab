


import functools
from typing import List


def move(dx: int, dy: int, curr_x: int, curr_y: int, arr: List[List[int]]):
    N_ROWS = len(arr)
    N_COLS = len(arr[0])
    next_x = curr_x + dx
    next_y = curr_y + dy
    if next_y < 0 or next_y > N_ROWS:
        return
    if next_x < 0 or next_x > N_COLS:
        return
    return arr[next_y][next_x]

def move_x(dx, curr_x, curr_y, arr):
    return move(move, dx, 0, curr_x, curr_y, arr)

def move_y(dx, curr_x, curr_y, arr):
    return move(move, 0, dy, curr_x, curr_y, arr)

# 1. wrapping function
arr = [[1,2,3],[4,5,6],[7,8,9]]
print(move(-1,0,1,1,arr))

# 2. partial example
partial_move_x = functools.partial(move, dy=0)
arr = [[1,2,3],[4,5,6],[7,8,9]]
print(partial_move_x(dx=-1, curr_x=1, curr_y=1, arr=arr))

