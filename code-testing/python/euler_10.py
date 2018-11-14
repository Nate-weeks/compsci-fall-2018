'''
Euler_10.py a program to solve euler_10 sum of primes under 2,000,000
Nate Weeks November 2018
'''

from library.jim_sieve import sieve

all_primes = sieve(2000000)

sum = 0
for prime in all_primes:
    sum += prime

print(sum)
