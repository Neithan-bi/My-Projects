#include<stdio.h>
#define num 3

int stack[num];
int top =-1;
void push(int a){
    if(top>=(num-1)){
        printf("the stack is full\n");
        return;
    }
    top++;
    stack[top]=a;
    printf("pushed %d successfully\n",a);
}
void pop(){
    if(top==-1){
        printf("the stack is empty");
        return;
    }
    printf("popped %d successfully\n",stack[top]);
    top--;
    
}
void peek(){
    printf("the top value is %d\n");
    
}
void display(){
     if(top==-1){
        printf("the stack is empty");
        return;
    }
    for(int i=0;i<=top;i++){
        printf("%d\n",stack[i]);
    }
    
}
int main(){
    push(5);
    push(10);
    push(15);
    push(20);
    pop();
}