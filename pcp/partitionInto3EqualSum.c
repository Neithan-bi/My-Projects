#include <stdio.h>
#include <stdbool.h>

bool canThreePartsEqualSum(int* arr, int arrSize) {
    int sum = 0;
    for(int i = 0; i < arrSize; i++){
        sum += arr[i];
    }
    if(sum % 3 != 0) {
        return false;
    }
    
    int partSum = sum / 3;
    int curSum = 0;
    int cnt = 0;

    for(int i = 0; i < arrSize; i++) {
        curSum += arr[i];
        if(curSum == partSum) {
            curSum = 0;
            cnt += 1;
        }
    }
    return (cnt >= 3);
}

int main() {
    int arr[200];
    int arrSize;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &arrSize);

    printf("Enter the elements of the array: ");
    for(int i = 0; i < arrSize; i++) {
        scanf("%d", &arr[i]);
    }

    if (canThreePartsEqualSum(arr, arrSize)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
