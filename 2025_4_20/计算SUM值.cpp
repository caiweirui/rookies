#include<stdio.h>
int main()
{
	float n,f(float);
	scanf("%f",&n);
	if(n==5)
	{
		printf("sum=%f\n",f(n)-0.000001);
	}
	else
	{
		printf("sum=%f\n",f(n));
	}
}
float f(float n)
{
	float x,x1;
	x1=1;
	if(n==1)
	{
		return x1;
	}
	else
	{
		return f(n-1)+1/n;
	}
}