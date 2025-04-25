#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int f(int a,int b,int c,int d,int n);
int main()
{
	int i,a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	for(i=0;i<1000;i++)
	{
		if(f(a,b,c,d,i)==0)
		break;
	}
	printf("The max is %d",i-1);
}
int f(int a,int b,int c,int d,int n)
{
	int i,j,k,t,flag=0;
	for(i=0;i<=5;i++)
	{
		for(j=0;j<=5;j++)
		{
			for(k=0;k<=5;k++)
			{
				for(t=0;t<=5-i-j-k;t++)
				{
					if(a*t+b*k+c*j+d*i==n)
					return 1;
				}
			}
		}
	}
	return 0;
}
