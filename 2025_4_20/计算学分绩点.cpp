#include<stdio.h>
int main()
{
	float a,b,r,c;
	scanf("%f %f",&a,&b);
	switch((int)b/10)
	{
		case 10:r=2;break;
		case 9:r=1.5;break;
		case 8:r=1.4;break;
		case 7:r=1.3;break;
		case 6:r=1;break;
		default:r=0;break;
	}
	c=a*r;
	printf("%.2f\n",c);
}