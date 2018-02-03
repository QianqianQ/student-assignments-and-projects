import numpy as np
from scipy.stats import norm
import matplotlib.pyplot as plt

data_set = []
for i in range(100):
    samples = norm.rvs(loc=0, scale=1, size=10, random_state=None)
    z = np.array([samples]).transpose()
    data_set.append(z)    
u = np.array([[1, 0, 0, 0, 0, 0, 0, 0, 0, 0]]).transpose()
v = np.array([[9/10,1/10,0,0,0,0,0,0,0,0]]).transpose()
x1=[]
x2=[]
for i in range(100):
    tempx1 = np.dot(u.transpose(),data_set[i])
    tempx2 = np.dot(v.transpose(),data_set[i])
    x1.append(tempx1)
    x2.append(tempx2)
plt.scatter(x1,x2,edgecolors='b')
plt.xlabel(r'$x_{1}$')
plt.ylabel(r'$x_{2}$')
plt.title("Scatter plot with the points "+r"$\bf{x}$")
plt.show()
