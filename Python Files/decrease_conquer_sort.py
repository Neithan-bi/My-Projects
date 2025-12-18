import time
import random
import matplotlib.pyplot as plt

def insertion_sort(arr):
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

def plot_time_complexity():
    """Plot the time taken versus n for different values of n."""
    n_values = [10, 50, 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000]
    times = [measure_time(n) for n in n_values]
    
    plt.figure(figsize=(10, 6))
    plt.plot(n_values, times, marker='o', linestyle='-', color='b')
    plt.title('Time Complexity of Insertion Sort (Decrease and Conquer)')
    plt.xlabel('Number of Elements (n)')
    plt.ylabel('Time Taken (seconds)')
    plt.grid(True)
    plt.show()

if __name__ == "__main__":
    # Example usage
    sample_list = [64, 34, 25, 12, 22, 11, 90]
    print("Original list:", sample_list)
    sorted_list = insertion_sort(sample_list.copy())
    print("Sorted list:", sorted_list)
    
    # Plot time complexity
    plot_time_complexity()
