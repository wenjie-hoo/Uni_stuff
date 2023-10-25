def sqrt(n: float) -> int:
    sum, i = 0, 0
    while sum < n:
        i += 1
        sum += 2 * i + 1
    return i

if __name__ == '__main__':
    for i in range(1000):
        print(i, ':', sqrt(i))