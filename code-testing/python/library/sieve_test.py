import unittest
from sieve import sieve

class TestSieve(unittest.TestCase):

    def test_sieve(self):
        self.assertEqual(sieve(10), [1,2,3,5,7,9])


if __name__ == '__main__':
    unittest.main()
