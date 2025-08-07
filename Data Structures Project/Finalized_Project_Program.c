#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX 100

struct Student {
    char name[50];
    int attended;
    int total;
    float percentage;
};

struct Queue {
    struct Student data[MAX];
    int front, rear;
};

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

int isStudentPresent(struct Queue *q, const char name[]) {
    for (int i = q->front; i <= q->rear; i++) {
        if (strcmp(q->data[i].name, name) == 0) {
            return 1;
        }
    }
    return 0;
}

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

void removeStudent(struct Queue *q, char name[]) {
    if (isEmpty(q)) return;

    int found = 0;
    for (int i = q->front; i <= q->rear; i++) {
        if (strcmp(q->data[i].name, name) == 0) {
            found = 1;
            for (int j = i; j < q->rear; j++) {
                q->data[j] = q->data[j + 1];  // shift left
            }
            q->rear--;
            break;
        }
    }

    if (found)
        printf("Student '%s' removed successfully.\n", name);
    else
        printf("Student not found.\n");
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
        printf("%%      : %.2f%% [%s]\n\n", s->percentage, s->percentage < 80.0 ? "LOW ATTENDANCE" : "GOOD");
    }
}

// BST Functions
struct BSTNode* insertBST(struct BSTNode *root, struct Student s) {
    if (root == NULL) {
        struct BSTNode* newNode = (struct BSTNode*)malloc(sizeof(struct BSTNode));
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
    if (root==NULL) printf("No Student record to display.");
        displayBST(root->left);
        printf("%s - %.2f%%\n", root->data.name, root->data.percentage);
        displayBST(root->right);
    }


void rebuildBST(struct Queue *q, struct BSTNode **root) {
    *root = NULL;
    for (int i = q->front; i <= q->rear; i++) {
        q->data[i].percentage = q->data[i].total == 0 ? 0.0 : (q->data[i].attended * 100.0f) / q->data[i].total;
        *root = insertBST(*root, q->data[i]);
    }
}

// File Functions
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
    if (!fp) {
        printf("No previous data found. Starting fresh...\n");
        return;
    }

    struct Student s;
    int count = 0;
    while (fscanf(fp, "%s %d %d %f", s.name, &s.attended, &s.total, &s.percentage) == 4) {
        enqueue(q, s);
        count++;
    }
    fclose(fp);

    if (count == 0) {
        printf("Data file is empty. Starting fresh...\n");
    } else {
        printf("Loaded %d student(s) from file.\n", count);
    }
}

// Attendance Increment
void adminIncrement(struct Queue *q, struct BSTNode **root) {
    if (isEmpty(q)) {
        printf("\nNo students to update attendance.\n");
        return;
    }
    int days;
    printf("Enter number of days to increment: ");
    scanf("%d", &days);
    getchar();
    srand(time(NULL));
    for (int d = 0; d < days; d++) {
        for (int i = q->front; i <= q->rear; i++) {
            q->data[i].total++;
            int present = (rand() % 10) < 8;
            if (present) {
                q->data[i].attended++;
            }
        }
    }
    rebuildBST(q, root);
    printf("\nAttendance randomly updated for %d days!\n", days);
}

// Student Search
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

// Menus
void adminMenu(struct Queue *q, struct BSTNode **root) {
    while (1) {
        printf("\n--- Admin Menu ---\n");
        printf("1. Add Student\n");
        printf("2. Remove Student\n");
        printf("3. Show Attendance Report\n");
        printf("4. Show Sorted BST Report\n");
        printf("5. Increment Attendance Randomly\n");
        printf("6. Back to Main Menu\n");
        printf("Enter choice: ");
        char input[10];
        int choice;
        fgets(input, sizeof(input), stdin);
        if (sscanf(input, "%d", &choice) != 1) {
            printf("Invalid choice. Please enter a number.\n");
            continue;
        }
        switch (choice) {
            case 1: {
                struct Student s;
                printf("\nEnter student name: ");
                fgets(s.name, sizeof(s.name), stdin);
                s.name[strcspn(s.name, "\n")] = '\0';
                toLowerCase(s.name);  // Convert input to lowercase for uniformity
                if (isStudentPresent(q, s.name)) {
                    printf("Student '%s' already exists.\n", s.name);
                    break;
                }
                printf("Enter total classes: ");
                scanf("%d", &s.total);
                getchar();
                printf("Enter attended classes: ");
                scanf("%d", &s.attended);
                getchar();
                if (s.attended > s.total) {
                    printf("Attended classes cannot exceed total classes. Setting attended = 0.\n");
                    s.attended = 0;
                }
                s.percentage = s.total == 0 ? 0.0 : (s.attended * 100.0f) / s.total;
                enqueue(q, s);
                *root = insertBST(*root, s);
                printf("Student '%s' added successfully.\n", s.name);
                break;
            }
            case 2: {
                char name[50];
                printf("Enter student name to remove: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';
                toLowerCase(name);
                removeStudent(q, name);
                rebuildBST(q, root);
                break;
            }
            case 3:
                showReport(q);
                break;
            case 4:
                printf("\n--- Sorted Attendance Report ---\n");
                displayBST(*root);
                break;
            case 5:
                adminIncrement(q, root);
                break;
            case 6:
                return;
            default:
                printf("Invalid choice.\n");
        }
    }
}

void studentMenu(struct Queue *q) {
    while (1) {
        printf("\n--- Student Menu ---\n");
        printf("1. Search Student by Name\n");
        printf("2. Display All Students with Attendance\n");
        printf("3. Exit to Main Menu\n");
        printf("Enter your choice: ");
        char input[10];
        int choice;
        fgets(input, sizeof(input), stdin);
        if (sscanf(input, "%d", &choice) != 1) {
            printf("Invalid choice. Please enter a number.\n");
            continue;
        }
        switch (choice) {
            case 1: {
                if (isEmpty(q)) {
                    printf("\nNo students to search.\n");
                    break;
                }
                char name[50];
                printf("Enter student name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';
                toLowerCase(name);
                searchStudent(q, name);
                break;
            }
            case 2:
                showReport(q);
                break;
            case 3:
                printf("Returning to Main Menu...\n");
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

// Main
int main() {
    struct Queue q;
    initialize(&q);
    struct BSTNode *root = NULL;
    loadFromFile(&q, "attendance.txt");  // Load ONCE at the start
    if (!isEmpty(&q)) {
        rebuildBST(&q, &root);
    }

    while (1) {
        printf("\n==== Main Menu ====\n");
        printf("1. Admin Menu\n");
        printf("2. Student Menu\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        char input[10];
        int mainchoice;
        fgets(input, sizeof(input), stdin);
        if (sscanf(input, "%d", &mainchoice) != 1) {
            printf("Invalid choice. Please enter a number.\n");
            continue;
        }
        switch (mainchoice) {
            case 1:
                adminMenu(&q, &root);
                break;
            case 2:
                studentMenu(&q);
                break;
            case 3:
                storeToFile(&q, "attendance.txt");  // Save ONCE at the end
                printf("Data saved. Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
