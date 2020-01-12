import math


def count_circles_and_squares(length, circles, squares):
    if length < 1:
        if circles == 0 and squares == 0:
            return circles, squares
        else:
            squares -= 1
            return circles, squares
    else:
        squares += 1
        circles += 1
        return count_circles_and_squares(length*(math.sqrt(1/2)), squares, circles)

    # Write your code here
    # raise NotImplementedError("Fix me!")


def main():
    length = 2
    length2 = 4
    circles, squares = count_circles_and_squares(length, 0, 0)
    print("Circles:", circles, "Squares:", squares)
    circles2, squares2 = count_circles_and_squares(length2, 0, 0)
    print("Circles:", circles2, "Squares:", squares2)

if __name__ == "__main__":    
    main()
