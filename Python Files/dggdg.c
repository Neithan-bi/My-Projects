#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// -----------------------------
// Sequential Search (Iterative)
// -----------------------------
int sequential_search_iterative(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

// -----------------------------
// Sequential Search (Recursive)
// -----------------------------
int sequential_search_recursive(int arr[], int n, int target, int index) {
    if (index >= n) return -1;
    if (arr[index] == target) return index;
    return sequential_search_recursive(arr, n, target, index + 1);
}

// -----------------------------
// Binary Search (Iterative)
// -----------------------------
int binary_search_iterative(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

// -----------------------------
// Binary Search (Recursive)
// -----------------------------
int binary_search_recursive(int arr[], int left, int right, int target) {
    if (left > right) return -1;
    int mid = (left + right) / 2;
    if (arr[mid] == target) return mid;
    else if (arr[mid] < target) return binary_search_recursive(arr, mid + 1, right, target);
    else return binary_search_recursive(arr, left, mid - 1, target);
}

// -----------------------------
// Benchmark Function
// -----------------------------
void benchmark_searches() {
    int sizes[] = {50, 100, 200, 300, 400, 500};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    printf("%-5s %-12s %-12s %-12s %-12s\n", "n", "Seq_Iter", "Seq_Rec", "Bin_Iter", "Bin_Rec");

    for (int s = 0; s < num_sizes; s++) {
        int n = sizes[s];
        int *arr = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) arr[i] = i; // sorted array for binary search
        int target = rand() % n;  // pick random target

        clock_t start, end;
        double seq_iter_time, seq_rec_time, bin_iter_time, bin_rec_time;

        // Sequential Iterative
        start = clock();
        sequential_search_iterative(arr, n, target);
        end = clock();
        seq_iter_time = ((double)(end - start)) / CLOCKS_PER_SEC;

        // Sequential Recursive
        start = clock();
        sequential_search_recursive(arr, n, target, 0);
        end = clock();
        seq_rec_time = ((double)(end - start)) / CLOCKS_PER_SEC;

        // Binary Iterative
        start = clock();
        binary_search_iterative(arr, n, target);
        end = clock();
        bin_iter_time = ((double)(end - start)) / CLOCKS_PER_SEC;

        // Binary Recursive
        start = clock();
        binary_search_recursive(arr, 0, n - 1, target);
        end = clock();
        bin_rec_time = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("%-5d %-12f %-12f %-12f %-12f\n", n, seq_iter_time, seq_rec_time, bin_iter_time, bin_rec_time);

        free(arr);
    }
}

// -----------------------------
// Main Function
// -----------------------------
int main() {
    srand(time(NULL));
    benchmark_searches();
    return 0;
}
