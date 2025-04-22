#include<stdio.h>
int GCD(int n,int m)
{
	int yu=1,i;
	if(m<=n&&n%m==0||m>=n&&m%n==0)
	{
		if(m<=n)
		{
			return m;
		}
		else
		{
			return n;
		}
	}
	else
	{
		if(n>m)
		{
			while (yu>0)
			{
				yu=n%m;
				n=m;
				m=yu;
			}
			return n;
		}
		else
		{
			while(yu>0)
			{
				yu=m%n;
				m=n;
				n=yu;
			}
			return m;
		}
	}
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	printf("%d\n",GCD(n,m));
}