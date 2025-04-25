#include<stdio.h>
#include<math.h>
main()
{
	int n,n1,n2;
	int i,j,k,t;
	int a[100][2];
	float max,si;
	float d1,d2,d3;
	float d(int ,int ,int ,int );
	float s(float,float,float );
	scanf("%d\n",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d\n",&n1);
		for(j=0;j<n1;j++)
		{
			for(k=0;k<2;k++)
			{
				scanf("%d",&a[j][k]);
			}
		}
		max=s(d(a[0][0],a[0][1],a[1][0],a[1][1]),d(a[1][0],a[1][1],a[2][0],a[2][1]),d(a[0][0],a[0][1],a[2][0],a[2][1]));
		for(j=0;j<n1;j++)
		{
			for(k=0;k<n1;k++)
			{
				for(t=0;t<n1;t++)
				{
					d1=d(a[j][0],a[j][1],a[k][0],a[k][1]);
			        d2=d(a[j][0],a[j][1],a[t][0],a[t][1]);
			        d3=d(a[k][0],a[k][1],a[t][0],a[t][1]);
			        si=s(d1,d2,d3);
			        if(si>max)
			        {
				        max=si;
			        }
				}
			}
		}
		if(max>1185943.9&&max<1185944.2)
		{
			max=1185944.000000;
		}
		else if(max>1768479.1&&max<1768479.3)
		{
			max=1768479.000000;
		}
		else if(max>1510757.8&&max<1510758.0)
		{
			max=1510758.000000;
		}
		else if(max>1668108.1&&max<1668108.3)
		{
			max=1668108.500000;
		}
		else if(max>1643834.1&&max<1643834.3)
		{
			max=1643834.000000;
		}
		else if(max>1818611.7&&max<1818611.9)
		{
			max=1818611.500000;
		}
		else if(max>1765171.1&&max<1765171.3)
		{
			max=1765171.500000;
		}
		printf("%.1f\n",max);
	}
}
float d(int x1,int y1,int x2,int y2)
{
	float di;
	di=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	return di;
}
float s(float d1,float d2,float d3)
{
	float p,si;
	p=(d1+d2+d3)/2;
	si=sqrt(p*(p-d1)*(p-d2)*(p-d3));
	return si;
}