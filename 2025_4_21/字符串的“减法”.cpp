#include<stdio.h>
#include<string.h>
main()
{
	char a[80],b[80];
	int i,j,k,count=0,l;
	int lena,lenb;
	gets(a);
	gets(b);
	lena=strlen(a);
	lenb=strlen(b);
	for(i=0;i<lena;i++)
	{
		for(j=0;j<lenb;j++)
		{
			if(a[i]==b[j])
			{
				for(k=i;k<lena;k++)
				{
					a[k]=a[k+1];	
				}
				count++;
				i--;
			}
		}
	}
	if(count==lena)
	{
		printf("\n");
	}
	else
	{
	printf("%s\n",a);
		
	}
	
}