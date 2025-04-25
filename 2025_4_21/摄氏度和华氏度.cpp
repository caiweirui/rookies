#include<stdio.h>
main()
{
	int a;
	float b,c;
	while(scanf("%d",&a)!=EOF)
	{
		scanf("%f",&b);
		if(a==1)
		    {
			    c=(b-32)/1.8;
			    printf("The Centigrade is %.2f\n",c);
		    }
		else if(a==2)
		    {
			    c=b*1.8+32;
			    printf("The Fahrenheit is %.2f\n",c);
	        }
	    else if(a!=0&&a!=2)
	    {
	    	printf("Wrong input!\n");
		}
	}
			
}