#include<stdio.h>
int main()
{
	int a=0,max,min,b=0,num,flag=0;
	char c,d,e,f;
		scanf("%c%c",&c,&d);
		scanf("%c%c",&e,&f);
		a=c-'0';
		b=e-'0';
		if(a>b)
		{
			max=a;
			min=b;
		}
		else
		{
			max=b;
			min=a;
		}
	while(scanf("%c",&c)!=EOF)
	{
		if((c>='0'&&c<='9')||c=='+'||c=='-'||c=='*'||c=='/'||c=='%')
		{
		scanf("%c",&d);
		if(c>='0'&&c<='9')
		{
		a=c-'0';
		if(a>max)
		max=a;
		else if(a<min)
		min=a;
		if(min==0&&c=='/')
		{
			goto p;
		}
		}
		else if(c=='+'||c=='-'||c=='/'||c=='*'||c=='%')
		{
			if(c=='+')
			num=max+min;
			else if(c=='-')
			num=max-min;
			else if(c=='/')
			if(min==0)
			{
				goto p;
			}
			else
			{
				num=max/min;
			}
			
			else if(c=='*')
			num=max*min;
			else if(c=='%')
			num=max%min;
			flag=1;
			printf("%d%c%d=%d\n",max,c,min,num);
	        return 0;
		}
		}
		else
		{
p:			printf("Error!\n");
			return 0;
		}
	}
	
}