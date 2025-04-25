#include<stdio.h>
#include<string.h>
main()
{
	char a[100],b[100],c[100];
	int n,i,j,count=0,d,len1,len2;
    scanf("%d\n",&n);
	gets(a);
    for(i=0;i<100;i++)
    {
    	if(a[i]==EOF)
		{
			d=i;
			goto p;
		}
	}
p:	for(i=0;i<d;i++)
{
	c[i]=a[i];
}
	len1=strlen(c);
	len2=strlen(b);
	for(i=0;i<len2;i++)
	{
		b[i]=b[i];
	}
	for(i=0;i<len1;i++)
	{
		if(c[i]==b[0]&&c[i+1]==b[1]&&c[i+2]==b[2]&&c[i+3]==b[3]&&c[i+4]==b[4]&&c[i+5]==b[5])
		{
			count++;
		}
	}
	printf("%d\n",count);
}
