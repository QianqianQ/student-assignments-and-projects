from PIL import Image
import matplotlib.pyplot as plt
import numpy as np

def open_image(name):
    image = Image.open(name)
    return image

def get_normalized_greenness(image):
    img = image.load()
    width, height = image.size
    greenness = 0
    for i in range(width):
        for j in range(height):
            color = img[i, j]
            greenness += color[1]
    total_pixel = width*height
    normalized_greenness = greenness/total_pixel
    return normalized_greenness

if __name__ == "__main__":
    x = []
    y = [211,271,121,31,341,401,241,181,301,301]
    y_matrix = np.array([y]).transpose()
    for n in range(1, 11):
        im = open_image("MontBlanc"+str(n)+".png")
        green = get_normalized_greenness(im)
        print("image"+str(n)+":")
        print("normalized greenness: {}\n".format(green))
        x.append(green)

    x_g = np.array([x]).transpose()
    dummy_vec =np.array([[1,1,1,1,1,1,1,1,1,1]]).transpose()
    x_matrix = np.concatenate((x_g,dummy_vec),axis=1)
    XTX=np.dot(x_matrix.transpose(),x_matrix)
    XTX_I=np.linalg.inv(XTX)
    w = XTX_I.dot(x_matrix.transpose()).dot(y_matrix)
    print("w:\n",w)
    print("\n")

    total_loss=0
    for i in range(10):
        h=np.dot(w.transpose(),x_matrix[i].transpose())
        #h = w[0]*x[i]+w[1]
        print("Image"+str(i+1)+": ")
        print("h:{},y:{}".format(h,y[i]))
        loss = (y[i]-h)**2
        print("loss:",loss)
        total_loss += loss
    print(total_loss)
    emperical_risk = total_loss/len(y)
    print(emperical_risk)


    plt.style.use('ggplot')
    plt.scatter(x, y,c="b",s=30)
    count = 1
    for x, y in zip(x, y):
        plt.annotate('%s' % count, xy=(x, y), xytext=(x, y+9))
        count += 1
    plt.xlabel("normalized greenness")
    plt.ylabel("duration(in minutes)")
    x_pred = np.arange(70.0,140.0, 0.1)
    y_pred=w[0]*x_pred+w[1]
    plt.plot(x_pred,y_pred)
    plt.annotate("h(x) = 6.15 x - 440",xy=(75,350))
    plt.autoscale(axis='x', tight=True)
    plt.show()
