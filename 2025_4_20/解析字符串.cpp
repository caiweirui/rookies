#include<stdio.h>
#include<string.h>
main()
{
	char a[100],b[100],c[100];
	int i,j,k,l;
	gets(a);
	l=strlen(a);
	for(i=0;i<l;i++)
	{
		if(a[i]=='n'&&a[i+1]!='\0')
		{
			printf("\n");
		}
		else
		{
			printf("%c",a[i]);
		}
    }
}