#include <stdio.h>
#define TABLE_SIZE 10

int hashTable[TABLE_SIZE];

void initTable() {
    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = -1;
}

int hash(int key) {
    return key % TABLE_SIZE;
}

void insert(int key) {
    int index = hash(key);
    int start = index;
    
    while (hashTable[index] != -1) {
        index = (index + 1) % TABLE_SIZE;
        if (index == start) {
            printf("Hash Table is full!\n");
            return;
        }
    }
    hashTable[index] = key;
}

void display() {
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++)
        printf("[%d] => %d\n", i, hashTable[i]);
}

int main() {
    initTable();
    insert(5);
    insert(15);
    insert(25);
    insert(35);
    display();
    return 0;
}
