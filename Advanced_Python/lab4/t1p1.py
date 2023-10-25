def is_prime(n):
    if n < 2:
        return False
    return all(n % i != 0 for i in range(2, int(n**0.5) + 1))


def prime_imperative(n):
    primes = []
    for num in range(2, n + 1):
        if is_prime(num):
            primes.append(num)
    return primes

def prime_comprehension(n):
    return [num for num in range(2, n + 1) if is_prime(num)]

def prime_functional(n):
    return list(filter(is_prime, range(2, n + 1)))

def results(n):
    return (f'prime_imperative:{prime_imperative(n)}\n \
          prime_comprehension:{prime_comprehension(n)}\n \
          prime_functional:{prime_functional(n)}')

print(results(50))

