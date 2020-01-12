def is_prime(n):
    """ Return True if n is a prime number, else False. """
    if n < 2:
        return False
    for i in range(2, n):
        if n % i == 0:
            return False
    return True
#raise NotImplementedError("This exercise is still unsolved.")

