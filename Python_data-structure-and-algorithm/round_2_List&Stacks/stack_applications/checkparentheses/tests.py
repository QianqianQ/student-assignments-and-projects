import unittest

from checkparentheses import checkParentheses


class TestCheckParentheses(unittest.TestCase):

    def test_empty_string(self):
        """checkParentheses returns True for empty strings. (1p)"""

        correct_input = ""

        self.assertTrue(
            checkParentheses(correct_input),
            "checkParentheses({0!r}) should return True, not False.".format(correct_input)
        )

    def test_no_parentheses(self):
        """checkParentheses returns True for strings with no parentheses. (1p)"""

        correct_input = "1 + 1 = 2"

        self.assertTrue(
            checkParentheses(correct_input),
            "checkParentheses({0!r}) should return True, not False.".format(correct_input)
        )

    def test_correct_parentheses(self):
        """checkParentheses returns True for strings with correctly formatted parentheses. (1p)"""

        input_list = [
            "(1, 2, (True, False))",
            "([1, 2], [True, False, True])",
            "{'name': 'Flappy', 'awards': ['best shoes']}"
        ]

        for correct_input in input_list:
            self.assertTrue(
                checkParentheses(correct_input),
                "checkParentheses({0!r}) should return True, not False.".format(correct_input)
            )

    def test_incorrect_parentheses(self):
        """checkParentheses returns False for strings with incorrectly formatted parentheses. (1p)"""

        input_list = [
            "(i for i in range(10)",
            "[1, 2, (3], 4)",
            "{'a': (1, 3) ]",
        ]

        for incorrect_input in input_list:
            self.assertFalse(
                checkParentheses(incorrect_input),
                "checkParentheses({0!r}) should return False, not True.".format(incorrect_input)
            )


if __name__ == "__main__":
    # Run the tests
    unittest.main(verbosity=2)

