#include<stdio.h>
main()
{
	int a,b;
	int fun1(int,int),fun2(int,int);
	scanf("%d,%d",&a,&b);
	const char s1[]="最大公约数",s2[]="最小公倍数";
	printf("%s: %d\n",s1,fun1(a,b));
	printf("%s: %d\n",s2,fun2(a,b));
}
int fun1(int a,int b)
{
	int min,i;
	for(i=1;i<=a;i++)
	{
		if(a%i==0&&b%i==0)
		{
			min=i;
		}
	}
	return min;
}
int fun2(int a,int b)
{
	int max,j;
	for(j=a*b;j>=a;j--)
	{
		if(j%a==0&&j%b==0)
		{
			max=j;
		}
	}
    return max;
}
