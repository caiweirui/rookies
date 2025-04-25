#include<stdio.h>
#include<stdlib.h>
float sum(int n)
{
	if(n==1)
	{
		return 1;
	}
	else if(n%2==0)
	{
		return (float)(sum(n-1)+(float)1/n);
	}
	else if(n%2==1)
	{
		return (float)(sum(n-1)-(float)1/n);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	if(n==1)
	{
		printf("1\n");
	}
	else
	{
		printf("%f\n",sum(n));
	}
    return 0;
}