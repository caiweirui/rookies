#include<stdio.h>
#include<ctype.h>
int main()
{
	char a,b;
	scanf("%c",&a);
	if(isalpha(a))
	{
		if(islower(a))
		{
			b=a-32;
		}
		else
		{
			b=a+32;
		}
	}
	else
	{
	    b=a;	
	}
	printf("%c\n",b);
	return 0;	
}