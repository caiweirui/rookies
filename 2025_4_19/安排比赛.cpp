#include<stdio.h>
main()
{
	int n,a[110][1],m;
	int i,j;
	scanf("%d\n",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<1;j++)
		{
			scanf("%d",&a[i][j]);
			m=a[i][j];
				if(m==1)
    m=0;
	else if(m==2)
    m=1;
    else if(m==3)
    m=3;
	else if(m%2==0)
	m=m-1;
	else if(m%2==1)
	m=m;
			printf("%d\n",m);
		}
	}
	return 0;
}
