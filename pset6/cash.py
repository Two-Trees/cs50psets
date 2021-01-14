from cs50 import get_float
import math

dollars = get_float("what is your change?\n")

change = (dollars * 100)

q = change // 25

afterQuarters = change % 25

d = afterQuarters // 10

afterDimes = afterQuarters % 10

n = afterDimes // 5
    
afterNickels = afterDimes % 5

p = afterNickels // 1
    
totalCoins = math.floor(q + d + n + p)

print(totalCoins)