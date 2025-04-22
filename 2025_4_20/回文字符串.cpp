#include<stdio.h>
#include<string.h>
main()
{
	char a[100];
	gets(a);
    int len,i,flag=0;
	len=strlen(a);
	for(i=0;i<len;i++)
	{
		if(a[i]==a[len-i-1])
		{
			flag=0;
		}
		else
		{
			flag=1;
		}
	}
	if(flag==0)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}

	

