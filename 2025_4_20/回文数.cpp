#include<stdio.h>
main()
{
	int n;
	int i,j;
	int a,b,c,d,e;
	scanf("%d",&n);
	for(i=1;i<n;i++)
	{
		j=i*i;
		a=j%10;
		b=((j-a)/10)%10;
		c=((j-a-10*b)/100)%10;
		d=((j-a-10*b-100*c)/1000)%10;
		e=((j-a-10*b-100*c-1000*d)/10000)%10;
		if(e!=0)
		{
			if(a==e&&b==d)
			{
				printf("%d\n",i);
			}
		}
		else
		{
			if(d!=0)
			{
				if(a==d&&b==c)
				{
					printf("%d\n",i);
				}
			}
			else
			{
				if(c!=0)
				{
					if(a==c)
					{
						printf("%d\n",i);
					}
				}
				else
				{
					if(b!=0)
					{
						if(a==b)
						{
							printf("%d\n",i);
						}
					}
					else
					{
						printf("%d\n",i);
					}
				}
			}
		}
	}
}