#include<stdio.h>
main()
{
	int n,i,a;
	scanf("%d",&n);
	i=n;
    a=1;
    if(n==1)
    {
    	printf("The monkey got %d peach in first day.\n",a);
	}
	else
	{
			while(i>1)
    {
    	a=(a+i-1)*2;
    	i--;
	}
	printf("The monkey got %d peaches in first day.\n",a);
	}

}