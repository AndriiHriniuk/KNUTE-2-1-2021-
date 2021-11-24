import math
def F(x):
    return x ** 4 + 2 * x ** 3 + 2 * x ** 2 + 6 * x - 3

def F1(x):
    return 4 * x ** 3 + 6 * x ** 2 + 4 * x + 6 

def F2(x):
    return 12 * x ** 2 + 12 * x + 4

def metN(a, b):
    f =  F1(b)
    f2 = F2(b)
    if f * f2 > 0:
        x = b
    else:
        x = a
    
    while F(b) / F1(b) <= 0.0001:
        f =  F(x)
        f1 = F1(x)
        h = f / f1
        x = x - h
        
    f = F(x)
    return print ('Metod N =', f, '\nx = ', x)
metN(0, 6)