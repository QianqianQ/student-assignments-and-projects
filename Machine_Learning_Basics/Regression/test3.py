from PIL import Image
import scipy
import matplotlib.pyplot as plt
import numpy as np
import theano 
from theano import tensor as T
from scipy.spatial.distance import pdist, squareform
from PIL import Image
import matplotlib.pyplot as plt
import numpy as np
from scipy.misc import logsumexp
from scipy.interpolate import Rbf,InterpolatedUnivariateSpline
from sklearn.neighbors import KNeighborsRegressor
from sklearn.svm import SVR
from sklearn.metrics.pairwise import pairwise_kernels
from kernel_regression import KernelRegression
import sklearn
def open_image(name):
    image = Image.open(name)
    return image

def get_greenness(image):
    img = image.load()
    width, height = image.size
    greenness = 0
    for i in range(width):
        for j in range(height):
            color = img[i, j]
            greenness += (color[1])
    total_pixel = width*height
    normalized_greenness = greenness/total_pixel
    return normalized_greenness
# this is an NxD matrix, where N is number of items and D its dimensionalites
if __name__ == "__main__":
    y = [211,271,121,31,341,401,241,181,301,301]
    y_matrix = np.array([y]).transpose()
    x = []
    for n in range(1, 11):
        im = open_image("MontBlanc"+str(n)+".png")
        green = get_greenness(im)
        x.append(green)
    x_matrix = np.array([x]).transpose()
    '''svr_rbf_1 = SVR(kernel='rbf', C=1e3, gamma=0.5)
    svr_rbf_2 = SVR(kernel='rbf', C=1e3, gamma=1/50)
    svr_rbf_3 = SVR(kernel='rbf', C=1e3, gamma=1/200)
    xpred = np.array([np.arange(0,255,0.1)]).transpose()
    y_rbf1 = svr_rbf_1.fit(x_matrix, y).predict(xpred)
    y_rbf2= svr_rbf_2.fit(x_matrix, y).predict(xpred)
    y_rbf3= svr_rbf_3.fit(x_matrix, y).predict(xpred)
    plt.scatter(x,y)
    plt.plot(xpred,y_rbf1)
    plt.plot(xpred,y_rbf2)
    plt.plot(xpred,y_rbf3)
    plt.legend()
    plt.show()
    print(np.shape(np.logspace(-2, 2, 10)))
    total_cost =0
    for i in range(len(y)):
        total
'''
    K = pairwise_kernels(x_matrix,metric="rbf",gamma=0.5)
    K2 = pairwise_kernels(x_matrix,metric="rbf",gamma=1/50)
    print(K)
    model = K*y_matrix[:,None].sum(axis=0)/K.sum(axis=0)
    print(np.shape(K.sum(axis=1)))
    print(np.shape(model))
    Ky = K * y_matrix
    Ky2 = K2 * y_matrix
    y_pred = Ky.sum(axis=0) / K.sum(axis=0)
    y_pred2 = Ky2.sum(axis=0) / K2.sum(axis=0)
    print(np.shape(y_pred))
    plt.scatter(x,y)
    plt.scatter(x,y_pred)
    plt.scatter(x,y_pred2)
    plt.show()
    '''
    X = np.sort(5 * np.random.rand(100, 1), axis=0)
    y = np.sin(X).ravel()
    print(np.shape(X),np.shape(y))'''