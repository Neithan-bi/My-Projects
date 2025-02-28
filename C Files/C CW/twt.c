#include <stdio.h>
#include <stdlib.h>

// Define a struct for Student
typedef struct {
    int id;
    float marks;
} studData;

int main() {
    studData *students = NULL;
    int count = 0, ch;

    while (1) {
        // Menu creation
        printf("\n-------Menu-------\n");
        printf("1. Add Student\n");
        printf("2. Display Student Records\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        if (ch == 1) {
            // Increase student count
            count++;

            // Allocate memory for the first student or expand memory for new students
            if (students == NULL) {
                students = (studData *)malloc(count * sizeof(studData));
            } else {
                students = (studData *)realloc(students, count * sizeof(studData));
            }

            if (students == NULL) {
                printf("Memory allocation failed!\n");
                return 1; // Indicates error
            }

            // Get student details directly in the allocated memory
            printf("Enter Student ID: ");
            scanf("%d", &students[count - 1].id);
            printf("Enter Marks: ");
            scanf("%f", &students[count - 1].marks);
        } 
        else if (ch == 2) {
            // Display all student records
            if (count == 0) {
                printf("No student records available.\n");
            } else {
                printf("\nStudent Records:\n");
                for (int i = 0; i < count; i++) {
                    printf("ID: %d, Marks: %.2f\n", students[i].id, students[i].marks);
                }
            }
        } 
        else if (ch == 3) {
            // Free allocated memory and exit
            free(students);
            printf("Memory freed. Exiting...\n");      {

            } 
            break;
        } 
        else {
            printf("Enter a valid choice (1 to 3).\n");
        }
    }   
    return 0;
}
