#include<stdio.h>
main()
{
	char x,y;
	int n;
	char a[10000];
	int i,j,k,t,u,v,flag=0,p,q;
	scanf("%c,%d",&x,&n);
	for(p=0;p<10000;p++)
	{
		a[p]=x+p;
		while(a[p]>'Z')
		{
			a[p]=a[p]-26;
		}
	}
	if(n==1)
	{
		printf("%c\n",a[0]);
	}
	else
	{
		i=1;
		while(i<n)
		{
			printf(" ");
			i++;
		}
		printf("%c\n",a[0]);
		u=2;
		j=2;
		t=1;
		k=1;
		while(u<=n)
		{
		while(j<n)
		{
			printf(" ");
			j++;
		}
		printf("%c",a[u-1]);
		while(t<2*k)
		{
			printf(" ");
			t++;
		}
		printf("%c\n",a[u-1]);
		u++;
		k++;
		j=1+k;
		t=1;
		}
		u=n;
		j=n-1;
		t=1;
		k=n-2;
		v=1;
		i=1;
		q=1;
		while(j>1)
		{
			while(u>n-1)
			{
				printf(" ");
				u--;
			}
			k++;
			printf("%c",(a[0]+n-'A'-q-1)%26+'A');
			v++;
			while(t<=2*(n-2)-i)
			{
				printf(" ");
				t++;
			}
			t=i+1;
			i++;
			u=n-1+i;
			v=i-1;
			printf("%c\n",(a[0]+n-'A'-q-1)%26+'A');
			j--;
			v++;
			q++;
		}
		i=1;
		while(i<n)
		{
			printf(" ");
			i++;
		}
			printf("%c\n",x);
	}
}