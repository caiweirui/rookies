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
  int n1,y1,r1,n2,y2,r2,day,d=0,i;
  scanf("%d%d%d",&n1,&y1,&r1);
  scanf("%d%d%d",&n2,&y2,&r2);
  for(i=n1;i<n2;i++)
  {
  	d=d+year_days(i);
  }
  day=days(n2,y2,r2)-days(n1,y1,r1)+d;
  if(day==1||day==0)
  {
  	printf("%d day\n",day);
  }
  else
  {
  	printf("%d days\n",day);
  }
  return 0; 
}    