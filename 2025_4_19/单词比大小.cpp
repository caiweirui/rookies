#include<stdio.h>
#include<string.h>
main()
{
	char s[5][100];
	char temp[100];
	int i,j;
	for(i=0;i<=4;i++)
	scanf("%s",s[i]);
	for(i=0;i<5;i++)
	{
		for(j=0;j<5-i;j++)
	    {
	    	if(strcmp(s[i],s[i+j])<0)
	    	{
	        strcpy(temp,s[i]);
	        strcpy(s[i],s[i+j]);
	        strcpy(s[i+j],temp);
	        }
		}
    }
    for(i=0;i<=4;i++)
	printf("%s\n",s[i]);
}