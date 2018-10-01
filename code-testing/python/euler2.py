'''
Euler2.py
a class to complete project euler number 2
Nate Weeks September 2018
'''

class Euler2(object):
    ''' object takes a max size and calculates even
    fibonacci sum'''
    def __init__(self, max_number):
        self.max_number = max_number

    def createFibArray(self):
        ''' given a max number, creates an array of fibonacci numbers
        under that size'''
        array = [1]
        m = array[0]
        n = 2
        while n < self.max_number:
            array.append(n)
            m = array[-2]
            n += m
        return array

    def even_number(self, array):
        ''' given an array, return an array of only even numbers '''
        even_array = []
        for i in range(len(array)):
            if array[i] % 2 == 0:
                even_array.append(array[i])
        return even_array

    def add_array(self, array):
        ''' total an array of integers '''
        total = 0
        for i in range(len(array)):
            total += array[i]
        return total

def main():
    arr = Euler2(4000000)
    print "the even sum of even fibonacci numbers under 4000000 is: "
    print arr.add_array(arr.even_number(arr.createFibArray()))

main()
