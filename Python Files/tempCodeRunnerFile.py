import random
import time
import matplotlib.pyplot as plt

def merge_sort(arr):
    if len(arr) > 1:
        mid = len(arr) // 2
        left_half = arr[:mid]
        right_half = arr[mid:]

        merge_sort(left_half)
        merge_sort(right_half)

        i = j = k = 0

        while i < len(left_half) and j < len(right_half):
            if left_half[i] < right_half[j]:
                arr[k] = left_half[i]
                i += 1
            else:
                arr[k] = right_half[j]
                j += 1
            k += 1

        while i < len(left_half):
            arr[k] = left_half[i]
            i += 1
            k += 1

        while j < len(right_half):
            arr[k] = right_half[j]
            j += 1
            k += 1

def quick_sort(arr):
    def _quick_sort(items, low, high):
        if low < high:
            pi = partition(items, low, high)
            _quick_sort(items, low, pi - 1)
            _quick_sort(items, pi + 1, high)

    def partition(items, low, high):
        pivot = items[high]
        i = low - 1
        for j in range(low, high):
            if items[j] <= pivot:
                i += 1
                items[i], items[j] = items[j], items[i]
        items[i + 1], items[high] = items[high], items[i + 1]
        return i + 1

    _quick_sort(arr, 0, len(arr) - 1)

def time_sort(sort_func, arr):
    start_time = time.perf_counter()
    sort_func(arr)
    end_time = time.perf_counter()
    return end_time - start_time

def run_experiment():
    ns = [100, 500, 1000, 5000, 10000]
    merge_times = []
    quick_times = []

    for n in ns:
        arr = [random.randint(0, 100000) for _ in range(n)]

        arr_copy = arr.copy()
        merge_time = time_sort(merge_sort, arr_copy)
        merge_times.append(merge_time)

        arr_copy = arr.copy()
        quick_time = time_sort(quick_sort, arr_copy)
        quick_times.append(quick_time)

    plt.plot(ns, merge_times, label='Merge Sort')
    plt.plot(ns, quick_times, label='Quick Sort')
    plt.xlabel('Number of elements (n)')
    plt.ylabel('Time taken (seconds)')
    plt.title('Merge Sort vs Quick Sort Performance')
    plt.legend()
    plt.grid(True)
    plt.savefig('sorting_performance.png')
    plt.show()

if __name__ == '__main__':
    run_experiment()
