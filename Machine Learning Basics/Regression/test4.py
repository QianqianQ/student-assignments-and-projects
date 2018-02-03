from math import exp,sqrt,pi
from PIL import Image
import scipy
import matplotlib.pyplot as plt
import sklearn_extensions as ske
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
from sklearn_extensions.kernel_regression import KernelRegression
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
def fit(test_X, train_X, train_y, bandwidth=1.0, kn='box'):
    kernels = {
        'box': lambda x: 1/2 if (x<=1 and x>=-1) else 0,
        'gs': lambda x: 1/sqrt(2*pi)*exp(-x**2/22),
        'ep': lambda x: 3/4*(1-x**2) if (x<=1 and x>=-1) else 0
    }
    predict_y = []
    for entry in test_X:
        nks = [np.sum((j-entry)**2)/bandwidth for j in train_X]
        ks = [kernels['box'](i) for i in nks]
        dividend = sum([ks[i]*train_y[i] for i in range(len(ks))])
        divisor = sum(ks)
        predict = dividend/divisor
        predict_y.extend(predict)
        # print(entry)
    return np.array(predict_y)[:,np.newaxis]

if __name__ == "__main__":
    y = [211,271,121,31,341,401,241,181,301,301]
    y_matrix = np.array([y]).transpose()
    x = []
    for n in range(1, 11):
        im = open_image("MontBlanc"+str(n)+".png")
        green = get_greenness(im)
        x.append(green)
    x_matrix = np.array([x]).transpose()
    plt.style.use('ggplot')
    test_x = np.linspace(0, 255, 255)
    test_x = x[: np.newaxis]
    pred_y = fit(test_x,x_matrix,y_matrix,0.3,'gs')
    plt.scatter(x,y,color='black')
    plt.scatter(test_x,pred_y,color='blue')
    plt.xticks(())
    plt.yticks(())
    plt.show()
    divisor = lambda x: np.sum([ks(np.sum((j-x)**2)/bindwidth) for j in train_X])