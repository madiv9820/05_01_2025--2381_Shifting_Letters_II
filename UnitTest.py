from Solution import Solution
from timeout_decorator import timeout
import unittest

class UnitTest(unittest.TestCase):
    def setUp(self):
        self.__testcases = {1: ('abc', [[0,1,0],[1,2,1],[0,2,1]], 'ace'),
                            2: ('dztz', [[0,0,0],[1,1,1]], 'catz')}
        self.__obj = Solution()
        return super().setUp()

    @timeout(0.5)
    def test_case_1(self):
        s, shifts, output = self.__testcases[1]
        result = self.__obj.shiftingLetters(s = s, shifts = shifts)
        self.assertIsInstance(result, str)
        self.assertEqual(result, output)

    @timeout(0.5)
    def test_case_2(self):
        s, shifts, output = self.__testcases[2]
        result = self.__obj.shiftingLetters(s = s, shifts = shifts)
        self.assertIsInstance(result, str)
        self.assertEqual(result, output)

if __name__ == '__main__': unittest.main()