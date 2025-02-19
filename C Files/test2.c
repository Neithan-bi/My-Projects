#include <stdio.h>

void main() {
    int i,j,k;
    scanf("%d",&k);
    while(k>0){
        i=1;
        while(i<k){
            j=i;
            while(j<i+2){
                printf("%d",j);
                j++;
            }
        i++;
        printf("\n");
        }
        k--;
    }
}