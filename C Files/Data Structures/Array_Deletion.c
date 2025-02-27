#include <stdio.h>
void deleteAtEnd(int array[], int a) {
 (a == 0)   ? printf("Array is empty. Nothing to delete.\n") 
            : (a--, printf("Deleted last element. New size: %d\n", a)); }
 
void deleteAtBeginning(int array[], int a) {
 (a == 0)   ? printf("Array is empty. Nothing to delete.\n")
            : ({for (int i = 0; i < a - 1; i++) array[i] = array[i + 1];
            a--;
            printf("Deleted first element. New size: %d\n", a); }); }
 
void deleteAtPosition(int array[], int a, int position) {
 (a == 0) ? printf("Array is empty. Nothing to delete.\n")  : (position < 1 || position > a)
                ? printf("Invalid position.\n")
                : ({for (int i = position - 1; i < a - 1; i++) array[i] = array[i + 1]; 
                a--;
                printf("Deleted element at position %d. New size: %d\n", position, a);  }); }

int main() {

    int size, position, a, choice;
    printf("Enter size of array to be defined: ");
    scanf("%d", &size);
    int array[size];
    printf("Enter elements in array:\n");

    for (int i = 0; i < size; i++) {
        printf("Array[%d] = ", i);
        scanf("%d", &array[i]); }

    a = size;
    printf("\nElements in Array are:\n");

    for (int i = 0; i < a; i++) printf("%d ", array[i]);

    printf("\n");
    while (1) {
            printf("\n---Array Deletion---\n");
            printf("1. Delete at End\n");
            printf("2. Delete at Beginning\n");
            printf("3. Delete at Position\n");
            printf("4. Display Array\n");
            printf("5. Exit\n");
            printf("Enter choice: ");
            scanf("%d", &choice);
            switch (choice) {
                    case 1:
                            deleteAtEnd(array, a);
                            a--;
                            break;
                    case 2:
                            deleteAtBeginning(array, a);
                            a--;
                            break;
                    case 3:
                            printf("Enter position to delete (1 to %d): ", a);
                            scanf("%d", &position);
                            deleteAtPosition(array, a, position);
                            a--;
                            break;
                    case 4:
                            if (a == 0) printf("Array is empty.\n");
                            else {
                            printf("Array elements are: ");
                            for (int i = 0; i < a; i++) printf("%d ", array[i]);
                            printf("\n"); }
    
                            break;
                    case 5:
                            printf("Exiting...\n");
                            return 0;
                            default:
                            printf("Invalid choice.\n"); }} 
    return 0; }