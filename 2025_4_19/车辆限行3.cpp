#include <stdio.h>
int f(int x)
{
	if(x%4==0&&x%100!=0||x%400==0) return 1;
	else return 0;
}
int g(int x)
{
	if(x<1) return g(x+5);
	else if(x>5) return g(x-5);
	else return x;
}
main()
{
	int year,month,date,day=-100,m,n,b;
	int a[2][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,31}};
	scanf("%d %d %d",&year,&month,&date);
	if(year==2012) day++;
	while(--year>2011) day+=f(year)+365;
	while(--month) day+=a[f(year)][month];
	day+=date;m=day/7/13;n=day%7;
	if(n==5||n==6) printf("Free.\n");
	else 
	{
	    b=g(g(3-m)+n);
		if(b!=5) printf("%d and %d.\n",b,b+5); 
		else printf("5 and 0.\n");
	}
}