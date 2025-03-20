#include <stdio.h>

int main() {
    int n[2];
    int *p=n;
    char op;
    int c;
    printf("Enter the first & second number : ");
    scanf("%d %d",p);
    printf("Enter the operator ('+' , '-' , '*' , '/'): ");
    scanf(" %c",&op);

    switch(op) {
        case '+':
            c = *p + *(p+1);
            break;
        case '-':
            c = *p - *(p+1);
            break;
        case '*':
            c = *p * *(p+1);
            break;
        case '/':
            if(*(p+1) != 0) c = *p / *(p+1);
            else {
                printf("Division by zero is not allowed.\n");
                return 1;
            }
            break;
        default:
            printf("Invalid operator.\n");
            return 1;
    }
}