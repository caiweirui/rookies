#include<stdio.h>
main()
{
	int n,a[100];
	int i,j,k,t,u,len;
	scanf("%d\n",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
    if(n%2==0)
    {
    	for(k=0;k<n/2;k++)
    	{
    		printf("%d ",a[k]*a[n-k-1]);
		}
		printf("\n");
	}
    else
    {
    	for(k=0;k<(n-1)/2;k++)
    	{
    		printf("%d ",a[k]*a[n-k-1]);
		}
		printf("%d \n",a[(n+1)/2-1]);
	}
}
