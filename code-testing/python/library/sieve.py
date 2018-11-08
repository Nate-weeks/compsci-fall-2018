''' a program by nate weeks to solves all primes under a given n
October 2018
'''

import math

#inefficicient attempt with lots of array manipulation

def sieve(num):
    i = 2
    array = list(range(num+1))
    while i < math.sqrt(num):   #to get all primes under a number only have to check the sqaure root of that number
        temp = i                #temp to hold starting value of i
        while i < num - 1:
            i = i + temp
            if i < num - 1:     # check if added total is higher than array bounds
                array[i] = 0    # marks all non-primes as 0
        i = temp
        i += 1
    # sets i to the next non-marked number
        while True:
            if array[i] != 0:
                i = array[i]
                break
            else:
                i += 1
    answer = filter(lambda x: x != 0, array)

    return list(answer)

# def sieve(n):
#     # from https://www.geeksforgeeks.org/sieve-of-eratosthenes/ ... not much faster
#     # Create a boolean array "prime[0..n]" and initialize
#     #  all entries it as true. A value in prime[i] will
#     # finally be false if i is Not a prime, else true.
#     prime = [True for i in range(n+1)]
#     p = 2
#     while (p * p <= n):
#
#         # If prime[p] is not changed, then it is a prime
#         if (prime[p] == True):
#
#             # Update all multiples of p
#             for i in range(p * 2, n+1, p):
#                 prime[i] = False
#         p += 1
#     return prime
