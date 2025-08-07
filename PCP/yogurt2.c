#include <stdio.h>
int main() {
    int x;
    printf("Enter a value for ur multiple checker : ");
    scanf("%d",&x);
    int a,b;
    printf("Enter 2 numbers : ");
    scanf("%d %d",&a,&b);
    if(x/a==0 && x/b==0){
        printf("%d is a multiple of %d and %d",x,a,b);
    }
    else{
        printf("%d is not a multiple of %d and %d",x,a,b);
    }
}