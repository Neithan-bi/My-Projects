#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) return i;
    }
    return -1;
}

int binarySearch(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) return mid;
        if (arr[mid] < key) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

void sortArray(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, key;

    printf("Enter array size: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter search key: ");
    scanf("%d", &key);

    int linearIndex = linearSearch(arr, n, key);
    printf("\nLinear search result: ");
    if (linearIndex == -1) {
        printf("Not found\n");
    } else {
        printf("Found at index %d\n", linearIndex);
    }

    sortArray(arr, n);
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    int binaryIndex = binarySearch(arr, 0, n - 1, key);
    printf("\n\nBinary search result: ");
    if (binaryIndex == -1) {
        printf("Not found\n");
    } else {
        printf("Found at index %d\n", binaryIndex);
    }

    return 0;
}