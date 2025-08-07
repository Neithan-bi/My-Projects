#include <stdio.h>
#define SIZE 5

int arr[SIZE];
int front = -1;
int rear = -1;

void insert(int value) {
    if ((front == 0 && rear == SIZE - 1) || (rear == (front - 1) % (SIZE - 1))) {
        printf("Overflow\\n");
        return;
    } else if (front == -1) {
        front = rear = 0;
        arr[rear] = value;
    } else if (rear == SIZE - 1 && front != 0) {
        rear = 0;
        arr[rear] = value;
    } else {
        rear++;
        arr[rear] = value;
    }
}

void delete() {
    if (front == -1) {
        printf("Underflow\\n");
        return;
    }
    printf("Deleted %d\\n", arr[front]);
    if (front == rear) {
        front = rear = -1;
    } else if (front == SIZE - 1) {
        front = 0;
    } else {
        front++;
    }
}

void display() {
    if (front == -1) {
        printf("Empty\\n");
        return;
    }
    printf("Elements: ");
    if (rear >= front) {
        for (int i = front; i <= rear; i++)
            printf("%d ", arr[i]);
    } else {
        for (int i = front; i < SIZE; i++)
            printf("%d ", arr[i]);
        for (int i = 0; i <= rear; i++)
            printf("%d ", arr[i]);
    }
    printf("\\n");
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    display();
    delete();
    delete();
    display();
    insert(60);
    insert(70);
    display();
    insert(80);
    return 0;
}
