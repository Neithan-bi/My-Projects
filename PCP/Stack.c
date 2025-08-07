#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 5

int stack[MAX];
int top = -1;

int isFull() {
    return top == MAX - 1; }

int isEmpty() {
    return top == -1;
}

void push(int val) {
    if(ifFull()){
        printf("Stack oveflow");
        return;
    }
    stack[++top] = val;
    printf("%d has been pushed onto the stack.\n",val);
}
void pop() {
    if(isEmpty()) {
        printf("Stack underflow");
        return;
    }
    stack[top--];
    printf("%d has been popped from the stack.\n",stack[top+1]);
}
void peek(){
    if(isEmpty()) {
        printf("Stack is empty");
        return;
    }
    printf("Top element is %d\n",stack[top]);
}
void display() {
    if(isEmpty()) {
        printf("Stack is empty");
        return;
    }
    printf("Stack elements are: ");
    for(int i = 0; i <= top; i++) {
        printf("%d ",stack[i]);
    }
    printf("\n");
}

int main() {
    printf("Stack Operations\n");
    pritnf("1.Push\n2.Pop\n3.Display\n4.Peek\n5.Exit\n");
    int c, v;
    scanf("%d",&c);
    switch(c) {
        case 1 :
    }
}