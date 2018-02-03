from PIL import Image
import matplotlib.pyplot as plt
import numpy as np
from sklearn.model_selection import StratifiedKFold
from sklearn.model_selection import cross_val_score,cross_val_predict
from sklearn.linear_model import SGDClassifier
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import log_loss
def open_image(name):
    image = Image.open(name)
    return image

def get_pixels(image,r):
    img = image.load()
    pixels = []
    for i in range(r):
        for j in range(r):
            color = img[i, j]
            pixels.append(color[0])
            pixels.append(color[1])
            pixels.append(color[2])
    return pixels

def gradient(x,y,w):
    dec = 1+np.exp(y*np.dot(x,w))
    grad = (-y*x.transpose())/dec
    return grad

def gradient_descent(x,y,w):
    for i in range(0, 8000):
        grad = []
        for j in range(len(x)):
            grad.append(gradient(x[j],y[j],w))
        grad_mean = np.mean(grad)
        w = w - 1e-9 * grad_mean
    return w

def risk(y, y_pred): 
    L =0
    for i in range(len(y)):
        L = L + np.log(1+np.exp(-y_train[i]*y_pred[i]))
    return L


r = [1,10,20,50,100,200]
clf = LogisticRegression()
training_error=[]
val_error=[]

for i in range(len(r)):
    autumn = []
    winter = []
    X = []
    y = []
    for n in range(1, 11):
        im = open_image('WinterFall\\autumn'+str(n)+'.jpg')
        pixels = get_pixels(im,r[i])
        X.append(pixels)
        y.append(1)
        autumn.append(pixels)
    autumn = np.array(autumn)

    for n in range(1, 11):
        im = open_image('WinterFall\\winter'+str(n)+'.jpg')
        pixels = get_pixels(im,r[i])
        X.append(pixels)
        winter.append(pixels)
        y.append(-1)
    winter = np.array(winter)

    X = np.array(X)
    y = np.array(y)
    Y = np.array([y]).transpose()
   
    train_loss = []
    test_loss = []
    kf = StratifiedKFold(n_splits=5)
    for train, test in kf.split(X,y):
        X_train,X_test = X[train], X[test]  
        y_train,y_test = y[train], y[test]

        clf.fit(X_train,y_train)
        y_train_pred = clf.predict_proba(X_train)
        y_test_pred = clf.predict_proba(X_test)
        lltrain = log_loss(y_train,y_train_pred)
        lltest = log_loss(y_test,y_test_pred)
        train_loss.append(lltrain)
        test_loss.append(lltest)

    training_error.append(np.mean(train_loss))
    val_error.append(np.mean(test_loss))
print(training_error,val_error)


f,(ax1,ax2)=plt.subplots(1,2)
ax1.plot(r,training_error,marker='o')
ax1.set_title("training error")
ax1.set_xlabel("r")
ax1.set_ylabel("error")
ax2.set_title("testing error")
ax2.set_xlabel("r")
ax2.set_ylabel("error")
ax2.plot(r,val_error,marker='o')
plt.show()

