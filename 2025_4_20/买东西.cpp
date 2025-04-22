#include <stdio.h>  
typedef struct buy  
{  char  gname;  
   int   sname;  
   int   gprice;  
} BUY;  
int main( )  
{  int i, j, n;  
   int min, price[10][3];  
   int findm( int n, int price[][3], BUY scheme[] );  
  
   static BUY scheme[3]={ {'A', 0, 0}, {'B', 0, 0}, {'C', 0, 0} };  
  
   scanf( "%d", &n );  
   for( i = 0; i < n; i++ )  
   for( j = 0; j < 3; j++ )  
       scanf( "%d", &price[i][j] );  
   min = findm( n, price, scheme );  
   printf("Total Money are : %d\nGoods-Name  Shop-Name  Goods-Price\n", min );  
   for ( i=0; i < 3; i++ )  
       printf("         %c:%10d%13d\n", scheme[i].gname, scheme[i].sname, scheme[i].gprice );  
   return 0;  
}  
int findm( int n, double gp[ ][3] ,BUY schm[ ] )
{
     int i,j,min=0,k,t;
     int a[10000]={0};
     for(i=0;i<3;i++)
     {
        k=100000;
        t=0;
        for(j=0;j<n;j++)
        {
           if(gp[j][i]<k)
        {
           if(a[j]==0)
          {
           k=gp[j][i];
           t=j+1;
           }
      }
         }
         schm[i].sname=t;
         schm[i].gprice=k;
         a[t-1]=1;
         min+=k;
      }
      return min;
}