#include<stdio.h>
#include<string.h>
main()
{
	char s1[1000],s2[1000],s3[1000],s4[1000];
	int i,j,k,len1,len2,len3,t,u,count=0;
	gets(s1);
	gets(s2);
	gets(s3);
	len1=strlen(s1);
	len2=strlen(s2);
	len3=strlen(s3);
	for(u=0;u<10;u++)
		{
			for(i=0;i<len1+(len3-len2)*count;i++)
		    {
			    if(s1[i]==s2[0])
			    {
			    	for(j=i;j<len2+i;j++)
			    	{
			    		if(s1[j]!=s2[j-i]||s1[j+1]=='\0'&&s2[j-i+1]!='\0')
			    		{
			    			goto p;
						}
					}
					for(t=i+len2;t<1000;t++)
					{
						s4[t-i-len2]=s1[t];
					}
					for(t=i;t<1000;t++)
					{
						s1[t]='\0';
					}
					for(t=i;t<1000;t++)
					{
						s1[t]=s3[t-i];
					}
					for(t=i+len3;t<1000;t++)
					{
						s1[t]=s4[t-i-len3];
					}
					count++;
				}
p:	        i=i;
		    }
		}
	printf("%s\n",s1);
}