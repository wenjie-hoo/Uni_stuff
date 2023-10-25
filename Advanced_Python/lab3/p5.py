# Kadane's algorithm
def max_sublist_sum(lst):
    if not lst:
        return None
    max_sum = lst[0]
    current_sum = lst[0]
    start = 0
    max_range = (0, 0)
    for i in range(1, len(lst)):
        if lst[i] > current_sum + lst[i]:
            current_sum = lst[i]
            start = i
        else:
            current_sum += lst[i]
        if current_sum > max_sum:
            max_sum = current_sum
            max_range = (start, i)
    return max_range

list_1 = [1, -3, 4, -2, -1, 6]
print(f'Maximum contiguous sum is {max_sublist_sum(list_1)}')

list_2 = [-2, -3, 4, -1, -2, 1, 5, -3]
print(f'Maximum contiguous sum is {max_sublist_sum(list_2)}')