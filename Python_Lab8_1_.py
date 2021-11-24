import math
from array import*
import numpy as np
arrayX = np.array([0, 0.1, 0.2, 0.3, 0.4, 0.5])
arrayY = np.array([1.2733, 1.8007, 2.3606, 2.9577, 3.5969, 4.2833])
arrayDy1 = np.array(range(len(arrayX) - 1), float)
arrayDy2 = np.array(range(len(arrayX) - 2), float)
arrayDy3 = np.array(range(len(arrayX) - 3), float)
arrayDy4 = np.array(range(len(arrayX) - 4), float)
i = 0
size = len(arrayX)

print('n =')
n = int(input())

while i != size - 1:
    arrayDy1[i] = arrayY[i + 1] - arrayY[i]
    i = i + 1
i = 0
while i != size - 2:
    arrayDy2[i] = arrayDy1[i + 1] - arrayDy1[i]
    i = i + 1
i = 0
while i != size - 3:
    arrayDy3[i] = arrayDy2[i + 1] - arrayDy2[i]
    i = i + 1
i = 0
while i != size - 4:
    arrayDy4[i] = arrayDy3[i + 1] - arrayDy3[i]
    i = i + 1
i = 0


while i <= size - 1:
    print(' x', i,' = ', arrayX[i])
    i = i + 1
    if i == size:
        print('\n')
i = 0
while i <= size -1:
    print(' y', i,' = ', arrayY[i])
    i = i + 1
    if i == size:
        print('\n')

i = 0
while i <= size - 2:
    print(' /\y1( y', i,') = ', arrayDy1[i])
    i = i + 1
    if i == size - 1:
        print('\n')
i = 0
while i <= size - 3:
    print(' /\y2( y', i,') = ', arrayDy2[i])
    i = i + 1
    if i == size - 2:
        print('\n')
i = 0
while i <= size - 4:
    print(' /\y3( y', i,') = ', arrayDy3[i])
    i = i + 1
    if i == size - 3:
        print('\n')
i = 0
while i <= size - 5:
    print(' /\y4( y', i,') = ', arrayDy4[i])
    i = i + 1
    if i == size - 4:
        print('\n')
yl = (1 / (arrayX[n + 1] - arrayX[n]))  * (arrayDy1[n] - (arrayDy2[n] / 2) + (arrayDy3[n] / 3) - (arrayDy4[n] / 4))
yll = (1 / pow((arrayX[n + 1] - arrayX[n]), 2))  * (arrayDy2[n] - arrayDy3[n] + (11 / 12 * arrayDy4[n]))
print(' y` =', yl, '\n y`` =', yll)

