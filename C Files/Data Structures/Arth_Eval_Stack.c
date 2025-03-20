#include <stdio.h> 
#include <ctype.h> 
#include <stdlib.h> 
#define MAX 100 

typedef struct {
    int top;
    int arr[MAX];
} Stack;

void push(Stack *s, int value) {
    s->arr[++(s->top)] = value;
}

int pop(Stack *s) {
    return s->arr[(s->top)--];
}

int evalpost(char *exp) {
    Stack s;
    s.top = -1;
    for (int i = 0; exp[i] != '\0'; i++) {
        if (isdigit(exp[i])) push(&s, exp[i] - '0');
        else {
            int v2 = pop(&s);
            int v1 = pop(&s);
            switch (exp[i]) {
                case '+': push(&s, v1 + v2); break;
                case '-': push(&s, v1 - v2); break;
                case '*': push(&s, v1 * v2); break;
                case '/': push(&s, v1 / v2); break; }}}return pop(&s);
}

int main() {
    char exp[MAX];
    printf("Enter a postfix expression: ");
    scanf("%s", exp);
    printf("Result: %d\n", evalpost(exp));
    return 0;
}
