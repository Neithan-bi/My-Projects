#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;   
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1; }
        arr[j + 1] = key; }
}

double measureTime(int n) {
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 0.0;
    }    
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000 + 1;
    }
    clock_t start = clock();
    insertionSort(arr, n);
    clock_t end = clock(); 
    double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
    free(arr);
    return timeTaken;
}
int main() {
    srand(time(NULL));
    int sample[] = {64, 34, 25, 12, 22, 11, 90};
    int sampleSize = sizeof(sample) / sizeof(sample[0]);
    printf("Original list: ");
    for (int i = 0; i < sampleSize; i++) {
        printf("%d ", sample[i]);
    }
    printf("\n");
    insertionSort(sample, sampleSize);

    printf("Sorted list: ");
    for (int i = 0; i < sampleSize; i++) {
        printf("%d ", sample[i]);
    }
    printf("\n\n");
    int n_values[10];
    printf("Time taken for 10 random n values:\n");
    printf("n\tTime (seconds)\n");
    printf("----------------\n");
    for (int i = 0; i < 10; i++) {
        n_values[i] = (rand() % 951) + 50; // Random between 50-1000
        double time_taken = measureTime(n_values[i]);
        printf("%d\t%.6f\n", n_values[i], time_taken);
    }
    return 0;
}
