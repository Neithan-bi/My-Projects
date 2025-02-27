#include <stdio.h>
#include <stdlib.h>

struct node* Beg(struct node* head, int data) {
    if(head == NULL){
        return NULL;
    }
    struct node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct node* posi(struct node* head, int data, int pos){
    if(head == NULL){
        return NULL;
    }
    if(head->next == NULL){
        free(head);
        return NULL;
    }
    struct node* temp = head;
    struct node* prev = NULL;
    for(int i = 0; temp->next!=NULL && i< pos;i++){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        return NULL;
    }
    prev->next = temp->next;
    free(temp);
    return head;

}
struct node* end(struct node* head,int data){
    if(head == NULL){
        return NULL;
    }
    if(head->next == NULL){
        free(head);
        return NULL;
    }
    struct node* temp = head;
    struct node* prev = NULL;
    for(int i = 0; temp->next!=NULL && i< pos;i++){
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
    return head;
}

