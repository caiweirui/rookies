#include<stdio.h>
main()
{
	int N,a[100],begin,end,len,max;
	int i,j,k;
	scanf("%d\n",&N);
	for(i=0;i<N;i++)
	{
		scanf("%d",&a[i]);
	}
	begin=0;
	end=N-1;
	len=1;
	max=1;
	for(j=0;j<N;j++)
	{
		if(a[j]==a[j+1])
		{
			len=1;
			for(k=j;k<N;k++)
			{
				len++;
				if(a[k]!=a[k+1])
				{
					goto p;
				}
			}
p:			if(max<len)
            {
            	max=len;
            	begin=j;
            	end=j+len;
			}
		}
	}
	if(max==1)
	{
		printf("No equal number list.\n");
	}
	else
	{
		printf("The longest equal number list is from %d to %d.\n",begin,end-2);
	}
}