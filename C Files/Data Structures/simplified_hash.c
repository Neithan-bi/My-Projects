#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

struct Node {
    int value;
    struct Node* next;
};

struct Node* table[SIZE];

void init() {
    for(int i=0; i<SIZE; i++) table[i] = NULL;
}

int hash(int key) {
    return key % SIZE;
}

void insert(int key) {
    int i = hash(key);
    struct Node* new = malloc(sizeof(struct Node));
    new->value = key;
    new->next = table[i];
    table[i] = new;
}

void display() {
    printf("\nHash Table:\n");
    for(int i=0; i<SIZE; i++) {
        printf("[%d]: ", i);
        struct Node* curr = table[i];
        while(curr) {
            printf("%d -> ", curr->value);
            curr = curr->next;
        }
        printf("X\n");
    }
}

int main() {
    init();
    insert(5);
    insert(15);
    insert(25);
    insert(35);
    display();
    return 0;
}
