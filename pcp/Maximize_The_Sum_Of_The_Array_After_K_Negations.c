#include <stdio.h>
#include<stdlib.h>

int compare(const void *a, const void *b){
     return (*(int *) a - *(int *)b);
}
int cal(int nums[],int size,int k){
    for (int i = 0; i < size && k > 0;i++){
        if(nums[i] < 0){
            nums[i] = -nums[i];
            k--;
        }
    }
    qsort(nums, size, sizeof(int), compare);
    if (k % 2 == 1){
        nums[0] = - nums[0];
    }
    int tot = 0;
    for(int i = 0;i < size;i++){
        tot = tot + nums[i];
    }
    return tot;
}
void main(){
    int size;
    printf("Enter Size of Array: ");
    scanf("%d",&size);
    int nums[size];
    printf("Enter Elements: ");
    for(int i = 0; i < size;i++){
        scanf("%d",&nums[i]);
    }
    int k;
    printf("Enter no of Iteration: ");
    scanf("%d",&k);
    qsort(nums, size, sizeof(int), compare);
    printf("%d",cal(nums,size,k));
}