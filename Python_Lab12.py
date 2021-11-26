import math
import numpy as np
import matplotlib.pyplot as plt
#𝑓(𝑥) = x * sin(x)
def f(x):
    return x * math.sin(x)

x = np.array([0.1, 0.15, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.47, 0.5])
y = np.array(range(len(x)), float)
x2 = np.array(range(len(x)), float)
xy = np.array(range(len(x)), float)
fx = np.array(range(len(x)), float)

i = 0
ymid = 0 
xmid = 0
x2mid = 0
xymid = 0
while i <= len(x) - 1:
    xmid += x[i]
    y[i] = f(x[i])
    ymid += y[i]
    x2[i] = pow(x[i],2)
    x2mid += x2[i]
    xy[i] = x[i] * y[i]
    xymid += xy[i]
    i = i + 1

ymid /= len(x)
xmid /= len(x)
x2mid /= len(x)
xymid /= len(x)

print(' x(n):\n', x, '\nmidle x =', xmid)
print(' y(n):\n', y, '\nmidle y =', ymid)
print(' x^2(n):\n', x2, '\nmidle x^2 =', x2mid)
print(' xy(n):\n', xy, '\nmidle xy =', xymid)

a1 = (xymid - xmid * ymid) / (x2mid - pow(xmid, 2))
a0 = ymid- a1 * xmid
print(' a1 =', a1, '\n a0 =', a0)

i = 0
while i <= len(x) - 1:
    fx[i] = a0 + a1 * x[i]
    i = i + 1

print(' fx(n):\n', fx)

plt.title("Метод наименьших квадратов.\n f(x) = x * sin(x)")
plt.plot(x,fx, label = 'f(x) = a0 + a1 * x')
plt.plot(x,y, label = 'f(x) = x * sin(x)')
plt.grid()
plt.legend()
plt.show()