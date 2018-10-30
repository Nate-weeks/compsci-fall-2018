from library.sieve import sieve
import math

def euler_3(num):
    answer = []
    primes = sieve(1000000)
    for i in range(len(primes)):
        if num % primes[i] == 0:
            answer.append(primes[i])
    return answer[-1]

print(euler_3(600851475143))
