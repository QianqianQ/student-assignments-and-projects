from PIL import Image
import matplotlib.pyplot as plt
import numpy as np
from sklearn.cluster import KMeans
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
    normalized_redness = redness/total_pixel
    normalized_greenness = greenness/total_pixel
    return normalized_redness, normalized_greenness

def purity(p):
    h_P = 1+p*np.log2(p)+(1-p)*np.log2(1-p)
    return h_P

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
M = [3, 6, 9, 12, 15, 18, 21, 24, 27, 30]
y_pred=[]
average_P = []
for i in M:
    hat_P=[]
    for n in range(10):
        kmeans = KMeans(n_clusters=2,init='random',n_init=1,max_iter=i).fit(X)
        clusters = kmeans.labels_
        c1_w = 0
        c1_s = 0
        for j in range(10):
            if clusters[j]==1:
                c1_s += 1
        for k in range(10,20):
            if clusters[k]==1:
                c1_w += 1
        P_w = purity(c1_w/10)
        P_s = purity(c1_s/10)
        average = (P_w+P_s)/2
        hat_P.append(average)
    y_pred.append(clusters)
    average_P.append(np.mean(hat_P))
print(y_pred)
print(average_P)




plt.scatter(summer[:,0],summer[:,1],label="summer")
plt.scatter(winter[:,0],winter[:,1],label="winter")
plt.xlabel("redness")
plt.ylabel("greenness")
plt.legend()
plt.title("Scatter plot of initial data point")

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
plt.plot(M,average_P,marker='o')
plt.xticks(range(np.max(M)+1))
plt.xlabel("M")
plt.ylabel("average purity")
plt.show()