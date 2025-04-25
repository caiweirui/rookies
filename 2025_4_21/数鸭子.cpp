#include<stdio.h>
main()
{
	int a[8],i;
	int sum=2,sum1;
	for(i=0;i<7;i++)
	{
		sum1=(sum+1)*2;
		a[i]=sum1-sum;
		sum=sum1;
	}
	printf("sum=%d\n",sum);
	for(i=0;i<7;i++)
	{
		printf("sell=%d",a[6-i]);
		if(i<6)
		{
			printf(",");
		}
		else
		{
			printf("\n");
		}
	}
}