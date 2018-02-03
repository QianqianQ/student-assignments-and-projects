from PIL import Image
import matplotlib.pyplot as plt
import numpy as np
from sklearn.decomposition import PCA
from numpy import linalg as LA

def open_image(name):
    image = Image.open(name)
    return image

def get_greyscale(image):
    img = image.load()
    width, height = image.size
    grey = []
    for i in range(40):
        for j in range(40):
            [r, g, b] = img[i, j]
            grey_value = (r * 0.299) + (g * 0.587) + (b * 0.114)
            grey.append(grey_value)
    return grey

grey=[]
for n in range(1, 11):
        im = open_image('images\\summer'+str(n)+'.jpeg')
        grey_value = get_greyscale(im)
        grey.append(grey_value)

for n in range(1, 11):
        im = open_image('images\\winter'+str(n)+'.jpeg')
        grey_value = get_greyscale(im)
        grey.append(grey_value)

grey = np.asarray(grey)
print(grey[0])
error=[]
for i in range(20,101):
    pca = PCA(n_components=i, random_state=42)
    pca_results = pca.fit_transform(grey)
    pca_proj_back=pca.inverse_transform(pca_results)
    total_loss = LA.norm((grey-pca_proj_back),None)
    error.append(total_loss)
print(error)