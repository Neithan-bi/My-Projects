#include <stdio.h>

int main() {
    int a = 1;
    int *b = &a;
    int *c = &b;
    printf("%p", *b);
}