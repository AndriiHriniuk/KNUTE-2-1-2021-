import math
from array import*
import numpy as np
arrayX = np.array([1.5, 2.0, 2.5, 3.0, 3.5, 4.0])
arrayY = np.array([10.517, 10.193, 9.807, 9.387, 8.977, 8.637])
arrayDy1 = np.array(range(5), float)
arrayDy2 = np.array(range(4), float)
arrayDy3 = np.array(range(3), float)
arrayDy4 = np.array(range(2), float)
i = 0
#print(' i     ', 'x     ', 'y       ', '/\y1       ', '/\y2       ', '/\y3       ', '/\y4       \n')
while i != 5:
    arrayDy1[i] = arrayY[i + 1] - arrayY[i]
    i = i + 1
i = 0
while i != 4:
    arrayDy2[i] = arrayDy1[i + 1] - arrayDy1[i]
    i = i + 1
i = 0
while i != 3:
    arrayDy3[i] = arrayDy2[i + 1] - arrayDy2[i]
    i = i + 1
i = 0
while i != 2:
    arrayDy4[i] = arrayDy3[i + 1] - arrayDy3[i]
    i = i + 1
i = 0
while i <= 5:
    print(' x', i,' = ', arrayX[i])
    i = i + 1
    if i == 6:
        print('\n')
i = 0
while i <= 5:
    print(' y', i,' = ', arrayY[i])
    i = i + 1
    if i == 6:
        print('\n')

i = 0
while i <= 4:
    print(' /\y1( y', i,') = ', arrayDy1[i])
    i = i + 1
    if i == 5:
        print('\n')
i = 0
while i <= 3:
    print(' /\y2( y', i,') = ', arrayDy2[i])
    i = i + 1
    if i == 4:
        print('\n')
i = 0
while i <= 2:
    print(' /\y3( y', i,') = ', arrayDy3[i])
    i = i + 1
    if i == 3:
        print('\n')
i = 0
while i <= 1:
    print(' /\y4( y', i,') = ', arrayDy4[i])
    i = i + 1
    if i == 2:
       print('\n') 
yl = (1 / (arrayX[1] - arrayX[0]))  * (arrayDy1[0] - (arrayDy2[0] / 2) + (arrayDy3[0] / 3) - (arrayDy4[0] / 4))
yll = (1 / pow((arrayX[1] - arrayX[0]), 2))  * (arrayDy2[0] - arrayDy3[0] + (11 / 12 * arrayDy4[0]))
print(' y` =', yl, '\n y`` =', yll)
