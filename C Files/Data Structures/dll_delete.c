#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

struct node* insertatEND(struct node* head, int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    if (head == NULL) {
        return newnode;
    }
    struct node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
    return head;
}
struct node* insertatBEGINNING(struct node* head, int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = head;
    newnode->prev = NULL;

    if (head != NULL) {
        head->prev = newnode;
    }

    return newnode;
}

struct node* insertatPOSITION(struct node* head, int data, int pos) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    if (pos == 1) {
        newnode->next = head;
        if (head != NULL) head->prev = newnode;
        return newnode;
    }
    struct node* temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of bounds. Inserting at end.\n");
        struct node* temp = head;
        while (temp->next != NULL) {
        temp = temp->next;
         }
        temp->next = newnode;
        newnode->prev = temp;
        return head;
    }
    newnode->next = temp->next;
    if (temp->next != NULL) temp->next->prev = newnode;
    temp->next = newnode;
    newnode->prev = temp;
    return head;
}




struct node* deleteBeginning(struct node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    struct node* temp = head;
    head = head->next;
    if (head != NULL) head->prev = NULL;
    free(temp);
    return head;
}

struct node* deletePosition(struct node* head, int pos) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    if (pos == 1) {
        return deleteBeginning(head);
    }
    struct node* temp = head;
    for (int i = 1; temp != NULL && i < pos; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of bounds.\n");
        return head;
    }
    if (temp->prev != NULL) temp->prev->next = temp->next;
    if (temp->next != NULL) temp->next->prev = temp->prev;
    free(temp);
    return head;
}

struct node* deleteEnd(struct node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    struct node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
    return head;
}

void displayList(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct node* head = NULL;
    int choice, pos, data;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from Position\n");
        printf("6. Delete from End\n");
        printf("7. Display List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertatBEGINNING(head, data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertatEND(head, data);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &pos);
                head = insertatPOSITION(head, data, pos);
                break;
            case 4:
                head = deleteBeginning(head);
                break;
            case 5:
                printf("Enter position: ");
                scanf("%d", &pos);
                head = deletePosition(head, pos);
                break;
            case 6:
                head = deleteEnd(head);
                break;
            case 7:
                printf("Doubly Linked List: ");
                displayList(head);
                break;
            case 8:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

