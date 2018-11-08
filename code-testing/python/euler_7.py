'''
euler_7.py a program by nate weeks to solve euler problem 7
October 2018
'''

from library.sieve import sieve

#find the 100001'st prime
all_primes = sieve(1000000)

print(all_primes[10001])
