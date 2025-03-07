#include <stdio.h>

void greedy(int coins[],int size,int amount){
    int temp = amount;
    for(int i = 0;i < size;i++){
        while (amount >= 0){
            int no;
            if(temp % coins[i] == 0){
                no = temp / coins[i];
                for(int j = 0;j < no;j++){
                    printf("%d",coins[i]);   
                }
                temp = temp - (no * coins[i]);
            }
        }
    }
}
int main()
{
    int amount;
    int coins[] = {25,10,5,1};
    int n = sizeof(coins) / sizeof(coins[0]);
    printf("\nEnter the Amount: ");
    scanf("%d",&amount);
    greedy(coins,n,amount);
    return 0;
}
