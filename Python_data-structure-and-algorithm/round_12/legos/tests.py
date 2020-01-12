import unittest

from legos import suitable_pieces


class TestLegos(unittest.TestCase):

    def _test_with_data(self, data):
        """Generic test method accepting a dictionary of test data as parameter."""
        width = data["width"]
        # Convert float lengths to integers
        pieces = list(map(round, data["pieces"]))

        returned_value = suitable_pieces(width, pieces)
        expected_value = tuple(map(round, data["correct"]))

        self.assertEqual(
            returned_value,
            expected_value,
            "For the width {0} cm and pieces {1} nm, the correct suitable combination is {2}, not {3}."
            .format(width, pieces, expected_value, returned_value)
        )

    def test1_all_widths_no_pieces(self):
        """If no pieces are given, there's no way to choose suitable pieces. (1p)"""
        for width in range(1, 21):
            test_data = {
                "width": width,
                "pieces": [],
                "correct": ()
            }
            self._test_with_data(test_data)

    def test2_only_suitable_pieces(self):
        """If only pieces which have a length half of the total width are given, there should always be a way to choose two pieces. (1p)"""
        for width in range(1, 21):
            width_nm = round(width*1e7)
            pieces = [width_nm//2, width_nm//2]
            test_data = {
                "width": width,
                "pieces": pieces,
                "correct": tuple(pieces)
            }
            self._test_with_data(test_data)

    def test3_only_unsuitable_pieces(self):
        """If only unsuitable pieces are given, there's no way to choose suitable pieces. (1p)"""
        for width in range(1, 21):
            width_nm = round(width*1e7)
            pieces = [width_nm//3, width_nm//3]
            test_data = {
                "width": width,
                "pieces": pieces,
                "correct": ()
            }
            self._test_with_data(test_data)

    def test4_suitable_pieces_return_value_ascending(self):
        """If only suitable pieces are given, the return value contains two suitable pieces in ascending order with the maximum size difference. (1p)"""

        # List of 'test cases' with parameters and the corresponding expected return value
        # for calling suitable_pieces with the parameters.
        test_data = [
            { "width": 10,
              "pieces": [6e7, 4e7, 5e3, 4e5],
              "correct": (4e7, 6e7) },

            { "width": 10,
              "pieces": [5e7, 5e7, 3e7, 7e7],
              "correct": (3e7, 7e7) },

            { "width": 1,
              "pieces": [5e6, 5e6, 4e6, 6e6, 9e2, 1e2],
              "correct": (4e6, 6e6) },

            { "width": 20,
              "pieces": [1.7e8, 0.3e8, 1.9e8, 0.1e7],
              "correct": (0.3e8, 1.7e8) }
        ]
        for data in test_data:
            self._test_with_data(data)



if __name__ == "__main__":
    unittest.main(verbosity=2)

