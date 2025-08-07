#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct Node {
 char song[50];
 struct Node* next;
} Node;
Node* top = NULL;
void addSong(char song[]) {
 Node* newNode = (Node*)malloc(sizeof(Node));
 strcpy(newNode->song, song);
 newNode->next = top;
 top = newNode;
 printf("'%s' added to the playlist.\n", song); }


void playNext() {
 if (top == NULL) printf("Playlist is empty! Add some songs first.\n");
 else printf("Playing: '%s'\n", top->song); }
void skipToNext() {
 if (top == NULL) printf("Playlist is empty! Add some songs first.\n");
 else {
 printf("Skipping: '%s'\n", top->song);
 Node* temp = top;
 top = top->next;
 free(temp); } }
 
int main() {
 int choice;
 char song[50];
 do {
 printf("\n---------- Playlist Menu ----------\n");
 printf("1. Add Song\n");
 printf("2. Play Next\n");
 printf("3. Skip to Next\n");
 printf("4. Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 printf("Enter song name: ");
 scanf(" %[^\n]", song);
 addSong(song);
 break;
 case 2:
 playNext();


 break;
 case 3:
 skipToNext();
 break;
 case 4:
 printf("Exiting the playlist.... \n");
 sleep(1);
 printf("Goodbye!");
 break;
 default:
 printf("Invalid choice! Please try again.\n");
 }
 } while (choice != 4);
 return 0; }