#include<stdio.h>
main()
{
	int n,i,j,t,k,v,m;
	int a[50];
	scanf("%d",&n);
	for(t=0;t<n;t++)
	{
		a[t]=t+1;//a[0]=1;a[1]=2;a[2]=3;...
	}
	i=1;
	j=1;
	while(j<=2*(n-1))
	{
		printf(" ");
		j++;
	}
	printf("%2d\n",a[0]);
	i=2;
	while(i<=n)
	{
		j=i;
		while(j<(2*n-i))
		{
			printf(" ");
			j++;
		}
		k=n-1;
		while(k>=n-i)
		{
			printf("%2d",a[n-k-1]);
			k--;
		}

			v=a[k+1];
			while(v<n)
			{
				printf("%2d",n-v);
				v++;
			}
		printf("\n");
		i++;
	}
}