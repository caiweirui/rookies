#include<stdio.h>
main()
{
	int a,b,c;
	int i,j,t;
	scanf("%d%d",&a,&b);
	if(b==1)
	{
		printf("%d\n",a);
	}
	else
	{
		for(i=1;i<b+1;i++)
	{
		printf("%d",(a+i-1)%10);
	}
	printf("\n");
	for(j=1;j<b-1;j++)
	{
		c=(a+2*(b-1)+b-1-j)%10;
		printf("%d",c);
		for(t=j;t<b-2;t++)
		{
			printf(" ");
		}
		printf("%d\n",(a+b+j-1)%10);
	}
	printf("%d\n",(a+2*(b-1))%10);
	}
	
}