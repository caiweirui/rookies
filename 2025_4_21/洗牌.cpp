#include<stdio.h>
main()
{
	int n1,n,i,j,count=0,k,u,v=0,count1=0,t;
	int a[100],b[100];
	scanf("%d",&n1);
	n=n1*2;
	for(i=0;i<n1;i++)
	{
		a[2*i]=1;
		a[2*i+1]=2;
	}
	for(k=0;k<n;k++)
	{
		for(j=1;j<=n/2;j++)
	    {
	    	b[j-1]=a[2*j-1];
	    	b[j+n/2-1]=a[2*(j-1)];
	    }
	    for(u=0;u<n1;u++)
		{
		    if(b[2*u]==1)
			{
				count1++;
			}
			if(b[2*u+1]==2)	
			{
				count1++;
			}
		}
		if(count1==n)
		{
            v=k+1;
			goto p;
		}
		else
		{
			count1=0;
		} 
		for(t=0;t<n;t++)
		{
			a[t]=b[t];
	    }
	}
p:  printf("%d\n",v);return 0;
}