#include<stdio.h>
main()
{
	int a,b,max,min,maxi,maxj,mini,minj,flag=0;
	int i,j,temp,k;
	int s[100][100],t[100][100];
	scanf("%d%d",&a,&b);
	for(i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
		{
			scanf("%d",&s[i][j]);
		}
	}
	for(i=0;i<a;i++)
	{
	    max=0;
        maxj=0;
		min=100;
		mini=0;
		for(j=0;j<b;j++)
		{
            if(max<s[i][j])
            {
            	max=s[i][j];
            	maxj=j;
			}
		}
		for(k=0;k<a;k++)
		{
			
			if(min>s[k][maxj])
			{
				min=s[k][maxj];
				mini=k;
			}
		}
		if(mini==i)
		{
			printf("Point:a[%d][%d]==%d\n",mini,maxj,s[mini][maxj]);
			flag=1;
		}
	}
	if(flag==0)
	{
		printf("No Point\n");
	}
}