import matplotlib.pyplot as plt
from scipy.interpolate import UnivariateSpline
from numpy import *
x = [0.1, 0.3, 0.6, 1.1, 1.8]
y = [2.65, 2.75, 2.19, 1.76, 3.43]
spl = UnivariateSpline(x, y)
xs = linspace(0, 5, 50)
plt.plot(x, y, 'ro', xs, spl(xs), 'g')
plt.grid()
plt.show()
