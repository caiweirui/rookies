#include<stdio.h>
#include<string.h>
main()
{
	char a[20];
	int i,j,t,len;
	char b;
	gets(a);
	t=0;
	len=strlen(a);
	j=0;
	while(t<len)
	{
		while(j<len)
	    { 
		if(a[j]>a[j+1])
		{
			a[j]=a[j];
			a[j+1]=a[j+1];
		}
		else
		{
			b=a[j+1];
			a[j+1]=a[j];
			a[j]=b;
		}
		j++;
    	}
	t++;
	j=0;
	}
    printf("%s\n",a);
}