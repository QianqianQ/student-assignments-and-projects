from PIL import Image
import matplotlib.pyplot as plt
import numpy as np
from scipy.misc import logsumexp
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

def component(x,x1,sigma):
    sigma2 = sigma**2
    diff2 = 0
    for i in range(len(x)):
        diff2 += (x[i]-x1)**2
    component = (-1/2)*diff2/sigma2
    return component
def get_predictor(xpred,x,y,sigma):
    Kxxl=[]
    for i in range(len(x)):
        t = -0.5*(xpred-x[i])**2/(sigma**2)
        Kxxl.append(t)
    lower = logsumexp(Kxxl)

    Kxxi=[]
    for i in range(len(x)):
        log=np.log(y[i])
        t = -0.5*(xpred-x[i])**2/(sigma**2)
        f = log+t
        Kxxi.append(f)       
    higher = logsumexp(Kxxi)
    final = np.exp(higher-lower)
    return final

def empirical_risk(x,y,sigma):
    total_risk=0
    for i in range(len(y)):
        pred = get_predictor(x[i],x,y,sigma)
        total_risk += (y[i]-pred)**2
    empirical_risk = total_risk/len(y)
    return empirical_risk

if __name__ == "__main__":
    x = []
    y = [211,271,121,31,341,401,241,181,301,301]
    y_matrix = np.array([y]).transpose()
    for n in range(1, 11):
        im = open_image("MontBlanc"+str(n)+".png")
        green = get_greenness(im)
        x.append(green)
    x_matrix = np.array([x]).transpose()
    sigma=[1,5,10]
    xpred = np.arange(0,255,1)

    ypred_1=[]
    for i in range(len(xpred)):
        t = get_predictor(xpred[i],x,y,sigma[0])
        ypred_1.append(t)

    ypred_5=[]
    for i in range(len(xpred)):
        t = get_predictor(xpred[i],x,y,sigma[1])
        ypred_5.append(t)

    ypred_10=[]
    for i in range(len(xpred)):
        t = get_predictor(xpred[i],x,y,sigma[2])
        ypred_10.append(t)

    er=[]
    total_risk=0
    for i in range(len(y)):
        pred = get_predictor(x[i],x,y,sigma[0])
        total_risk += (y[i]-pred)**2
    empirical_risk = total_risk/len(y)
    print(empirical_risk)
    er.append(empirical_risk)

    total_risk=0
    for i in range(len(y)):
        pred = get_predictor(x[i],x,y,sigma[1])
        total_risk += (y[i]-pred)**2
    empirical_risk = total_risk/len(y)
    print(empirical_risk)
    er.append(empirical_risk)

    total_risk=0
    for i in range(len(y)):
        pred = get_predictor(x[i],x,y,sigma[2])
        total_risk += (y[i]-pred)**2
    empirical_risk = total_risk/len(y)
    print(empirical_risk)
    er.append(empirical_risk)
    print(er)

    plt.style.use("ggplot")
    plt.plot(xpred,ypred_1,label=r'$\sigma=1$')
    plt.plot(xpred,ypred_5,label=r'$\sigma=5$')
    plt.plot(xpred,ypred_10,label=r'$\sigma=10$',color="green")
    plt.scatter(x,y)
    plt.xlabel("normalized greenness")
    plt.ylabel("duration(in minutes)")
    plt.legend(loc=2)
    plt.show()
    


'''
    xxl=0
    for l in range(len(y)):
            xxl += np.log(kernel(x,x[l],sigma[0]))
    print(xxl)
    for i in range(len(y)):
        xxi = kernel(x,x[i],sigma[0])
        xxl = 0
        exponent=np.log(xxi)-np.log(xxl) 
        e = np.exp(exponent)
        h += y[i]*e    
    print(h)
    xpred = np.arange(0,255,1)
    ypred = xpred*h
    plt.scatter(x,y)
    plt.plot(xpred,ypred)
    plt.show()
    '''