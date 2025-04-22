#include<stdio.h>
#include<string.h>
main()
{
	char a[100],b,c[100],d[100];
	gets(a);
	int i,j,k,t,len,x,s1,s2,jieguo;
	float jieguo1,s11,s22;
	len=strlen(a);
	for(i=0;i<len;i++)
	{
		if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/'||a[i]=='%')
		{
			b=a[i];
			x=i;
		}
	
	}
	j=0;
	s1=a[j]-'0';
	for(j=0;j<x-1;j++)
	{
		s1=10*s1+a[j+1]-'0';
	}
	k=x+1;
	s2=a[k]-'0';
	for(k=x+1;k<len-1;k++)
	{
		s2=10*s2+a[k+1]-'0';
	}
	switch(b)
	{
		case '+':jieguo=s1+s2;break;
		case '-':jieguo=s1-s2;break;
		case '*':jieguo=s1*s2;break;
		case '/':s11=s1;s22=s2;
		jieguo1=s11/s22;break;
		case '%':jieguo=s1%s2;break;
	}
	if(b=='/')
	{
		printf("%f\n",jieguo1);
	}
	else
	{
		printf("%d\n",jieguo);
	}
}