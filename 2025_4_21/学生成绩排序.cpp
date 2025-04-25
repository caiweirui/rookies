#include<stdio.h>
#include<string.h>
main()
{
	char s[100][100],temp[100];
	int a[100];
	int n,i,j,k,t,u,m,temp1;
	scanf("%d\n",&n);
	for(i=0;i<n;i++)
	{

			scanf("%s",&s[i]);

	}
	for(i=0;i<n;i++)
	{
		for(k=0;k<100;k++)
		{
			if(s[i][k]==',')
			{
				if(s[i][k+1]=='1'&&s[i][k+1]=='0'&&s[i][k+2]=='0')
				{
					a[i]=100;
				}
				else
				{
					a[i]=10*(s[i][k+1]-'0')+(s[i][k+2]-'0');
				}
			}
		}
	}
	for(t=0;t<n;t++)
	{
		for(m=0;m<n;m++)
		{
			if(a[m]<a[m+1])
			{
				temp1=a[m];
				a[m]=a[m+1];
				a[m+1]=temp1;
				strcpy(temp,s[m]);
				strcpy(s[m],s[m+1]);
				strcpy(s[m+1],temp);
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%s\n",s[i]);
	}
}