'''
Euler3.py, a program by Nate Weeks to solve Euler problem 3
October 2018
'''

from library.sieve import sieve
import math

def euler_3(num):
    '''takes a number as an argument and solves for the greatest prime factor
    of that number'''
    answer = []
    primes = sieve(1000000)
    for i in range(len(primes)):
        if num % primes[i] == 0:
            answer.append(primes[i])      # create an array of prime factors
    return answer[-1]                     # return the greatest prime factor

print(euler_3(600851475143))
