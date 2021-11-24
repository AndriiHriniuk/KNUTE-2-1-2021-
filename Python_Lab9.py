import numpy as np
import math
from math import factorial
from numpy import*
import matplotlib.pyplot as plt

mas_x=[0, 0.2, 0.4, 0.6, 0.8, 1]
mas_y=[1.2715, 2.4652, 3.6443, 4.8095, 5.9614, 7.1005]
h = mas_x[1] - mas_x[0]

def y(mas_y, j):
    mas=[]
    for i in range(len(mas_y)):
        mas.append(mas_y[i] - mas_y[i-1])
    mas.pop(0)
    if j == 1:
        return mas
    else:
        j-=1
        return y(mas, j)

q = (mas_x[1] - 0.1) / h
print(q)
yx1= mas_y[0] + q * (y(mas_y,1)[0]) + (q * (q - 1)) / factorial(2) *  (y(mas_y,2)[0])
yx1 = yx1 + (q * (q - 1) * (q - 2)) / factorial(3) * (y(mas_y,3)[0])
yx1 = yx1 + (q * (q - 1) * (q - 2)) * (q - 3) / factorial(4) * (y(mas_y,4)[0])
yx1 = yx1 + (q * (q - 1) * (q - 2)) * (q - 3) * (q - 4) / factorial(5) * (y(mas_y,5)[0])


yx2 = mas_y[4] + q * (y(mas_y, 1)[3]) + (q * (q + 1) * (q + 2)) / factorial(3) * (y(mas_y,3)[2])
yx2 = yx2 + (q * (q + 1) * (q + 2) * (q + 3) / factorial(4) * (y(mas_y,4)[1]))
yx2 = yx2 + (q * (q + 1) * (q + 2) * (q + 3) * (q + 4) / factorial(5) * (y(mas_y,5)[0]))

print ("N1 = ",yx1)
print ("N1 = ",yx2)

x = linspace(0, 1, len(mas_x))
y = mas_y
plt.plot(x, y, 'g--', color = 'red')
plt.scatter(linspace(0, 1, len(mas_x)), mas_y, color = 'orange', marker = 'o')
plt.xticks(np.linspace(0, 1.3, 14))
plt.yticks(np.linspace(0, 7.2, 19)) 
plt.axis([0, 1.3, 0, 7.2]) 
plt.xlabel('x')
plt.ylabel('y')
plt.title('Polinom Nutona')
plt.legend(['N(x)'])
plt.grid(linestyle = '--')
plt.show()