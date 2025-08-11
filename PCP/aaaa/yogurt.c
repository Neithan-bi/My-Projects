#include <stdio.h>
int main() {
    int x,y;
    scanf("%d %d",&x,&y);
    if(y/x==0){
        printf("Y divides X completely");
    }
    else{
        printf("Y does not divide X completely");
    }
}