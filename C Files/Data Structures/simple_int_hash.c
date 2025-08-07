#include <stdio.h>
#include <stdlib.h>
#define SIZE 5  // Small table for easy understanding

struct Node {
    int num;
    struct Node* next;
};

struct Node* table[SIZE];

void start() {
    for(int i=0; i<SIZE; i++) table[i] = NULL;
}

int hash(int n) {
    return n % SIZE;
}

void add(int n) {
    int i = hash(n);
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->num = n;
    new->next = table[i];
    table[i] = new;
}

void show() {
    printf("\nHash Table:\n");
    for(int i=0; i<SIZE; i++) {
        printf("%d: ", i);
        struct Node* curr = table[i];
        while(curr) {
            printf("%d->", curr->num);
            curr = curr->next;
        }
        printf("X\n");
    }
}

int main() {
    start();
    add(3);
    add(8);  // Collides with 3
    add(10);
    show();
    return 0;
}
