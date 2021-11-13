#This file generates input for sort.cpp
import random
n=int(input("Enter input size:"))
input_size = n
f = open("input.txt", "w")
f.write(str(input_size))

for i in range(input_size):
    x = random.randint(-input_size, input_size)
    f.write(" ")
    f.write(str(x))