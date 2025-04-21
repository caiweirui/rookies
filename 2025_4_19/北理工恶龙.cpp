#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{
	int i,j,k,t=0,m,n,tmp,sum=0;
	int a[105]={0},b[105]={0},c[105]={0};
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(i=0;i<m;i++)
	scanf("%d",&b[i]);
	if(n>m)
	{
		printf("bit is doomed!");
		return 0;
	}
	else
	{
		for(i=0;i<n-1;i++)
		{
			for(j=0;j<n-1-i;j++)
			{
				if(a[j]<a[j+1])
				{
					tmp=a[j];
					a[j]=a[j+1];
					a[j+1]=tmp;
				}
			}
		}//冒泡 
		for(i=0;i<m-1;i++)
		{
			for(j=0;j<m-1-i;j++)
			{
				if(b[j]<b[j+1])
				{
					tmp=b[j];
					b[j]=b[j+1];
					b[j+1]=tmp;
				}
			}
		}//冒泡 
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<=m;j++)
		{
			int flag=0;
			if(b[j]>=a[i])
			continue;
			else
			{
				if(j==0)
				{
					printf("bit is doomed!");
		            return 0;
				}
				else
				{
					for(k=j-1;k>=0;k--)
					{
						if(c[k]==0)
						{
						c[k]=1;
						flag=1;
						break;
						}
					}
					if(flag==1)
					break;
					if(k==-1)
					{
						printf("bit is doomed!");
		                return 0;
					}
				}
			}
		}
	}
	for(i=0;i<m;i++)
	{
		if(c[i]==1)
		sum+=b[i];
	}
	printf("%d\n",sum);
	return 0; 
}
