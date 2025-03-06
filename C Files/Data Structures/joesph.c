#include<stdio.h>
int Josephus (int N,int k )
{
	int i =1,count=0;
	while(i<=N)
	{
		count=(count+k)%i;
        printf("%d's Count : %d\n",i+1,count);
		i++;  
	}
	return count+1;
}
int main()
{
	int N=7,k=3;
	printf("Final person left : %d\n",Josephus(N,k));
	return 0;
    
}