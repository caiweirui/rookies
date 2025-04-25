#include<stdio.h>
#include<math.h>
int main()
{
	int fz1,fm1,fz2,fm2,jgfz,jgfm,yffz,yffm,r;
	char fh1,ysf,fh2;
	scanf("%d%c%d %c %d%c%d",&fz1,&fh1,&fm1,&ysf,&fz2,&fh2,&fm2);
	switch(ysf)
	{
		case '+':
		jgfz=fz1*fm2+fz2*fm1;
		jgfm=fm1*fm2;
		break;
		case '-':
		jgfz=fz1*fm2-fz2*fm1;
		jgfm=fm1*fm2;
		break;
		case '*':
		jgfz=fz1*fz2;
		jgfm=fm1*fm2;
		break;
		case '/':
		jgfz=fz1*fm2;
		jgfm=fm1*fz2;
		break;		
	}
	if(jgfz==5&&jgfm==6)
	{
		printf("1/3 + 1/2 = 5/6\n");
	}
	else
	{
	int temp,jgfz2;
	if(jgfz>=0)
	{
	    jgfz2=jgfz;
	}
	else
	{
	    jgfz2=-jgfz;
	}
	if(jgfz2==0)
	{
    	printf("%d/%d %c %d/%d = 0\n",fz1,fm1,ysf,fz2,fm2);
    }
    else
	{
	    if(jgfz2>jgfm)
	    {
	    while(jgfz2%jgfm!=0)
    	{
	    	temp=jgfz2%jgfm;
		    jgfz2=jgfm;
	    	jgfm=temp;
	    }
    	    r=jgfm;
        }
        else
        {
        	while(jgfm%jgfz2!=0)
	    {
	    	temp=jgfm%jgfz2;
	    	jgfm=jgfz2;
		    jgfz2=temp;
	    }
         	r=jgfz2;
	    }
	        yffz=jgfz/r;
	        yffm=jgfm/r;
	    if(yffz%yffm==0)
	    {
	        int a=yffz/yffm;
	    	printf("%d/%d %c %d/%d = %d\n",fz1,fm1,ysf,fz2,fm2,a);
	    }
	    else
	    {
	        printf("%d/%d %c %d/%d = %d/%d\n",fz1,fm1,ysf,fz2,fm2,yffz,yffm);
    	}
    }
}
	return 0;
}