#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 100

struct Student {
    char name[50];
    int attended;
    int total;
    float percentage;
};

// Queue structure
struct Queue {
    struct Student data[MAX];
    int front, rear;
};

// BST Node
struct BSTNode {
    struct Student data;
    struct BSTNode *left, *right;
};

// Queue Functions
void initialize(struct Queue *q) {
    q->front = q->rear = -1;
}

int isEmpty(struct Queue *q) {
    return q->front == -1 || q->front > q->rear;
}

int isFull(struct Queue *q) {
    return q->rear == MAX - 1;
}

void enqueue(struct Queue *q, struct Student s) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    if (q->front == -1) q->front = 0;
    q->rear++;
    q->data[q->rear] = s;
}

void removeStudent(struct Queue *q, char name[]) {
    if (isEmpty(q)) return;

    int found = 0;
    struct Queue temp;
    initialize(&temp);

    for (int i = q->front; i <= q->rear; i++) {
        if (strcmp(q->data[i].name, name) == 0) {
            found = 1;
            continue;
        }
        enqueue(&temp, q->data[i]);
    }
    *q = temp;

    if (found) printf("Student '%s' removed successfully.\n", name);
    else printf("Student not found.\n");
}

void showReport(struct Queue *q) {
    if (isEmpty(q)) {
        printf("\nNo student records to display.\n");
        return;
    }

    printf("\nTotal Students: %d\n", q->rear - q->front + 1);
    printf("\n--- Attendance Report ---\n");

    for (int i = q->front; i <= q->rear; i++) {
        struct Student *s = &q->data[i];
        int absent = s->total - s->attended;
        s->percentage = s->total == 0 ? 0.0 : (s->attended * 100.0f) / s->total;

        printf("Name   : %s\n", s->name);
        printf("Present: %d\n", s->attended);
        printf("Absent : %d\n", absent);
        printf("%%      : %.2f%% [%s]\n\n", s->percentage,
               s->percentage < 80.0 ? "LOW ATTENDANCE" : "GOOD");
    }
}

// BST Functions
struct BSTNode* insertBST(struct BSTNode *root, struct Student s) {
    if (root == NULL) {
        struct BSTNode *newNode = (struct BSTNode*)malloc(sizeof(struct BSTNode));
        newNode->data = s;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (s.percentage < root->data.percentage)
        root->left = insertBST(root->left, s);
    else
        root->right = insertBST(root->right, s);
    return root;
}

void displayBST(struct BSTNode *root) {
    if (root) {
        displayBST(root->left);
        printf("%s - %.2f%%\n", root->data.name, root->data.percentage);
        displayBST(root->right);
    }
}

void rebuildBST(struct Queue *q, struct BSTNode **root) {
    *root = NULL;
    for (int i = q->front; i <= q->rear; i++) {
        q->data[i].percentage = q->data[i].total == 0 ? 0.0 : (q->data[i].attended * 100.0f) / q->data[i].total;
        *root = insertBST(*root, q->data[i]);
    }
}

// File Operations
void storeToFile(struct Queue *q, const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = q->front; i <= q->rear; i++) {
        struct Student *s = &q->data[i];
        fprintf(fp, "%s %d %d %.2f\n", s->name, s->attended, s->total, s->percentage);
    }
    fclose(fp);
    printf("Data saved to file successfully.\n");
}

void loadFromFile(struct Queue *q, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) return;

    struct Student s;
    while (fscanf(fp, "%s %d %d %f", s.name, &s.attended, &s.total, &s.percentage) != EOF) {
        enqueue(q, s);
    }
    fclose(fp);
    printf("Data loaded from file successfully.\n");
}

// Admin random attendance updater
void adminIncrement(struct Queue *q, struct BSTNode **root) {
    if (isEmpty(q)) {
        printf("\nNo students to update attendance.\n");
        return;
    }

    int days;
    printf("Enter number of days to increment: ");
    scanf("%d", &days);
    getchar(); // clear newline

    srand(time(NULL));

    for (int d = 0; d < days; d++) {
        for (int i = q->front; i <= q->rear; i++) {
            q->data[i].total++;
            int present = rand() % 2; // 0 = Absent, 1 = Present
            if (present) {
                q->data[i].attended++;
            }
        }
    }

    rebuildBST(q, root);
    printf("\nAttendance randomly updated for %d days!\n", days);
}

// Search Student
void searchStudent(struct Queue *q, char name[]) {
    for (int i = q->front; i <= q->rear; i++) {
        if (strcmp(q->data[i].name, name) == 0) {
            struct Student *s = &q->data[i];
            printf("\n--- Student Found ---\n");
            printf("Name     : %s\n", s->name);
            printf("Attended : %d\n", s->attended);
            printf("Total    : %d\n", s->total);
            printf("Percent  : %.2f%%\n", s->percentage);
            return;
        }
    }
    printf("Student not found.\n");
}

// Main Program
int main() {
    struct Queue q;
    initialize(&q);
    struct BSTNode *root = NULL;

    loadFromFile(&q, "attendance.txt");
    rebuildBST(&q, &root);

    char input[20];

    while (1) {
        printf("\n==== Attendance Management Menu ====\n");
        printf("1. Add Student\n");
        printf("2. Remove Student\n");
        printf("3. Show Attendance Report\n");
        printf("4. Show BST (Sorted by Percentage)\n");
        printf("5. Search Student by Name\n");
        printf("6. Exit and Save\n");
        printf("Enter your choice (or type 'admin'): ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "admin") == 0) {
            adminIncrement(&q, &root);
            continue;
        }

        int choice = atoi(input);
        switch (choice) {
            case 1: {
                struct Student s;
                printf("\nEnter student name: ");
                fgets(s.name, sizeof(s.name), stdin);
                s.name[strcspn(s.name, "\n")] = '\0';

                printf("Enter total number of classes: ");
                scanf("%d", &s.total);
                getchar();

                printf("Enter number of classes attended by %s: ", s.name);
                scanf("%d", &s.attended);
                getchar();

                if (s.attended > s.total) {
                    printf("Error: attended classes can't be more than total classes (%d). Setting attended = 0.\n", s.total);
                    s.attended = 0;
                }

                s.percentage = s.total == 0 ? 0.0 : (s.attended * 100.0f) / s.total;

                enqueue(&q, s);
                root = insertBST(root, s);
                printf("\nStudent added successfully!\n");
                break;
            }
            case 2: {
                char name[50];
                printf("Enter student name to remove: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';
                removeStudent(&q, name);
                rebuildBST(&q, &root);
                break;
            }
            case 3:
                showReport(&q);
                break;
            case 4:
                printf("\n--- Attendance Report (Sorted by Percentage) ---\n");
                displayBST(root);
                break;
            case 5: {
                char name[50];
                printf("Enter name to search: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';
                searchStudent(&q, name);
                break;
            }
            case 6:
                storeToFile(&q, "attendance.txt");
                printf("\nExiting... Thank you!\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
