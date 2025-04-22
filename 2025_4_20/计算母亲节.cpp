#include<stdio.h>
int main()
{
	int year,day,rns,r,i;
	scanf("%d",&year);//2000nian 5.1 shi 1
	rns=(int)(year-2000)/4;
	day=(year-2000)*365+rns;
	r=day%7;
	i=1;
	while((i+r)%14!=0)
	{
		i++;
	}
	printf("%d\n",i);
}