#!/usr/bin/python3
import random
import sys
 
a = int(sys.argv[1])
for i in random.sample(range(100), a) :
    print(i, end=' ')
