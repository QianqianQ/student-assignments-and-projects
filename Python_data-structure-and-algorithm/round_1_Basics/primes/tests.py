"""
These local tests can be used to test your implementation of the is_prime function.

Feel free to modify these tests as you wish.
"""
import unittest

from primes import is_prime


class TestPrimes(unittest.TestCase):
    # All methods starting with 'test' in a TestCase will be run as tests.
    def test_is_prime_with_only_primes(self):
        """is_prime returns True for prime numbers. (1p)"""

        values = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]

        # Test all values in the list
        for value in values:
            # Check that is_prime(value) returns True.
            self.assertTrue(
                is_prime(value),
                # The message below is shown if the test fails.
                # In this case when is_prime(value) returns False.
                "{:d} is a prime number, but your function says it is not".format(value)
            )


    def test_is_prime_with_no_primes(self):
        """is_prime returns False for non-prime numbers. (1p)"""

        values = [-1, 0, 1, 4, 6, 8, 9, 10, 12, 14]

        for value in values:
            # Check that is_prime(value) returns False.
            self.assertFalse(
                is_prime(value),
                "{:d} is not a prime number, but your function says it is".format(value)
            )


# The if checks below prevent the tests from being run if this file is for example imported

# True when running tests from the command line or the Eclipse PyDev unittest tool
if __name__ in ("__main__", "tests"):
    import sys
    # If this test is being run with a Python version that is older than version 3,
    # raise an exception. This skips the tests.
    if sys.version_info.major < 3:
        class VersionError(BaseException): pass
        raise VersionError("You are using Python version {:d}.{:d}, please use version 3 instead."
                           .format(sys.version_info.major, sys.version_info.minor))


# True when running tests from the command line
if __name__ == "__main__":
    # Run the tests with increased output verbosity.
    # You can change the verbosity to for example 1 and see what happens.
    unittest.main(verbosity=2)

