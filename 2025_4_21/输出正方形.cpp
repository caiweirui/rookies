#include<stdio.h>
main()
{
	int n,i,j,a;
	scanf("%d",&n);
	i=1;
	j=1;
	while(i<=n)
	{
		while(j<=n)
		{
			a=(i-1)*n+j;
			j++;
			printf(" %2d",a);
		}
		printf("\n");
		i++;
		j=1;
	}
}