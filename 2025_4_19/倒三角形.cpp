#include<stdio.h>
main()
{
	int n,i,j;
	scanf("%d",&n);
	i=1;
	while(i<=2*n-1)
	{
		printf("*");
		i++;
	}
	printf("\n");
	i=2;
	while(i<=n-1)
	{
		j=i;
		while(j>1)
		{
			printf(" ");
			j--;
		}
		printf("*");
		j=1;
		while(j<=(2*(n-i)-1))
		{
			printf(" ");
			j++;
		}
		printf("*\n");
		i++;
	}
	if(n!=1)
	{
		i=1;
	while(i<n)
	{
		printf(" ");
		i++;
	}
	printf("*\n");
	}
}