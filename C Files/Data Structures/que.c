#include <stdio.h>
# define size 5
int q[size];
int front= -1 ;
int rear= -1;
int enq(int val){
    if(rear == size-1)
    printf("queue is full ");
    if(front==-1)front=0;
    rear++;
    q[rear]=val;
    printf(" %d has been enqueued \n",val);
}
void deq(){
    if(front == -1 || front > rear){
    printf("queue is empty");
    front = rear = -1;
    }
    printf("%d has been dequeued\n",&q[front++]);
}
int main(){
    enq(10);
    enq(20);
    enq(30);
    deq();
    
    
    
}