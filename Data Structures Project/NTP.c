#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100
#define DAYS 30
#define FILENAME "attendance_data.txt"
#define ADMIN_PASSWORD "admin123"
#define ELIGIBILITY_THRESHOLD 75  // Percentage threshold for eligibility

// ===== STRUCTURES =====

typedef struct {
    int id;
    char name[50];
    int attendance[DAYS];  // 1 = Present, 0 = Absent, -1 = Not marked
} Student;

typedef struct {
    Student data[SIZE];
    int count;
} AttendanceBook;

// ===== FILE HANDLING =====

void saveToFile(AttendanceBook *book) {
    FILE *fp = fopen(FILENAME, "w");
    if (!fp) {
        printf("Error saving file.\n");
        return;
    }

    for (int i = 0; i < book->count; i++) {
        fprintf(fp, "%d %s", book->data[i].id, book->data[i].name);
        for (int j = 0; j < DAYS; j++) {
            fprintf(fp, " %d", book->data[i].attendance[j]);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

void loadFromFile(AttendanceBook *book) {
    FILE *fp = fopen(FILENAME, "r");
    if (!fp) {
        printf("No saved data found. Starting with empty data.\n");
        book->count = 0;
        return;
    }

    book->count = 0;
    while (fscanf(fp, "%d %s", &book->data[book->count].id, book->data[book->count].name) == 2) {
        for (int j = 0; j < DAYS; j++) {
            fscanf(fp, "%d", &book->data[book->count].attendance[j]);
        }
        book->count++;
    }

    fclose(fp);
}

// ===== ATTENDANCE FUNCTIONS =====

void incrementAttendanceDays(AttendanceBook *book, int numDays) {
    for (int i = 0; i < book->count; i++) {
        for (int j = DAYS - numDays; j < DAYS; j++) {
            book->data[i].attendance[j] = 1;  // Mark incremented days as present
        }
    }
    saveToFile(book);
    printf("%d days of attendance marked as present for all students.\n", numDays);
}

void calculateEligibility(AttendanceBook book) {
    for (int i = 0; i < book.count; i++) {
        int present = 0, validDays = 0;
        for (int j = 0; j < DAYS; j++) {
            if (book.data[i].attendance[j] != -1) {
                validDays++;
                if (book.data[i].attendance[j] == 1)
                    present++;
            }
        }
        float percent = validDays ? (present / (float)validDays) * 100.0 : 0;
        printf("ID: %d, Name: %s, Attendance: %.2f%%\n", book.data[i].id, book.data[i].name, percent);

        // Check if attendance is below threshold and calculate how many more days are needed
        if (percent < ELIGIBILITY_THRESHOLD) {
            int neededDays = (int)((ELIGIBILITY_THRESHOLD / 100.0) * validDays) - present;
            if (neededDays > 0) {
                printf("To reach %.2f%%, student %s needs to attend %d more consecutive classes.\n",
                       ELIGIBILITY_THRESHOLD, book.data[i].name, neededDays);
            }
        }
    }
}

// ===== ADMIN FUNCTIONS =====

void addStudent(AttendanceBook *book) {
    if (book->count >= SIZE) {
        printf("Attendance book full.\n");
        return;
    }

    Student newStudent;
    printf("Enter new student ID: ");
    scanf("%d", &newStudent.id);
    getchar(); // flush newline character

    printf("Enter new student name: ");
    fgets(newStudent.name, sizeof(newStudent.name), stdin);
    newStudent.name[strcspn(newStudent.name, "\n")] = 0;

    for (int i = 0; i < DAYS; i++) {
        newStudent.attendance[i] = -1; // Initially, attendance is not marked
    }

    book->data[book->count++] = newStudent;
    saveToFile(book);
    printf("Student added successfully.\n");
}

void removeStudent(AttendanceBook *book) {
    int id;
    printf("Enter student ID to remove: ");
    scanf("%d", &id);

    int found = 0;
    for (int i = 0; i < book->count; i++) {
        if (book->data[i].id == id) {
            found = 1;
            for (int j = i; j < book->count - 1; j++) {
                book->data[j] = book->data[j + 1]; // Shift students down
            }
            book->count--;
            break;
        }
    }

    if (found) {
        saveToFile(book);
        printf("Student with ID %d removed.\n", id);
    } else {
        printf("Student ID not found.\n");
    }
}

void adminMenu(AttendanceBook *book) {
    int choice, numDays;
    char input[10];

    do {
        printf("\n--- Admin Menu ---\n");
        printf("1. Add Student\n");
        printf("2. Remove Student\n");
        printf("3. Increment Attendance Days\n");
        printf("4. Calculate Eligibility\n");
        printf("5. Exit Admin Menu\n");
        printf("Enter your choice: ");

        fgets(input, sizeof(input), stdin);
        if (sscanf(input, "%d", &choice) != 1) {
            printf("Invalid input.\n");
            continue;
        }

        switch (choice) {
            case 1:
                addStudent(book);
                break;
            case 2:
                removeStudent(book);
                break;
            case 3:
                printf("Enter number of days to increment: ");
                scanf("%d", &numDays);
                getchar(); // To consume newline
                incrementAttendanceDays(book, numDays);
                break;
            case 4:
                calculateEligibility(*book);
                break;
            case 5:
                printf("Exiting Admin Menu...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);
}

// ===== STUDENT FUNCTIONS =====

void viewAttendance(AttendanceBook *book, int studentID) {
    int studentIndex = -1;
    for (int i = 0; i < book->count; i++) {
        if (book->data[i].id == studentID) {
            studentIndex = i;
            break;
        }
    }

    if (studentIndex == -1) {
        printf("Student not found.\n");
        return;
    }

    Student student = book->data[studentIndex];
    int present = 0, validDays = 0;
    for (int i = 0; i < DAYS; i++) {
        if (student.attendance[i] != -1) {
            validDays++;
            if (student.attendance[i] == 1) {
                present++;
            }
        }
    }

    float percent = validDays ? (present / (float)validDays) * 100.0 : 0;
    printf("\n--- Attendance for %s ---\n", student.name);
    printf("Total Attendance: %.2f%%\n", percent);
    printf("Classes Attended: %d out of %d days\n", present, validDays);

    if (percent < ELIGIBILITY_THRESHOLD) {
        int neededDays = (int)((ELIGIBILITY_THRESHOLD / 100.0) * validDays) - present;
        if (neededDays > 0) {
            printf("To reach %.2f%%, you need to attend %d more consecutive classes.\n", ELIGIBILITY_THRESHOLD, neededDays);
        }
    }
}

// ===== MAIN =====

int main() {
    AttendanceBook book;
    loadFromFile(&book);

    int choice;
    char input[20];

    while (1) {
        printf("\n=== Attendance System ===\n");
        printf("1. Admin Menu\n");
        printf("2. Student Menu\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        fgets(input, sizeof(input), stdin);
        if (sscanf(input, "%d", &choice) != 1) {
            printf("Invalid input.\n");
            continue;
        }

        if (choice == 1) {
            char password[20];
            printf("Enter admin password: ");
            fgets(password, sizeof(password), stdin);
            password[strcspn(password, "\n")] = 0;
            if (strcmp(password, ADMIN_PASSWORD) == 0) {
                adminMenu(&book);
            } else {
                printf("Incorrect password.\n");
            }
        } else if (choice == 2) {
            int studentID;
            printf("Enter your student ID: ");
            scanf("%d", &studentID);
            getchar(); // To consume newline
            viewAttendance(&book, studentID);
        } else if (choice == 3) {
            printf("Exiting system...\n");
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
