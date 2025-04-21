#include<stdio.h>
#include<math.h>
int main()
{
	int n,csz,a,b,c,d,e,f,x;
	scanf("%d",&n);
	if(n==2)
	{
		printf("No output.\n");
	}
	else
	{
		csz=pow (10,n-1);
p:		a=csz%10;
        b=(csz-a)/10%10;
	    c=(csz-10*b-a)/100%10;
	    d=(csz-100*c-10*b-a)/1000%10;
	    e=(csz-1000*d-100*c-10*b-a)/10000%10;
	    f=(csz-10000*e-1000*d-100*c-10*b-a)/100000%10;
	    a=pow(a,n);
	    b=pow(b,n);
	    c=pow(c,n);
	    d=pow(d,n);
	    e=pow(e,n);
	    f=pow(f,n);
	    x=a+b+c+d+e+f;
	    if(csz>=pow (10,n))
	    {
	    	goto q;
		}
		else
		{
			if(x==csz)	
	        {
		    printf("%d\n",x);
		    csz++;
		    goto p;
	        }
	     	else
	    	{
		    csz++;
		    goto p;
	      	}	
		}	
	}
q:  return 0;
}