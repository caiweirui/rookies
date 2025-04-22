#include<stdio.h>
#include<math.h>
int main()
{
	float a1,b1,a2,b2,d;
	scanf("(%f,%f) (%f,%f)",&a1,&b1,&a2,&b2);
	d=sqrt((a1-a2)*(a1-a2)+(b1-b2)*(b1-b2));
    printf("%.2f\n",d);
}