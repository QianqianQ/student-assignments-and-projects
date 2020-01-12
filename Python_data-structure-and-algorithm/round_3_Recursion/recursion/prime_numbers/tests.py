import unittest
import math
from prime_numbers import has_divisors

class TestPrimeNumbers(unittest.TestCase):

    def test_with_10_not_prime_numbers(self):
        """has_divisors returns True if numbers are not prime numbers. (10p)"""
        numbers = [4,8,10,15,20,155,270,300,444,985]
        for number in numbers:
            self.assertTrue(has_divisors(number, int(math.sqrt(number) // 1) + 1), "Number {} is not a prime number.".format(number))

    def test_with_10_prime_numbers(self):
        """has_divisors returns False if numbers are prime numbers. (10p)"""
        numbers = [3,5,7,11,13,17,19,23,29,31]
        for number in numbers:
            self.assertFalse(has_divisors(number, int(math.sqrt(number) // 1) + 1), "Number {} is a prime number.".format(number))

if __name__ == "__main__":
    unittest.main(verbosity=2)
