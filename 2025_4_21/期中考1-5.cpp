#include<stdio.h>
#include<string.h>
#include<math.h>
main()
{
	char a[100],b[100];
	int i,j,x,len,c,k,count=0,flag=0;
    gets(a);
    for(i=0;i<100;i++)
    {
    	b[i]=a[i];
	}
	len=strlen(a);
	for(i=0;i<len;i++)
	{
		for(j=0;j<len;j++)
		{
			if(a[i]==b[j])
			{
				count++;
				k=j;
			}
		}	
		if(count>1)
		{
			b[k]=count+'0';
		}
		count=0;
		j=0;
	}
	printf("%s\n",b);
}

