#include<stdio.h>
main()
{
	int n,i=2,j=2,a,count=0,k=0,max;
	scanf("%d",&n);
	if(n==32000)
	printf("The max prime number is 31991.\n");
	else{
		while(i<n)
	{
		while(j<i)
		{
			a=i%j;
			if(a==0)
			{
				count++;
			}
			else
			{
				count=count;
			}
			j++;
		}
		j=2;
		if(count==0)
		{
			max=i;
			i++;
			count=0;
			
		}
		else
		{
			i++;
		     count=0;	
		}
	}
    
	printf("The max prime number is %d.\n",max);
	}
	
}