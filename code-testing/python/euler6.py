'''
Euler6.py - a program to solve euler problem 6 - sum of squares
Nate Weeks October 2018
'''
# squaresum = 0
# sum = 0
# for i in range(101):
#     squaresum += i ** 2
#     sum += i
#
# answer = (sum ** 2) - squaresum
# print(answer)

class Euler6(object):
    ''' object takes a max number - includes methods to find
    square of the sums and the sum of the sqaures'''
    def __init__(self, max):
        self.max = max

    def squaresum(self):
        ''' method to find the square of the sums under max'''
        result = 0
        for num in range(self.max + 1):
            result += num ** 2
        return result

    def sumsquared(self):
        ''' method to find the sum of the squares under max '''
        result = 0
        for num in range(self.max + 1):
            result += num
        result = result ** 2
        return result

if __name__ == "__main__":
    thing = Euler6(100)
    sumsquared = thing.sumsquared()
    squaresum = thing.squaresum()
    answer = sumsquared - squaresum
    print(answer)
