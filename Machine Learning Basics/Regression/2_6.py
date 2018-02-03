from PIL import Image
import matplotlib.pyplot as plt
import numpy as np
import theano 
from theano import tensor as T
def open_image(name):
    image = Image.open(name)
    return image

def get_greenness(image):
    img = image.load()
    greenness = []
    for i in range(100):
        for j in range(100):
            color = img[i, j]
            greenness.append(color[1])
    greenness = np.array([greenness])
    return greenness
    
def gradient_descent(x,y,w,la,alpha,n,iterations):
    risk=[]
    xTrans = x.transpose()
    for i in range(0, iterations):
        hypothesis = np.dot(x, w)
        bias = hypothesis - y
        cost = ((np.dot(bias.transpose(),bias))[0][0] / n)+la*np.dot(w.transpose(),w)[0][0]
        risk.append(cost)
        # avg gradient per example
        gradient = (2*(np.dot(xTrans, bias)) / n)+2*la*w
        # update
        w = w - alpha * gradient
    return w,risk

if __name__ == "__main__":
    y = [211,271,121,31,341,401,241,181,301,301]
    y_matrix = np.array([y]).transpose()
    x = np.zeros((len(y),10000))
    
    for n in range(1, 11):
        im = open_image("MontBlanc"+str(n)+".png")
        green = get_greenness(im)
        x[n-1]=green
    dummy_vec =np.ones((len(y),1))
    x_matrix = np.concatenate((x,dummy_vec),axis=1)
    
    plt.style.use('ggplot')
    origin_w=np.zeros((10001,1))
    risk = []
    w=[]
    iterations = [i for i in range(1,80001)]
    alpha = [1e-9,2e-9,3e-9,4e-9,1e-10]
    la = 2
    for i in range(len(alpha)):
        w_t, risk_t = gradient_descent(x_matrix,y_matrix,origin_w,la,alpha[i],len(y),len(iterations))
        risk.append(risk_t)
        w.append(w_t)
        plt.plot(iterations,risk_t,label=alpha[i])
    
    plt.xlabel("iteration number")
    plt.ylabel("empirical risk")
    plt.legend(title="step size")
    plt.show()
    

    
