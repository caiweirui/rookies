#include <stdio.h>     
#include <stdlib.h>
int leap_year(int year)   // 判断闰年或平年  
{   
    return ((year%4==0&&year%100!=0)||year%400==0) ? 1:0;  
}  
int year_days(int year)     // 计算一整年的天数  
{   
    return leap_year( year ) ? 366 : 365;  
}  
int days(int year,int month,int day) // 计算该天month,day 是本年year的第几天  
{   
    int months[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31}, i;  
    if(leap_year(year) && month >2)  
    {
		day++; 
    }
    for(i=1;i<month;i++)
	{
		day+=months[i];  
	}  
    return day;  
}  
int main() 
{ 
  int n1,y1,r1,n2,y2,r2,day,d=0,i,j,x;
  n1=2012;
  y1=4;
  r1=9;
  scanf("%d %d %d",&n2,&y2,&r2);
  for(i=n1;i<n2;i++)
  {
  	d=d+year_days(i);
  }
  day=days(n2,y2,r2)-days(n1,y1,r1)+d;
  int a[28];
  for(j=0;j<5;j++)
  {
  	a[j]=j+1;
  }
  a[5]=0;
  a[6]=0;
  for(j=0;j<5;j++)
  {
  	a[j+7]=j+11;
  }
  a[12]=0;
  a[13]=0;
   for(j=0;j<5;j++)
  {
  	a[j+14]=j+21;
  }
  a[19]=0;
  a[20]=0;
     for(j=0;j<5;j++)
  {
  	a[j+21]=j+31;
  }
  a[26]=0;
  a[27]=0;
  if(day%365>=0&&day%366<=89)
  {
  	x=day%367%7;
  	switch(a[x])
  	{
  		case 1:printf("3 and 8.\n");break;
    	case 2:printf("4 and 9.\n");break;
    	case 3:printf("5 and 0.\n");break;
    	case 4:printf("1 and 6.\n");break;
    	case 5:printf("2 and 7.\n");break;
    	default :printf("Free.\n");break;
    }
  }
  else if(day%365>=90&&day%365<=180)
  {
  	x=(day%367-90)%7+7;
  	switch(a[x]-1)
  	{
  		case 12:printf("3 and 8.\n");break;
    	case 13:printf("4 and 9.\n");break;
    	case 14:printf("5 and 0.\n");break;
    	case 15:printf("1 and 6.\n");break;
    	case 11:printf("2 and 7.\n");break;
    	default :printf("Free.\n");break;
    }
  }
  else if(day%365>=181&&day%365<=271)
  {
  	x=(day%367-181)%7+14;
  	switch(a[x])
{case 23:printf("3 and 8.\n");break;
    		case 24:printf("4 and 9.\n");break;
    		case 25:printf("5 and 0.\n");break;
    		case 21:printf("1 and 6.\n");break;
    		case 22:printf("2 and 7.\n");break;
    		default :printf("Free.\n");break;
	  }  	
  }
  else if(day%365>=272&&day%365<=366)
  {
  	x=(day%367-272)%7+21;
  	switch(a[x])
  	{
  		case 34:printf("3 and 8.\n");break;
    		case 35:printf("4 and 9.\n");break;
    		case 31:printf("5 and 0.\n");break;
    		case 32:printf("1 and 6.\n");break;
    		case 33:printf("2 and 7.\n");break;
    		default :printf("Free.\n");break;
	  }
	  
  }
}    