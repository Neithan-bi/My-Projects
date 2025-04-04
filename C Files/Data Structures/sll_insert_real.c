#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

struct Node* deleteByValue(struct Node* head, int value) {
    struct Node *temp = head, *prev = NULL;
    if (temp != NULL && temp->data == value) {
        head = temp->next;
        free(temp);
        return head;
    }
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return head;
    prev->next = temp->next;
    free(temp);
    return head;
}

struct Node* deleteByPosition(struct Node* head, int pos) {
    if (head == NULL) return NULL;
    struct Node* temp = head;
    if (pos == 1) {
        head = temp->next;
        free(temp);
        return head;
    }
    for (int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) return head;
    struct Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
    return head;
}

void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* Head = NULL;
    int choice, data, pos;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at end\n");
        printf("2. Delete by value\n");
        printf("3. Delete by position\n");
        printf("4. Display Singly List\n");
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
