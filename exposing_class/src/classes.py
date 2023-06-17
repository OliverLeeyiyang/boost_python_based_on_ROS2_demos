#!/usr/bin/env python

import classes

t1 = classes.RealWorld("Xiangdi", 'm')

t1.Welcome()
t1.SetAge(20)
print (t1.name, "'s age is ", t1.age, "sex is ", t1.sex)

t1.name = "Xiaoming"
# t1.sex = 'f'                # sex has no set function, so can't be setted
t1.age = 25
print (t1.name, "'s age is ", t1.age, "sex is ", t1.sex)
