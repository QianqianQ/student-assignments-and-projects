

def power(base, exponent):
    if exponent == 1:
        return base
    else:
        return base * power(base, exponent-1)
    # Write your code here
    # raise NotImplementedError("Fix me!")
    
def main():
    #Try your function
    base = 5
    exponent = 3
    print("{} ^ {} = {}".format(base, exponent, power(base, exponent)))
    
if __name__ == "__main__":    
    main()
