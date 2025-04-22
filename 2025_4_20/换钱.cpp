#include<stdio.h>
main()
{
	int n,price1,price2,t,h1,h2,h3;
	scanf("%d",&n);
	price1=10*n;
	price2=10*0.1+12*0.5+9*1;
	t=1;
	if(price1%80!=0)
	{
		printf("No change.\n");
	}
	else
	{
	while(t*price2<=price1)
	{
		if(price1==t*price2)
		{
			h1=10*t;
			h2=12*t;
			h3=9*t;
			printf("%d,%d,%d\n",h1,h2,h3);
		}
		t++;
	}
	}
}