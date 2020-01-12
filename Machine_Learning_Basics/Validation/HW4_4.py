import numpy as np
import random
import matplotlib.pyplot as plt
X=[]
with open("X_train.txt") as train_x:
    for line in train_x:
        element = [float(feature.strip()) for feature in line.split(',')]
        X.append(element)
X = np.asarray(X)

y=[]
with open("y_train.txt") as train_y:
    for line in train_y:
        element = [float(feature.strip()) for feature in line.split(',')]
        y.append(element)
Y = np.asarray(y)

XTX=np.dot(X.transpose(),X)
XTX_I=np.linalg.inv(XTX)
w = XTX_I.dot(X.transpose()).dot(Y)

test_X = []
with open("X_validation.txt") as test_x:
    for line in test_x:
        element = [float(feature.strip()) for feature in line.split(',')]
        test_X.append(element)
test_X = np.asarray(test_X)

test_y=[]
with open("y_validation.txt") as val_y:
    for line in val_y:
        element = [float(feature.strip()) for feature in line.split(',')]
        test_y.append(element)
test_Y = np.asarray(test_y)

index = random.sample(range(len(test_y)),10)
risk=[]
for i in index:
    pred = np.dot(test_X[i],w)
    error = (test_y[i]-pred)**2
    risk.append(error)
empirical_risk = np.mean(risk)
print(empirical_risk)

'''
empirical_risk=[]
for i in range(100):
    index = random.sample(range(len(test_y)),10)
    risk=[]
    for j in index:
        pred = np.dot(test_X[j],w)
        error = (test_y[j]-pred)**2
        risk.append(error)
    er = np.mean(risk)
    empirical_risk.append(er)

plt.hist(empirical_risk)
plt.xlabel("prediction error")
plt.ylabel("count")
plt.title("Histogram of the prediction error")
plt.show()
'''
