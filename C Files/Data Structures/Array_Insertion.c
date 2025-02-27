#include <stdio.h>
//Coded without using define so as to get the size from the user themselves.
void insertAtEnd(int a,int array[],int element,int size){
    (a >= size) ? printf("Array is full.") : (array[a]= element, a++);
                return;
   }
void insertAtPosition(int array[], int a, int position, int element, int size) {
    (a >= size) ? printf("Array is full.\n")  : (position < 1 || position > a + 1)
                ? printf("Invalid Position.\n")
                : ({for (int i = a; i >= position - 1; i--) array[i + 1] = array[i]; 
                    array[position - 1] = element;
                    printf("Inserted %d at position %d.\n", element, position); });
                    return;
   }

void insertAtBeginning(int array[],int a,int size,int element){
    (a >= size) ? printf("Array is full.") 
                : ({for (int i = a; i >=0; i--) array[i] = array[i-1]; });  
                    array[0] = element;
                    printf("Inserted %d at the beginning.\n",element);
                    return;
   }
   
void displayArray(int array[], int a) {
    (a == 0)    ? printf("Array is empty.\n") 
                : ({printf("Array elements are :-\n");
                    for (int i = 0; i < a; i++) printf("%d ", array[i]);
                    printf("\n");});
                    return;
    }
    
int main() {
    int size,position,element,a=0,choice;
   
    printf("Enter size of array to be defined :-\n");
    scanf("%d",&size);
    int array[size];

    while(1){
    printf("\n---Array Insertion---\n");
    printf("1. Insert at End.\n");
    printf("2. Insert at Beginning.\n");
    printf("3. Insert at position.\n");
    printf("4. Display Array.\n");
    printf("5. Exit.\n");
    printf("\n");
    printf("Enter choice : \n");
    scanf("%d",&choice);
   
    switch(choice) {
            case 1 :
                    printf("Enter element to insert: ");
                    scanf("%d", &element);
                    insertAtEnd(a, array, element, size);
                    a++;
                    break;
            case 2:
                    printf("Enter element to insert: ");
                    scanf("%d", &element);
                    insertAtBeginning(array, a, size, element);
                    a++;
                    break;
            case 3:
                    printf("Enter position to insert (1 to %d): ", size);
                    scanf("%d", &position);
                    printf("Enter element to insert: ");
                    scanf("%d", &element);
                    insertAtPosition(array, a, position, element, size);
                    a++;
                    break;
            case 4:
                    printf("Elements in Array are:\n");
                    displayArray(array, a);
                    break;
            case 5:
                    printf("Exiting...\n");
                    return 0;
            default:
                    printf("Invalid choice.\n"); }}
    return 0; }