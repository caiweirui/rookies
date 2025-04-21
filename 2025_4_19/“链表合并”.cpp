#include<stdio.h>
#include<string.h>
main()
{
	char a[100],b[100],c[100];
	int i,j,k,l1,l2,flag=1;
	gets(a);
	gets(b);
	l1=strlen(a);
	l2=strlen(b);
	for(i=0;i<l1;i++)
	{
		if(a[i]==' ')
		{
			for(j=i;j<l1;j++)
			{
				a[j]=a[j+1];
			}
			l1--;
		}
	}
	for(i=0;i<l2;i++)
	{
		if(b[i]==' ')
		{
			for(j=i;j<l2;j++)
			{
				b[j]=b[j+1];
			}
			l2--;
		}
	}
	printf("%c",a[0]);
	for(i=1;i<l1;i++)
	{
		printf(" %c",a[i]);
	}
	for(j=0;j<l2;j++)
	{
		for(k=0;k<l1;k++)
		{
			if(b[j]==a[k])
			{
				flag=0;
			}
		}
		if(flag==1)
		{
			printf(" %c",b[j]);
		}
		flag=1;
	}
	printf("\n");
}
	