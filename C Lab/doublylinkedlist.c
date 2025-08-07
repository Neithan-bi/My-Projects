#include <stdio.h>
#include <stdio.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

Node* head = NULL; 

int creatNode(int value){
    Node* newnode = malloc(sizeof(Node));
    newnode->data = value;
    newnode->next = NULL;
    newnode->prev = NULL;
}

void insertAtBeg(int value) {
    Node* newnode = malloc(sizeof(Node));
    newnode->data = value;
    head->prev = newnode;
    newnode->next = head;
    newnode->prev = NULL;
    head = newnode;
}

void insertAtEnd(int value) {
    Node* newnode = creatNode(value);
    if(!head) {
        head = newnode;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL) temp =  temp->next;
    temp->next = newnode->next;
    newnode->prev = temp;
}

int insertAtSP(int value,int position) {
    Node* newnode = creatNode(value);
    if(position == 1) {
        head = newnode;
        return;
    }
    Node* temp = head;
    for(int i = 1; i < position - 1 && temp->next != NULL ; i++) temp = temp->next;
    if(temp->next != NULL) temp->next->prev = newnode;
    temp->next = newnode;9
    return head;

}

