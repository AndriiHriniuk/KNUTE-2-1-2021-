from sympy import *
import numpy as np
import matplotlib.pyplot as plt
#𝑓(𝑥) = x * sin(x)
x = Symbol('x')
y = x * sin(x) 
def poh(y,x):
    yprime = y.diff(x)
    return yprime
print(' Введите число n')
n = int(input())
i = 0
print(' Производные функции f(x) =', y)
while i < n:
    y = poh(y,x)
    print(' f', i+1, '(x) =', y)
    i = i + 1
x = np.linspace(1, 4, 100)
y = x * np.sin(x)
y2 = x ** 2
y3 = x ** 2 - (x ** 4) / 6

plt.title("Метод Тейлора\n f(x) = x * sin(x)")
plt.xlim(1, 4)
plt.ylim(-4, 4)

plt.plot(x, y, label='x * sin(x)')
plt.plot(x, y2, label='x^2')
plt.plot(x, y3, label='x^2 - x^4 / 6')
plt.grid()
plt.legend()
plt.show()
