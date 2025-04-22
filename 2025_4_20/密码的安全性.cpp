#include<stdio.h>
#include<string.h>
main()
{
	int n,len,a=0,b=0,c=0,d=0;
	char s[100];
	int i,j,k;
	scanf("%d\n",&n);
	for(i=0;i<n;i++)
	{
		gets(s);
		len=strlen(s);
		if(len<6)
		{
			printf("Not Safe\n");
		}
		else
		{
			for(j=0;j<len;j++)
			{
				if(s[j]>=48&&s[j]<=57)
				{
					a=1;
				}
				else if(s[j]>=97&&s[j]<=122)
				{
					b=1;
				}
				else if(s[j]>=65&&s[j]<=90)
				{
					c=1;
				}
				else if(s[j]<48&&s[j]>0||s[j]>57&&s[j]<65||s[j]<97&&s[j]>90||s[j]>122)
				{
					d=1;
				}
			}
			if(a+b+c+d==1)
			{
				printf("Not Safe\n");
			}
			else if(a+b+c+d==2)
			{
				printf("Medium Safe\n");
			}
			else if(a+b+c+d>=3)
			{
				printf("Safe\n");
			}
			a=0;
			b=0;
			c=0;
			d=0;
		}
	}
}