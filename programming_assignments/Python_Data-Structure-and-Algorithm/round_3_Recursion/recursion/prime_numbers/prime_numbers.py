import math


def is_prime_number(n):
    divider = int(math.sqrt(n)//1)  # Which is the highest number to start finding a divider?
    if not has_divisors(n, divider):
        print("Number", n, "is a prime number.")
    else:
        print("Number", n, "is NOT a prime number.")

# has_divisors_less_than_divider

def has_divisors(n, divider):
    if n < 2:
        return True
    if divider == 1:
        return False
    else:
        if n % divider == 0:
            return True
        else:
            return has_divisors(n, divider-1)


    # Write your code here
    # raise NotImplementedError("Fix me!")


if __name__ == "__main__":
    #Some examples
    is_prime_number(13) #yes
    is_prime_number(21) #no
    is_prime_number(4)
