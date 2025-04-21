#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
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
int main()   
{  
   int n;  
   scanf("%d",&n);  
   printf("%d\n",count(n,n-1));  //count(4,3)=4  
   return 0;  
}  
             
   