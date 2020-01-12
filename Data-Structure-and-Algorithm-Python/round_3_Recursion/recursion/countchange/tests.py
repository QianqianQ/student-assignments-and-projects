import unittest

from countchange import count_change


class TestCountChange(unittest.TestCase):

    def test_with_negative_amount(self):
        """Negative amounts cannot be divided in any way. (1p)"""

        self.assertEqual(
            0,
            count_change(-1),
        )

    def test_with_zero_amount(self):
        """Zero amount can always be divided in only one way. (1p)"""

        self.assertEqual(
            1,
            count_change(0),
        )

    def test_with_no_coins(self):
        """No amount can be divided if there are no coins. (1p)"""

        for i in range(1, 10):
            self.assertEqual(
                0,
                count_change(i, ()),
            )

    def test_with_small_amounts(self):
        """count_change counts correctly for small amounts. (2p)"""

        data = [(2, 2), (6, 5), (12, 15)]

        for amount, correct_value in data:
            returned_value = count_change(amount)
            self.assertEqual(
                correct_value,
                returned_value,
                "{0:.2f} euros can be divided in {1} ways when using euro coins, not {2} ways."
                .format(0.01*amount, correct_value, returned_value)
            )


if __name__ == "__main__":
    unittest.main(verbosity=2)

