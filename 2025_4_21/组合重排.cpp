#include<stdio.h>
#include<string.h>
int main()
{
	char a[105]={},b[105]={},c[210]={};
	int i,j=0,k=0,l1,l2;
	gets(a);
	gets(b);
	l1=strlen(a);
	l2=strlen(b);
	if(l1==0)
	{
		printf("%s\n",b);
	}
	else if(l2==0)
	{
		printf("%s\n",a);
	}
	else if(l1!=0&&l2!=0)
	{
			for(i=0;i<l1+l2;i++)
	{
		if(a[j]>b[k])
		{
			c[i]=b[k];
			k++;
		}
		else
		{
			c[i]=a[j];
			j++;
		}
		if(j==l1)
		{
			while(k!=l2)
			{
				i++;
				c[i]=b[k];
				k++;
			}
		}
		else if(k==l2)
		{
			while(j!=l1)
			{
				i++;
				c[i]=a[j];
				j++;
			}
		}
	}
	printf("%s\n",c);
	}

	return 0;
}