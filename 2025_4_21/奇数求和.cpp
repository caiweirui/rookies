#include<stdio.h>
main()
{
	int n;
	int f(int);
	scanf("%d",&n);
	printf("%d\n",f(n));
}
int f(int n)
{
	if(n==1)
	{
		return 1;
	}
	else
	{
		return f(n-1)+2*n-1;
	}
}