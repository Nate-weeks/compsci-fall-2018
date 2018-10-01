import unittest
from euler2 import Euler2

class Euler_2_test(unittest.TestCase):
    def setUp(self):
        self.array = Euler2(90)

    def test_fibonacci_array(self):
        array = self.array.createFibArray()
        self.assertEqual([1, 2, 3, 5, 8, 13, 21, 34, 55, 89], array)

    def test_even_number(self):
        even_array = self.array.even_number(self.array.createFibArray())
        self.assertEqual([2, 8, 34], even_array)

    def test_add_array(self):
        even_array = self.array.even_number(self.array.createFibArray())
        self.assertEqual(45, self.array.add_array(even_array))

if __name__ == '__main__':
    unittest.main()
