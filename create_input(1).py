#This file generates input for graphs
import random
n=int(input("Enter input size:"))
input_size = n
f = open("input.txt", "w")
f.write(str(input_size))

for i in range(input_size):
    v = random.randint(1, 100*n)
    if(v<10):
    	e = random.randint(0,(v*(v-1))/2)
    else:
    	e = random.randint(0,5*v)
    f.write(" ")
    f.write(str(v))
    f.write(" ")
    f.write(str(e))
    # print(e)
    for j in range(e):
    	a = random.randint(1, int(v))
    	b = random.randint(1, v)
    	if(b==a):
    		b=b%v+1
    	f.write(" ")
    	f.write(str(a))
    	f.write(" ")
    	f.write(str(b))