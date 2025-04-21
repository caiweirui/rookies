#include<stdio.h>
#include<math.h>
int main()
{ 
int n, y, r, x;  
scanf("%d %d %d", &n,&y,&r);  
if(3 >y)  
{y+= 12;  
n--;}  
x=((r+2*y+3*(y+1)/5+n+n/4-n/100+n/400)%7+1)%7; //日期转换星期计算公式  
    if(n==2012&&((y>=4&&y<=6)||(y==7&&r<=7)))
    {
    	switch(x)
    	{
    		case 1:printf("3 and 8.\n");break;
    		case 2:printf("4 and 9.\n");break;
    		case 3:printf("5 and 0.\n");break;
    		case 4:printf("1 and 6.\n");break;
    		case 5:printf("2 and 7.\n");break;
    		default :printf("Free.\n");break;
		}
	}
	else if(n==2012&&((y>=8&&y<=9)||(y==7&&r>=8)||(y==10&&r<=6)))
    {
    	switch(x)
    	{
    		case 2:printf("3 and 8.\n");break;
    		case 3:printf("4 and 9.\n");break;
    		case 4:printf("5 and 0.\n");break;
    		case 5:printf("1 and 6.\n");break;
    		case 1:printf("2 and 7.\n");break;
    		default :printf("Free.\n");break;
		}
	}
	else if((n==2012&&((y>=11)||(y==10&&r>=7)))||(n==2013&&y==1&&r<=5))
    {
    	switch(x)
    	{
    		case 3:printf("3 and 8.\n");break;
    		case 4:printf("4 and 9.\n");break;
    		case 5:printf("5 and 0.\n");break;
    		case 1:printf("1 and 6.\n");break;
    		case 2:printf("2 and 7.\n");break;
    		default :printf("Free.\n");break;
		}
	}
	else if(n==2013&&(y>=2&&y<=3)||(y==2&&r>=6)||(y==4&&r<=10))
    {
    	switch(x)
    	{
    		case 4:printf("3 and 8.\n");break;
    		case 5:printf("4 and 9.\n");break;
    		case 1:printf("5 and 0.\n");break;
    		case 2:printf("1 and 6.\n");break;
    		case 3:printf("2 and 7.\n");break;
    		default :printf("Free.\n");break;
		}
	}
}
