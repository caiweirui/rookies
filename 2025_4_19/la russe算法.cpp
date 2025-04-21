#include<stdio.h>
int larusse(int p1,int p2)
{
	int count=0;
	while(p1>=1)
	{
		if(p1%2==1)
		{
			count=count+p2;
		}
		p1=p1/2;
		p2=p2*2;
	}
	return count;
}
main()
{
	int p1,p2;
	scanf("%d*%d",&p1,&p2);
	printf("%d\n",larusse(p1,p2));//输出两个数的乘积
}