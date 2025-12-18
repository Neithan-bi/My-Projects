def find_max_min(arr, low, high):
    if low == high:
        return arr[low], arr[low]
    if high == low + 1:
        if arr[low] > arr[high]:
            return arr[low], arr[high]
        else:
            return arr[high], arr[low]
    mid = (low + high) // 2
    max1, min1 = find_max_min(arr, low, mid)
    max2, min2 = find_max_min(arr, mid + 1, high)
    return max(max1, max2), min(min1, min2)
def main():
    arr = [3, 5, 1, 2, 4, 8, 7, 6]
    maximum, minimum = find_max_min(arr, 0, len(arr) - 1)
    print("Array:", arr)
    print("Maximum:", maximum)
    print("Minimum:", minimum)
if __name__ == "__main__":
    main()
