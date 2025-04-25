#include<stdio.h>
#include<math.h>
int main()
{
	int n,y,r,x,d,rns,xy,dy;   //2000 年1 月1 日是星期6
	scanf("%d %d %d",&n,&y,&r);
	rns=(int)(n-2000)/4;
	if(y>12||y<1)
	{
		printf("month is error.\n");
		goto p;
	}
	else
	{
		if(((y==1||y==3||y==5||y==7||y==8||y==10||y==12)&&(r>31))||((y==4||y==6||y==9||y==11)&&(r>30)))
		{
			printf("day is error.\n");
			goto p;
		}
		else
		{
		if(y%2==0)
	    {
		xy=y/2;
		if(n%400==0||(n%4==0&&n%100!=0))
		{
			if(y==2&&r>29)
			{
				printf("day is error.\n");
				goto p;
			}
			else
			{
				if(y<=6)
			{
				if(xy==1)
			    {
			    	if(n==2000)
			    	{
			    		d=30+r;
					}
					else
					{
						d=365*(n-2000-rns)+366*rns+31+r;
					}
					
			    }
			    else
			    {
				    d=365*(n-2000-rns)+366*rns+31*xy+29+30*(xy-2)+r;
			    }
			}
			else
			{
				d=365*(n-2000-rns)+366*rns+213+(xy-4)*61+r;
			}
			
			}
		}
		else
		{
			if(y==2&&r>28)
			{
				printf("day is error.\n");
				goto p;
			}
		    else
		    {
		    	if(y<=6)
			{
				if(xy==1)
			    {
				    d=365*(n-2000-rns)+366*(rns)+31+r;
			    }
			else
		    	{
				    d=365*(n-2000-rns)+366*(rns)+31*xy+28+30*(xy-2)+r;
			    }
			}
			else
			{
				d=365*(n-2000-rns)+366*(rns)+212+(xy-4)*61+r;
			}
			}
		}
	}
	else
	{
		dy=(y+1)/2;
		if(n%400==0||(n%4==0&&n%100!=0))
		{
			if(y==2&&r>29)
			{
				printf("day is error.\n");
				goto p;
			}
		    else
			{
				if(y<=7)
			{
				if(dy==1)
			    {
			    	d=365*(n-2000-rns+1)+366*(rns-1)+r;
		    	}
		 	    else
			    {
			    	d=365*(n-2000-rns+1)+366*(rns-1)+31*(dy-1)+29+30*(xy-2)+r;
		     	}
			}
			else
			{
				d=365*(n-2000-rns+1)+366*(rns-1)+213+(dy-4)*31+(dy-5)*30+r;
			}
			}
		}
		else
		{
			if((y==2&&r>29))
			{
				printf("day is error.\n");
				goto p;
			}
		    else
			{
				if(y<=7)
			{
				if(dy==1)
		    	{
				    d=365*(n-2000-rns)+366*(rns)+r;
			    }
			    else
		    	{
			    	d=365*(n-2000-rns)+366*(rns)+31*(dy-1)+28+30*(dy-2)+r;
		    	}
			}
			else
			{
				d=365*(n-2000-rns)+366*(rns)+212+(dy-4)*31+(dy-5)*30+r;
			}
			}
		}
	}
	x=(d+6)%7;
	printf("%d\n",x);
p:	return 0;
    
		}
	}
}