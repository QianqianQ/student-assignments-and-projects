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
            greenness += (color[1])
    total_pixel = width*height
    normalized_greenness = greenness/total_pixel
    return normalized_greenness

def standardized_greenness(l):
    mu = np.mean(l)
    print(mu)
    std=np.std(l)
    for i in range(len(l)):
        l[i]= (l[i]-mu)/std
        print(l[i])

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

    # standardized_greenness(x)
    
    w = []
    lamda=[0,2,5]
    x_g = np.array([x]).transpose()
    dummy_vec =np.array([[1,1,1,1,1,1,1,1,1,1]]).transpose()
    x_matrix = np.concatenate((x_g,dummy_vec),axis=1)
    XTX=np.dot(x_matrix.transpose(),x_matrix)
    for i in range(len(lamda)):
        lamdaI =len(y)*lamda[i]*np.eye(2)
        temp = XTX+lamdaI
        temp_I=np.linalg.inv(temp)
        w_temp = temp_I.dot(x_matrix.transpose()).dot(y_matrix)
        w.append(w_temp)
        
    print("w:\n",w)
    print("\n")
    risk = []
    for j in range(len(w)):
        total_loss=0    
        for i in range(10):            
            h=np.dot(w[j].transpose(),x_matrix[i].transpose())
            #h = w[0]*x[i]+w[1]
            loss = (y[i]-h)**2
            total_loss += loss
        emperical_risk = total_loss/len(y)
        emperical_risk += lamda[j]*(w[j][0]**2+w[j][1]**2)
        print(emperical_risk)
        risk.append(emperical_risk)
    print(risk)
    
    print(plt.style.available)
    plt.style.use('seaborn-bright')
    plt.scatter(x, y,c="b",s=30)
    plt.hold(True)
    count = 1
    for x, y in zip(x, y):
        #plt.annotate('%s' % count, xy=(x, y), xytext=(x, y+9))
        count += 1
    plt.xlabel("normalized greenness")
    plt.ylabel("duration(in minutes)")
    x_pred = np.arange(50,150, 0.01)

    '''
    y_pred_1=w[0][0]*x_pred+w[0][1]
    plt.plot(x_pred,y_pred_1,color="r",label=r'$\lambda=3$')
    plt.hold(True)
    y_pred_2=w[1][0]*x_pred+w[1][1]
    plt.plot(x_pred,y_pred_2,color="b",label=r'$\lambda=5$')
    plt.hold(True)
    plt.legend(loc=2)
    plt.annotate(r'$h_{\lambda=3}(x) = %.2f x %.1f$'%(w[0][0],w[0][1]),xy=(75,320))
    plt.annotate(r'$h_{\lambda=5}(x) = %.2f x %.1f$'%(w[1][0],w[1][1]),xy=(75,300))
    plt.autoscale(axis='x', tight=True)
    plt.show()
    '''
    y_pred=[]
    for i in range(len(w)):
        y_temp = w[i][0]*x_pred+w[i][1]
        y_pred.append(y_temp)
        plt.plot(x_pred,y_pred[i],label='$\lambda=%d$'%(lamda[i]),linewidth=1)
        plt.legend(loc=2)
        plt.annotate(r'$h_{\lambda=%d}(x) = %.2f x %.1f$'%(lamda[i],w[i][0],w[i][1]),xy=(75,480-50*i))
        plt.autoscale(axis='x', tight=True)
    
    plt.show()
