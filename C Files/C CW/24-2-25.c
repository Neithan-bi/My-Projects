#include <stdio.h>
int rec(int a){
    if(a==0){
        return 0;
    }
    return (a%10)+rec(a/100);
}   

int main() {
    int n;
    scanf("%d",&n);
    printf("%d",rec(n));
    return 0;
}