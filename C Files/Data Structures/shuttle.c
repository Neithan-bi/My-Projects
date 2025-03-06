#include <stdio.h>
#include <stdlib.h>

struct Node {
    int shuttle_id;
    struct Node* prev;
    struct Node* next;
};

void addShuttle(struct Node** head, int id) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->shuttle_id = id;

    if (*head == NULL) {
        new_node->next = new_node;
        new_node->prev = new_node;
        *head = new_node;
    } else {
        struct Node* last = (*head)->prev;
        new_node->next = *head;
        new_node->prev = last;
        last->next = new_node;
        (*head)->prev = new_node;
    }
}

void removeShuttle(struct Node** head, int id) {
    if (*head == NULL) return;

    struct Node* temp = *head;
    while (temp->shuttle_id != id) {
        temp = temp->next;
        if (temp == *head) {
            printf("Shuttle ID %d not found.\n", id);
            return;
        }
    }

    if (temp->next == temp) {
        *head = NULL;
    } else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        if (temp == *head) {
            *head = temp->next;
        }
    }
    free(temp);
}

void displayRoute(struct Node* head) {
    if (head == NULL) {
        printf("No shuttles in the route.\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("Shuttle ID: %d\n", temp->shuttle_id);
        temp = temp->next;
    } while (temp != head);
}

int main() {
    struct Node* head = NULL;
    int choice, id;

    while (1) {
        printf("\n1. Add Shuttle\n");
        printf("2. Remove Shuttle\n");
        printf("3. Display Route\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Shuttle ID to add: ");
                scanf("%d", &id);
                addShuttle(&head, id);
                break;
            case 2:
                printf("Enter Shuttle ID to remove: ");
                scanf("%d", &id);
                removeShuttle(&head, id);
                break;
            case 3:
                displayRoute(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
