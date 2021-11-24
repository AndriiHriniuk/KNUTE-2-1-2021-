from scipy import integrate
from numpy import*
def f(x):
    return 1 / sqrt(0.5 * x + 2)

def f1(x):
    return sin(2 * x) / pow(x, 2)

def f2(x):
    return 1 / (12 * pow(x, 2) + 0.5)

v,err = integrate.quad(f, 0.4, 1.2)
v1,err = integrate.quad(f1, 0.8, 1.2)
v2,err = integrate.quad(f2, 0.6, 1.4)
print('Proverka Priamokutnik', v)
print('Proverka Simpson', v1)
print('Proverka Trapetsiya', v2)

def prR(f, a, b, n):
    i = 1
    sum = f(b)
    h = (b - a) / n
    while i < n:
        b = b - h
        sum = f(b) + sum
        i = i + 1
    return sum * h 
print('Metod Right Priam', prR(f, 0.4, 1.2, 8))

def prL(f, a, b, n):
    i = 1
    h = (b - a) / n
    sum = f(a)
    while i < n:
        a = a + h
        sum = f(a) + sum
        i = i + 1
    return sum * h 
print('Metod Left Priam', prL(f, 0.4, 1.2, 8))

def prM(f, a, b, n):
    i = 1
    h = (b - a) / n
    sum = f(a + h / 2)
    while i <= n:
        a = a + h + h / 2
        sum = f(a) + sum
        i = i + 1
    return sum * h 
print('Metod Midle Priam', prM(f, 0.4, 1.2, 8))

def prS(f1, a, b, n):
    i = 0
    h = (b - a) / n
    sum = f1(a) + f1(b)
    while i < n:
        a = a + h # ne parni
        i = i + 1
        if i == n:
            return sum * (h / 3);  
        sum = f1(a) * 4  + sum 
        a1 = a + h # parni
        i = i + 1
        if i == n:
            return sum * (h / 3);  
        sum = sum + f1(a1) * 2
    return sum * (h / 3)
print('Metod Simpson', prS(f1, 0.8, 1.2, 2))

def prT(f2, a, b, n):
    i = 0
    h = (b - a) / n
    sum = f2(a) / 2 + f2(b) / 2
    while i < n:
        a = a + h
        i = i + 1
        if i == n:
            return sum * h
        sum = sum + f2(a)
    return sum * h
print('Metod Trapetsii', prT(f2, 0.6, 1.4, 20))