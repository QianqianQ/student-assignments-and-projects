from PIL import Image
import matplotlib.pyplot as plt
import numpy as np
from scipy.stats import multivariate_normal
np.seterr(divide='ignore', invalid='ignore')

def open_image(name):
    image = Image.open(name)
    return image

def get_pixels(image):
    img = image.load()
    width, height = image.size
    redness = 0
    greenness = 0
    for i in range(width):
        for j in range(height):
            [r, g, b] = img[i, j]
            redness += r
            greenness += g
    total_pixel = width*height
    normalized_redness = (redness/total_pixel)/255
    normalized_greenness = (greenness/total_pixel)/255
    return normalized_redness, normalized_greenness

def purity(p):
    P = 1+p*np.log2(p)+(1-p)*np.log2(1-p)
    return P


def update(m1,m0,C1,C0,X):
    dist_m0 = multivariate_normal(mean=m0,cov=C0+0.000001*np.identity(2))
    dist_m1 = multivariate_normal(mean=m1,cov=C1+0.000001*np.identity(2))
    pred=[]
    for i in range(20):
        y1 = dist_m1.pdf(X[i].transpose())
        y0 = dist_m0.pdf(X[i].transpose())
        y_t = y1/(y1+y0)
        pred.append(y_t)
    pred = np.array(pred)
    pred[np.isnan(pred)]=0
    '''  
    y_0 = dist_m0.pdf(X)
    y_1 = dist_m1.pdf(X)
    pred = y_1/(y_0+y_1)
    '''
    N_1=np.sum(pred)
    N_0 = 20 - N_1
    m_10=0
    m_11=0
    m_00=0
    m_01=0
    for i in range(20):
        m_10 += pred[i]*X[i][0]
        m_11 += pred[i]*X[i][1]
        m_00 += (1-pred[i])*X[i][0]
        m_01 += (1-pred[i])*X[i][1]
    m1[0] = m_10/N_1
    m1[1] = m_11/N_1
    m0[0] = m_00/N_0
    m0[1] = m_01/N_0
    '''
    m1 = np.sum([y*x for y, x in zip(pred,X)],axis=0)/N_1
    m0 = np.sum([(1-y)*x for y, x in zip(pred,X)],axis=0)/N_0
    '''
    C1 = np.zeros((2,2))
    C0 = np.zeros((2,2))
    for i in range(20):
        C1 += pred[i]*(X[i]-m1).transpose().dot(X[i]-m1)
        C0 += (1-pred[i])*(X[i]-m0).transpose().dot(X[i]-m0)
    C1 = C1/N_1
    C0 = C0/N_0

    return m1,m0,C1,C0,pred

def average_P(M,m1_i,m0_i,C1_i,C0_i,X):
    m1 = m1_i
    m0 = m0_i
    C1 = C1_i
    C0 = C0_i
    for i in range(M):
        m1,m0,C1,C0,pred = update(m1,m0,C1,C0,X)
    
    Pw_coef = (np.sum(pred[0:10]))/10
    Ps_coef = (np.sum(pred[10:]))/10
    Pw = purity(Pw_coef)
    Ps = purity(Ps_coef)
    average_P = (Pw+Ps)*0.5
    return average_P

redness = []
greenness = []
summer = []
winter = []
X = []
y=[]
for n in range(1, 11):
        x=[]
        im = open_image('images\\summer'+str(n)+'.jpeg')
        r,g = get_pixels(im)
        redness.append(r)
        greenness.append(g)
        x.append(r)
        x.append(g)
        summer.append(x)
        X.append(x)
        y.append(1)

for n in range(1, 11):
        im = open_image('images\\winter'+str(n)+'.jpeg')
        r,g = get_pixels(im)
        x=[]
        redness.append(r)
        greenness.append(g)
        x.append(r)
        x.append(g)
        winter.append(x)
        X.append(x)
        y.append(0)

summer = np.asarray(summer)
winter = np.asarray(winter)
X = np.asarray(X)

M = [5,10,15,20,25,30,35,40,45,50]

'''
P = []
y_pred=[]
for i in M:
    idx = np.random.randint(20,size=2)
    m0 = X[idx[0]].transpose()
    m1 = X[idx[1]].transpose()
    C0 = np.identity(2)
    C1 = np.identity(2)
    for k in range(i):
        m1,m0,C1,C0,pred = update(m1,m0,C1,C0,X)
    Pw_coef = (np.sum(pred[0:10]))/10
    Ps_coef = (np.sum(pred[10:]))/10
    Pw = purity(Pw_coef)
    Ps = purity(Ps_coef)
    average_P = (Pw+Ps)*0.5
    y_pred.append(pred)
    P.append(average_P)
print(P)
'''

y_pred=[]
P = []
for i in M:
    hat_P = 0
    for j in range(10):
        idx = np.random.randint(20,size=2)
        m0 = X[idx[0]].transpose()
        m1 = X[idx[1]].transpose()
        C0 = np.identity(2)
        C1 = np.identity(2)
        for k in range(i):
            m1,m0,C1,C0,pred = update(m1,m0,C1,C0,X)
        Pw_coef = (np.sum(pred[0:10]))/10
        Ps_coef = (np.sum(pred[10:]))/10
        Pw = purity(Pw_coef)
        Ps = purity(Ps_coef)
        average_P = (Pw+Ps)*0.5
        hat_P += average_P
    hat_P = hat_P/10
    y_pred.append(pred)
    P.append(hat_P)

print(P)

f,axes = plt.subplots(2,5)
for i in range(5):
    axes[0][i].scatter(redness,greenness,c=y_pred[i])
    axes[0][i].set_ylabel("greenness")
    axes[0][i].set_title("M=%d"%M[i])
for j in range(5):
    axes[1][j].scatter(redness,greenness,c=y_pred[j+5])
    axes[1][j].set_xlabel("redness")
    axes[1][j].set_ylabel("greenness")
    axes[1][j].set_title("M=%d"%M[5+j])

plt.figure()
plt.plot(M,P,marker='o')
plt.xticks(range(np.min(M),np.max(M)+2,5))
plt.xlabel("M")
plt.ylabel("average purity")
plt.show()