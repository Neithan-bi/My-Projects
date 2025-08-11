#include <stdio.h>

int main() {
    int std;
    int sub;
    printf("Enter the no. of Students : ");
    scanf("%d",&std);
    printf("Enter the no. of Subjects : ");
    scanf("%d",&sub);
    int arr[std][sub];
    for(int i = 0 ; i < std ; i++){
        for(int j = 0 ; j < sub ; j++){
            reverse:
            printf("Enter the marks of student %d in subject %d : ", i + 1, j + 1);
            scanf("%d",&arr[i][j]);
            if(arr[i][j] <0 || arr[i][j] >100) {
        printf("Enter between given range ( 0 - 100 )\n");
            goto reverse;}
            
    }}
    for(int i=0;i<std;i++){
        for(int j=0;j<sub;j++){
            printf("Enter the marks of student %d in subject %d : %d\n ",i+1,j+1,arr[i][j]);
            
    }
}
}