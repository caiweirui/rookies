#include<stdio.h>
int f(int n,int m)
{
	int sum=0,i;
	if(m==n)
	{
		return sum+n;
	}
	else
	{
		return f(n,m-1)+m;
	}
}
main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	printf("The sum from %d to %d is %d.\n",n,m,f(n,m));
}