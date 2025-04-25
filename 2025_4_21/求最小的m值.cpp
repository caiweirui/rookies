#include<stdio.h>
int main()
{
	int n,s,i;
	scanf("%d",&n);
	s=1;
	i=1;
	while(s<n)
	{
		i++;
		s=s+i;
	}
	printf("%d\n",i);
}