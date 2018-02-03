from PIL import Image
import matplotlib.pyplot as plt

def open_image(name):
    image = Image.open(name)
    return image


def get_redness(image):
    img = image.load()
    width, height = image.size
    redness = 0
    for i in range(width):
        for j in range(height):
            [r, g, b] = img[i, j]
            redness += r
    return redness


def get_greenness(image):
    img = image.load()
    width, height = image.size
    greenness = 0
    for i in range(width):
        for j in range(height):
            [r, g, b] = img[i, j]
            greenness += g
    return greenness


if __name__ == "__main__":
    x = []
    y = []

    for n in range(1, 8):
        im = open_image("shot"+str(n)+".jpg")
        red = get_redness(im)
        green = get_greenness(im)
        print("image"+str(n)+":")
        print("redness: {}, greenness: {}\n".format(red, green))
        x.append(red)
        y.append(green)

    plt.scatter(x, y, s=100)
    count = 1
    for x, y in zip(x, y):
        plt.annotate('shot %s' % count, xy=(x, y), xytext=(x+90000, y+60000))
        count += 1
    plt.xlabel("Redness")
    plt.ylabel("Greenness")
    plt.title("scatter plot - Redness vs Greenness")
    plt.show()

