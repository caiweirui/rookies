#include<stdio.h>
main()
{
	int a,b,c,d,e,f,g;
	scanf("%d%d",&a,&b);
	c=a+b;
	d=a-b;
	e=a*b;
	f=a/b;
	g=a%b;
	printf("%d+%d=%d\n",a,b,c);
	printf("%d-%d=%d\n",a,b,d);	
	printf("%d*%d=%d\n",a,b,e);	
	printf("%d/%d=%d\n",a,b,f);
	printf("%d",a);
	printf("%%");
	printf("%d=%d\n",b,g);
	return 0;
}