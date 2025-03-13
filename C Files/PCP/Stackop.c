#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 100

typedef struct Stack {
    int arr[MAX];
    int top;
}; struct Stack stack;

void push(struct Stack* stack, int value) {
    if (stack->top == MAX - 1) {
        printf("Stack overflow! Cannot push %d\n", value);
    } else {
        stack->arr[++stack->top] = value;
        printf("Pushed %d onto the stack.\n", value);
    }
}

int pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack underflow! Cannot pop from an empty stack.\n");
        return -1;}
    else return stack->arr[stack->top--]; }

void display(struct Stack* stack) {
    if (stack->top == -1) printf("Stack is empty!\n");
    else {
        printf("Stack elements: ");
        for (int i = 0; i <= stack->top; i++) printf("%d ", stack->arr[i]);
        printf("\n");
    }
}

int peek(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack is empty! Cannot peek.\n");
        return -1; }
    else return stack->arr[stack->top]; } 

int main() {
    stack.top = -1;

    int choice, value;

    while(1){
        printf("1. Push\n2. Pop\n3. Display\n4. Peek\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                value = pop(&stack);
                if (value != -1) printf("Popped value: %d\n", value);
                break;
            case 3:
                display(&stack);
                break;
            case 4:
                value = peek(&stack);
                if (value != -1) printf("Top value: %d\n", value);
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
            default: printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}


