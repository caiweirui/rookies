#include<stdio.h>
main()
{
int a,b,c,n,i;
scanf("%d%d",&a,&n);
if(a==0)
{
printf("The last 3 numbers is 000.\n");
}
else
{
b=1;
i=1;
while(i<=n)
{
b=(b*a)%1000;
i++;
}
c=b%1000;
if(c==0)
{
	printf("The last 3 numbers is 000.\n");
}
else
{
	printf("The last 3 numbers is %d.\n",b);
}

}
}