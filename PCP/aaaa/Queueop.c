#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue overflow, cannot enqueue %d.\n", value);
    } else {
        if (front == -1) {
            front = 0; // Initialize front if the queue is empty
        }
        queue[++rear] = value;
        printf("Enqueued %d into the queue.\n", value);
    }
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue underflow.\n");
        return -1;
    } else {
        int dequeuedValue = queue[front++];
        if (front > rear) {
            front = rear = -1; // Reset the queue if it's empty
        }
        return dequeuedValue;
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int peek() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
        return -1;
    } else {
        return queue[front];
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Peek\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                value = dequeue();
                if (value != -1) {
                    printf("Dequeued value: %d\n", value);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                value = peek();
                if (value != -1) {
                    printf("Peeked value: %d\n", value);
                }
                break;
            case 5:
                printf("Exiting");
                sleep(1);
                printf(".");
                sleep(1);
                printf(".");
                sleep(1);
                printf(".");
                sleep(1);
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
