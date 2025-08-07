#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void invalid() {
    printf("Invalid. Please enter a valid number.\n");
    exit(0);
}

int search(int arr[], int size, int element) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == element) return i;
    }
    return -1;
}

int insert(int arr[], int size, int element, int index) {
    if(index < 0 || index > size || size >= MAX_SIZE) return -1;
    for(int i = size; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = element;
    return size + 1;
}

int delete(int arr[], int size, int index) {
    if(index < 0 || index >= size) return -1;
    for(int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    return size - 1;
}

void display(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX_SIZE];
    int size, element, index;

    printf("Enter the size of the array (max %d): ", MAX_SIZE);
    scanf("%d", &size);
    if(size <= 0 || size > MAX_SIZE) invalid();

    printf("Enter the elements of the array: ");
    for(int i = 0; i < size; i++) scanf("%d", &arr[i]);

    printf("Enter the element to search: ");
    scanf("%d", &element);
    index = search(arr, size, element);
    if(index != -1) {
        printf("Element %d found at index %d\n", element, index);
    } else {
        printf("Element %d not found\n", element);
    }

    printf("Enter the element to insert: ");
    scanf("%d", &element);
    printf("Enter the index to insert at: ");
    scanf("%d", &index);
    int newSize = insert(arr, size, element, index);
    if(newSize == -1) {
        printf("Insertion failed.\n");
    } else {
        size = newSize;
        printf("Array after insertion: ");
        display(arr, size);
    }

    printf("Enter the index to delete: ");
    scanf("%d", &index);
    newSize = delete(arr, size, index);
    if(newSize == -1) {
        printf("Deletion failed.\n");
    } else {
        size = newSize;
        printf("Array after deletion: ");
        display(arr, size);
    }

    return 0;
}
