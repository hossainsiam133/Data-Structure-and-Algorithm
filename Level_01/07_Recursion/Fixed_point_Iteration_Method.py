# fixed point iteration method
from math import *
root = -1

def func(x0, x1):
    if x0 == x1:
        global root
        root = x0
        return 0
    return func(1 / sqrt(x0 + 1), x0)+1


iteration = func(0.5, -1)

value = root**3 + root**2 - 1
decimal_digits = len(str(root).split('.')[1])

print("Iterations:", iteration)
print("Digits after decimal:", decimal_digits)
print("Root:", root)
print("Function value at root:", value)