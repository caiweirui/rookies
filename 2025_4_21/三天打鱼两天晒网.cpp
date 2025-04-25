#include<stdio.h>
main()
{
	int N,n,y,r,d1,d2,d3,yushu,ns;
	int i;
	int a[]={31,28,31,30,31,30,31,31,30,31,30,31};
	int b[]={31,29,31,30,31,30,31,31,30,31,30,31};
	scanf("%d",&N);
	while(N>0)
	{
		d1=0;
		scanf("%d%d%d",&n,&y,&r);
		if(n==1990)
		{
p:			
			for(i=0;i<y-1;i++)
			{
				d1=d1+a[i];
			}
			d2=d1+r;
			goto u;
    	}
		else if(n==1991)
		{
q:			
			for(i=0;i<y-1;i++)
			{
				d1=d1+a[i];
			}
			d2=d1+r+365;
			goto u;
		}
		else if(n==1992)
		{
w:			
			for(i=0;i<y-1;i++)
			{
				d1=d1+b[i];
			}
			d2=d1+r+730;
			goto u;
		}
		else if(n==1993)
		{
t:	
			for(i=0;i<y-1;i++)
			{
				d1=d1+a[i];
			}
			d2=d1+r+1096;
			goto u;
		}
		else if(n!=1990&&n!=1991&&n!=1992&&n!=1993)
		{
			d1=0;
			d3=(int)(n-1990)/4;
			ns=n-4*d3-1990;
			d1=d1+d3*1461;
			switch(ns)
			{
				case 0:goto p;break;
			    case 1:goto q;break;
			    case 2:goto w;break;
		    	case 3:goto t;break;
			}
		}
u:		yushu=d2%5;
		switch(yushu)
		{
			case 1:case 2:case 3:printf("He was fishing on %d.%d.%d\n",n,y,r);break;
			case 4:case 0:printf("He was basking on %d.%d.%d\n",n,y,r);break;
		}
		N--;
	}
}