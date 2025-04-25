#include<stdio.h>
main()
{
	int sz,fz;
	float jd1,jd2,jd3;
	scanf("%d %d",&sz,&fz);
	if(sz>=12)
	{
		jd1=30*(sz-12)+0.5*fz;
	}
    else
	{
	   jd1=30*sz+0.5*fz;
    }
	jd2=6*fz;
	jd3=jd1-jd2;
	if(jd3<0)
	{
		jd3=-jd3;
	}
	if(fz<10)	
	printf("At %d:0%d the angle is %.1f degrees.\n",sz,fz,jd3);
	else
	printf("At %d:%d the angle is %.1f degrees.\n",sz,fz,jd3);
	return 0;
}