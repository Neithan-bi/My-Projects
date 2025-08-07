#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 100
#define NAME_LENGTH 50

char queue[MAX][NAME_LENGTH];
int front = -1, rear = -1;

int isFull() {
    return (front == (rear + 1) % MAX);
}

int isEmpty() {
    return (front == -1);
}

int isDuplicate(char name[]) {
    if (isEmpty()) return 0;
    int i = front;
    while (1) {
        if (strcmp(queue[i], name) == 0)
            return 1;
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    return 0;
}

void markAttendance(char name[]) {
    if (isFull()) {
        printf("Attendance list full!\n");
        return;
    }
    if (isDuplicate(name)) {
        printf("Duplicate entry: %s has already marked attendance.\n", name);
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
    strcpy(queue[rear], name);

    FILE *fp = fopen("attendance2.txt", "a");
    time_t now = time(NULL);
    fprintf(fp, "%s - %s", name, ctime(&now));
    fclose(fp);

    printf("Marked: %s\n", name);
}

void processAttendance() {
    if (isEmpty()) {
        printf("No attendance to process.\n");
        return;
    }
    printf("Processed: %s\n", queue[front]);
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

void displayAttendance() {
    if (isEmpty()) {
        printf("No one has marked attendance yet.\n");
        return;
    }
    printf("Attendance List:\n");
    int i = front, count = 1;
    while (1) {
        printf("%d. %s\n", count++, queue[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
}

void searchStudent(char *target) {
    if (isEmpty()) {
        printf("No attendance records.\n");
        return;
    }
    int i = front;
    do {
        if (strcmp(queue[i], target) == 0) {
            printf("Found: %s has marked attendance.\n", target);
            return;
        }
        i = (i + 1) % MAX;
    } while (i != (rear + 1) % MAX);

    printf("%s has NOT marked attendance.\n", target);
}

void resetAttendance() {
    front = rear = -1;
    FILE *fp = fopen("attendance.txt", "w");
    fclose(fp);
    printf("Attendance has been reset.\n");
}

int main() {
    int choice;
    char name[NAME_LENGTH];

    while (1) {
        printf("\n--- Attendance Marker ---\n");
        printf("1. Mark Attendance\n");
        printf("2. Process First Attendance\n");
        printf("3. Display Attendance List\n");
        printf("4. Search Student\n");
        printf("5. Reset Attendance\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                while (1) {
                    printf("Enter name (or type 'done' to stop): ");
                    fgets(name, NAME_LENGTH, stdin);
                    name[strcspn(name, "\n")] = 0;
                    if (strcmp(name, "done") == 0) break;
                    markAttendance(name);
                }
                break;
            case 2:
                processAttendance();
                break;
            case 3:
                displayAttendance();
                break;
            case 4:
                printf("Enter name to search: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0;
                searchStudent(name);
                break;
            case 5:
                resetAttendance();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
