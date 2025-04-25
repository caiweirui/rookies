#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,c;
	double pbs,d,x1,x2,x;
	scanf("%d%d%d",&a,&b,&c);
	if(a==0)
	{
		if(b==0)
	    {
		printf("Input error!\n");
	    }
	    else
	    {
		x=(double)-c/b;
	    printf("x=%.6lf\n",x);
	    }
	}
	else
	{
	pbs=b*b-4*a*c;
	    if(pbs>=0)
	    {
		d=sqrt(pbs);
	    x1=(-b+d)/(2*a);
	    x2=(-b-d)/(2*a);
	        if(pbs==0)
		    {
			printf("x1=x2=%.6lf\n",x1);
		    }
			else
		    {
			printf("x1=%.6lf\n",x1);
	     	printf("x2=%.6lf\n",x2);
	        }
	    }
		else
		{
		double e,f;
		e=-(double)b/(2*a);
		f=sqrt(-pbs)/(2*a);
		    if(e!=0)
		    {
		    printf("x1=%.6lf+%.6lfi\n",e,f);
        	printf("x2=%.6lf-%.6lfi\n",e,f);
		    }
		    else
	      	{
        	printf("x1=%.6lfi\n",f);
		    printf("x2=-%.6lfi\n",f);
	        }
		}
	}
	return 0;
}