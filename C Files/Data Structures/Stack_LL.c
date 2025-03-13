#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;


typedef struct Stack {
    Node* top;
} Stack;

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

int isEmpty(Stack* stack) {
    return stack->top == NULL;
}
int isFull(Stack* stack) {
    Node* temp = (Node*)malloc(sizeof(Node));
    int result = temp == NULL;
    free(temp);
    return result;
}

void push(Stack* stack, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
    printf("%d pushed to stack\n", data);
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return -1; }
    Node* temp = stack->top;
    int poppedData = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return poppedData;
}

int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1; 
    }
    return stack->top->data;
}

int main() {
    Stack* stack = createStack();
    int choice, data;

    do {
        printf("\n---------------------Menu---------------------\n1. Push\n2. Pop\n3. Peek\n4. Check if Empty\n5. Check if Full\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        sleep(1);

        switch (choice) {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(stack, data);
                sleep(1);
                break;
            case 2:
                printf("Popped: %d\n", pop(stack));
                sleep(1);
                break;
            case 3:
                printf("Top element: %d\n", peek(stack));
                sleep(1);
                break;
            case 4:
                printf("Stack is %s\n", isEmpty(stack) ? "empty" : "not empty");
                sleep(1);
                break;
            case 5:
                printf("Stack is %s\n", isFull(stack) ? "full" : "not full");
                sleep(1);
                break;
            case 6:
                printf("Exiting\n");
                sleep(1);
                printf(".");
                sleep(1);
                printf(".");
                sleep(1);
                printf(".\n");
                printf("Program has been succesfully terminated.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
                sleep(1);
                printf("Returning to menu\n");
                sleep(1);
                printf(".");
                sleep(1);
                printf(".");
                sleep(1);
        }
    } while (choice != 6);
}
