#include <stdio.h>

int main() {
    int i,j,k=5;
    while(k!=0){
        for(i=1;i<k;i++){
            for(j=i;j<i+2;j++){
                printf("%d",j);
            }
            printf("\n");
        }
        k--;
    }

}
    