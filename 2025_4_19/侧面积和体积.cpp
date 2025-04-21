#include<stdio.h>
#include<math.h>
#define P 3.1415926
int main()
{
	double r,h,s,v;
	scanf("%lf%lf",&r,&h);
	s=2*P*r*h;
	v=P*r*r*h;
	printf("s=%.2f,v=%.2f\n",s,v);
	return 0;
}