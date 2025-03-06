#include <stdio.h>
#include <stdlib.h>

struct DNode {
    int data;
    struct DNode* next;
    struct DNode* prev;
};

struct DNode* insertAtEnd(struct DNode* head, int data) {
    struct DNode* newNode = (struct DNode*)malloc(sizeof(struct DNode));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        return newNode;
    }

    struct DNode* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

struct DNode* deleteByValue(struct DNode* head, int value) {
    struct DNode* temp = head;
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }
    if (temp == NULL) return head;
    if (temp->prev != NULL) temp->prev->next = temp->next;
    if (temp->next != NULL) temp->next->prev = temp->prev;
    if (temp == head) head = temp->next;
    free(temp);
    return head;
}

struct DNode* deleteByPosition(struct DNode* head, int pos) {
    if (head == NULL) return NULL;
    struct DNode* temp = head;
    if (pos == 1) {
        head = temp->next;
        if (head) head->prev = NULL;
        free(temp);
        return head;
    }
    for (int i = 1; temp != NULL && i < pos; i++) {
        temp = temp->next;
    }
    if (temp == NULL) return head;
    if (temp->prev) temp->prev->next = temp->next;
    if (temp->next) temp->next->prev = temp->prev;
    free(temp);
    return head;
}

void display(struct DNode* head) {
    struct DNode* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct DNode* Head = NULL;
    int choice, data, pos;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at end\n");
        printf("2. Delete by value\n");
        printf("3. Delete by position\n");
        printf("4. Display Doubly List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                Head = insertAtEnd(Head, data);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &data);
                Head = deleteByValue(Head, data);
                break;
            case 3:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                Head = deleteByPosition(Head, pos);
                break;
            case 4:
                display(Head);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
