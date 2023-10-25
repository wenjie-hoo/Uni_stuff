import random
import math

def estimate_pi(num_throws, epsilon):
    hits_circle = 0
    hits_square = 0
    for _ in range(num_throws):
        x = random.uniform(-1, 1)
        y = random.uniform(-1, 1)
        if x**2 + y**2 <= 1:
            hits_circle += 1
        hits_square += 1
        pi_approximation = 4 * hits_circle / hits_square
        print(f"Approximation after {hits_square} throws: {pi_approximation}")
        if abs(math.pi - pi_approximation) < epsilon:
            print(f"Approximation is within {epsilon} of π.")
            break

if __name__ == "__main__":
    num_throws = 1000000
    epsilon = 0.0001
    estimate_pi(num_throws, epsilon)
