#include<stdio.h>
int Josephus (int N,int k )
{
	int i =1,count=0;
	while(i<=N)
	{
		count=(count+k)%i;
        printf("%d",count);
		i++;  
	}
	return count+1;
}
int main()
{
	int N=7,k=3;
	printf("%d",Josephus(N,k));
	return 0;
    
}