#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;
Node* head = NULL;

void insertAtBeg(int value){
    Node* newnode = malloc(sizeof(Node));
    newnode->data = value;
    newnode->next = head;
    head = newnode;
}

void insertAtEnd(int value) {
    Node* newnode = malloc(sizeof(Node));
    newnode->data = value;
    newnode->next = NULL;
    if(!head) {
        head = newnode;
        return; }
    Node* temp = head;
    while(temp->next!=NULL) temp = temp->next;
    temp->next = newnode;
}

void insertAtSP(int value, int position){
    Node* newnode = malloc(sizeof(Node));
    newnode->data = value;
    newnode->next = NULL;
    if(position==1) {
        newnode->next = head;
        head = newnode;
        return;
    }
    Node* temp = head;
    for(int i = 1 ; i < position - 1 && temp!=NULL ; i++) temp = temp->next;
    if(!temp){
        printf("Invalid");
        free(newnode);
        return;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}
void display() {
    Node* temp = head;
    if(!temp) {
        printf("Linked list is empty.");
        return;
    }
    while(temp!=NULL) {
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    insertAtBeg(10);
    insertAtBeg(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtSP(25, 3);
    insertAtBeg(5);
    display();
}