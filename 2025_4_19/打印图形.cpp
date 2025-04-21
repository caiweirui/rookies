#include<stdio.h>
main()
{
	char x,s[1000],y;
	int N,i,j,k,t;
	scanf("%d %c",&N,&x);
	for(i=0;i<1000;i++)
	{
		s[i]=x+i;
		while(s[i]>'Z')
		{
			s[i]=s[i]-26;
		}
	}
	for(i=0;i<N-1;i++)
	{
		printf(" ");
	}
	printf("%c\n",s[0]);
	for(j=1;j<N;j++)
	{
		for(k=j;k<N-1;k++)
		{
			printf(" ");
		}
		for(k=N;k>=N-j;k--)
		{
			printf("%c",s[N-k+1+j-1]);
		}
		for(t=0;t<j;t++)
		{
			printf("%c",s[N-k+1+j-1-t-2]);
		}
		printf("\n");
	}
}
