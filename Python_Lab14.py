# a) y' = x + cos(y / 2.25)          y(1.4) = 2.2    [1.4; 2.4]     - Метод Эйлeра
# b) y' = x + sin(y / sqrt(10))      y(0.6) = 0.8    [0.6; 1.6]     - Метод Эйлера-Коши  
# h = 0.1    q = 0.0001    i = 10

import math
import numpy as np
import matplotlib.pyplot as plt

xi = 1.4
xmax = 2.4
yi = 2.2
i = 0
h = 0.1
x = np.array(range(int((xmax - xi)/h+1)), float)
y = np.array(range(len(x)), float)

while xi <= xmax + h:
    print(i, '   ', xi, '   ', yi)
    if xi == yi:
        break;
    x[i] = xi
    y[i] = yi
    xi = xi + h
    i = i + 1
    yi = yi +  h * (xi + math.cos(yi / 2.25))

print('\n')
xi = 0.6
xmax = 1.6
yi = 0.8
i = 0

x1 = np.array(range(int((xmax - xi)/h+1)), float)
y1 = np.array(range(len(x)), float)

while xi <= xmax + h:
    print(i, '   ', xi, '   ', yi)
    if xi == xmax:
        break;
    x1[i] = xi
    y1[i] = yi
    xi = xi + h
    i = i + 1
    yi = yi +  (h/2) * (yi + (xi + math.sin(yi/math.sqrt(10))))

plt.plot(x, y, label = 'y = y + h * (x + cos(y / 2.25))',marker = 'o')
plt.grid()
plt.title('Метод Эйлeра')
plt.legend()
plt.show()

plt.plot(x, y, label = 'y = y + h/2 * (y + (x + siny / sqrt(10)))',marker = 'o')
plt.grid()
plt.title('Метод Эйлeра Коши')
plt.legend()
plt.show()