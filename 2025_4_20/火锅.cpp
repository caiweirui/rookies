#include<stdio.h>
main()
{
	int n1,n;
	int a[100000],b[100000];
	int i=0,j,count,t,p,q,temp,m,k;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&n1);
		for(j=0;j<n1;j++)
		{
			scanf("%d",&a[j]);
		}
		for(k=0;k<n1;k++)
		{
			for(t=k;t<n1;t++)
		    {
			    count=count+a[t];
			    b[t+k*n1]=count;
		    }
		    count=0;
		}
		
		for(p=0;p<10000;p++)
		{
			for(q=0;q<10000;q++)
			{
				if(b[q]<b[q+1])
				{
					temp=b[q];
					b[q]=b[q+1];
					b[q+1]=temp;
				}
			}
		}
		printf("%d\n",b[0]);
		count=0;
		for(m=0;m<100000;m++)
		{
			b[m]=0;
		}
	}
}