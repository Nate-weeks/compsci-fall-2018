import math

def sieve(maximum):
    """ Return a list of prime numbers p such that 2 <= p <= maximum """
    array = list(range(2, maximum + 1))
    limit = math.sqrt(maximum)
    # print("limit = ", limit)
    i = 0
    while array[i] <= limit:   #to get all primes under a number only have to check the sqaure root of that number
        # print("A : i, , array = ", i, array)
        temp = array[i]             #temp to hold starting value of i
        j = i
        while True:
            j += array[i]
            if j >= len(array):
                break
            array[j] = 0    # marks all non-primes as 0
        i += 1
        # print("B : i, , array = ", i, array)
        # sets i to the next non-marked number
        while array[i] == 0:
            i += 1
        # print("C : i, , array = ", i, array)
        # print()
    return list(filter(lambda x: x != 0, array))
