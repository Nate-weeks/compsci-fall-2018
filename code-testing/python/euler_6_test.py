import unittest
from euler6 import Euler6

class Euler_6_test(unittest.TestCase):
    def setUp(self):
        self.max = Euler6(10)

    def test_squaresum(self):
        self.assertEqual(385, self.max.squaresum())

    def test_sumsquared(self):
        self.assertEqual(3025, self.max.sumsqaured())

if __name__ == '__main__':
    unittest.main()
