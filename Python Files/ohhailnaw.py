import time
import random

def insertion_sort(arr):
    """
    Insertion Sort using Decrease and Conquer approach.
    Loop Invariant: At the start of each iteration of the outer loop,
    the subarray arr[0..i-1] is sorted.
    """
    n = len(arr)
    for i in range(1, n):
        key = arr[i]
        j = i - 1
        # Move elements of arr[0..i-1], that are greater than key,
        # to one position ahead of their current position
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
    return arr

def measure_time(n):
    """Measure the time taken to sort a list of n random elements."""
    arr = [random.randint(1, 1000) for _ in range(n)]
    start_time = time.time()
    insertion_sort(arr.copy())
    end_time = time.time()
    return end_time - start_time

# Example usage
sample_list = [64, 34, 25, 12, 22, 11, 90]
print("Original list:", sample_list)
sorted_list = insertion_sort(sample_list.copy())
print("Sorted list:", sorted_list)

# Measure time for 10 random values of n
random_n_values = [random.randint(50, 1000) for _ in range(10)]
random_n_values.sort()
print("\nTime taken for 10 random n values:")
for n in random_n_values:
    time_taken = measure_time(n)
    print(f"n = {n}, Time taken = {time_taken:.6f} seconds")
