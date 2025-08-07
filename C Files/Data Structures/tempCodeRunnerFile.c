#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 5

struct WordEntry {
    char word[20];
    char definition[50];
    struct WordEntry* next;
};

struct WordEntry* dictionary[TABLE_SIZE];

void setupEmptyDictionary() {
    printf("Creating empty dictionary...\n");
    for(int i=0; i<TABLE_SIZE; i++) {
        dictionary[i] = NULL;
    }
}

int getBucketNumber(char* word) {
    int sum = 0;
    for(int i=0; word[i] != '\0'; i++) {
        sum += word[i];
    }
    return sum % TABLE_SIZE;
}

void addNewWord(char* word, char* definition) {
    int bucket = getBucketNumber(word);
    printf("\nAdding '%s': ", word);
    printf("(Goes to bucket %d)\n", bucket);

    struct WordEntry* newEntry = malloc(sizeof(struct WordEntry));
    strcpy(newEntry->word, word);
    strcpy(newEntry->definition, definition);
    newEntry->next = NULL;

    if(dictionary[bucket] == NULL) {
        dictionary[bucket] = newEntry;
        printf("Added as first in bucket %d\n", bucket);
    } else {
        printf("Added to existing chain in bucket %d\n", bucket);
        newEntry->next = dictionary[bucket];
        dictionary[bucket] = newEntry;
    }
}

void findDefinition(char* word) {
    int bucket = getBucketNumber(word);
    printf("\nLooking for '%s' in bucket %d...\n", word, bucket);

    struct WordEntry* current = dictionary[bucket];
    while(current != NULL) {
        if(strcmp(current->word, word) == 0) {
            printf("FOUND: %s = %s\n", word, current->definition);
            return;
        }
        current = current->next;
    }
    printf("'%s' not found in dictionary\n", word);
}

void showDictionaryMap() {
    printf("\nDictionary Structure:\n");
    printf("--------------------\n");
    for(int i=0; i<TABLE_SIZE; i++) {
        printf("Bucket %d: ", i);
        struct WordEntry* current = dictionary[i];
        while(current != NULL) {
            printf("[%s]->", current->word);
            current = current->next;
        }
        printf("END\n");
    }
}

int main() {
    setupEmptyDictionary();
    
    printf("\n=== Simple Dictionary Learning Tool ===\n");
    
    addNewWord("cat", "A furry animal that meows");
    addNewWord("dog", "A loyal pet that barks");
    addNewWord("apple", "A crunchy fruit");
    addNewWord("banana", "A yellow curved fruit");
    addNewWord("apple", "A tech company"); // Demonstrate collision
    
    showDictionaryMap();
    
    printf("\n=== Testing Dictionary ===\n");
    findDefinition("dog");
    findDefinition("banana");
    findDefinition("orange"); // Not in dictionary
    
    return 0;
}
