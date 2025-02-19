    #include <stdio.h>
    #include <stdlib.h>

    struct node {
        int data;
        struct node* next;
    };

    struct node* Beginning(struct node* head, int data) {
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = data;
        newnode->next = head;
        return newnode;
    }

    struct node* Position(struct node* head, int data, int pos) {
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = data;
        if (pos == 1) {
            newnode->next = head;
            return newnode;}
        struct node* temp = head;
        for (int i = 1; temp != NULL && i < pos-1; i++) {
            temp = temp->next;}
        if (temp == NULL) {
            printf("Position out of bounds.\n");
            free(newnode);
            return head;}
        newnode->next = temp->next;
        temp->next = newnode;
        return head;}

    struct node* End(struct node* head, int data) {
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = data;
        newnode->next = NULL;
        if (head == NULL) {
            return newnode;}
        struct node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;}
        temp->next = newnode;
        return head;}

    void displayList(struct node* head) {
        struct node* temp = head;
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;}
        printf("NULL\n");}

    struct node* deleteBeginning(struct node* head) {
        if (head == NULL) {
            printf("List is empty.\n");
            return NULL;
        }
        struct node* temp = head;
        head = head->next;
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
        struct node* prev = NULL;
        for (int i = 1; temp != NULL && i < pos; i++) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Position out of bounds.\n");
            return head;
        }
        prev->next = temp->next;
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
        struct node* prev = NULL;
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        free(temp);
        return head;
    }

    int main() {
        struct node* head = NULL;
        int choice, data, pos;
        while (1) {
            printf("\n-----Menu-----\n");
            printf("1. Insert at Beginning\n");
            printf("2. Insert at Position\n");
            printf("3. Insert at End\n");
            printf("4. Display List\n");
            printf("5. Delete from Beginning\n");
            printf("6. Delete from Position\n");
            printf("7. Delete from End\n");
            printf("8. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            switch (choice) {
                case 1:
                    printf("Enter data: ");
                    scanf("%d", &data);
                    head = Beginning(head, data);
                    break;
                case 2:
                    printf("Enter data: ");
                    scanf("%d", &data);
                    printf("Enter position: ");
                    scanf("%d", &pos);
                    head = Position(head, data, pos);
                    break;
                case 3:
                    printf("Enter data: ");
                    scanf("%d", &data);
                    head = End(head, data);
                    break;
                case 4:
                    printf("Linked List: ");
                    displayList(head);
                    break;
                case 5:
                    head = deleteBeginning(head);
                    break;
                case 6:
                    printf("Enter position: ");
                    scanf("%d", &pos);
                    head = deletePosition(head, pos);
                    break;
                case 7:
                    head = deleteEnd(head);
                    break;
                case 8:
                    printf("Exiting program.\n");
                    return 0;
                default:
                    printf("Try again.\n");
            }
        }
        return 0;
    }
