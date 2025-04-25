#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int main()   
{  
   int n,count(int,int);  
   int m;
   scanf("%d %d",&n,&m);  
   printf("%d\n",count(n,m));  //count(4,3)=4  
   return 0;  
}  
int count(int n,int m)
{
	if(n<1||m<1)
	return 0;//返回值
	else if(n==1||m==1) 
	return 1;
	else if(n<m)
	return count(n,n);
	else if(n==m)
	return count(n,m-1)+1;
	else
	return count(n-m,m)+count(n,m-1);
}              
   

	