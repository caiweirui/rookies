#include<stdio.h>  
main()  
{  
    long int a[100];  
    int i,j,temp,x,k,m;  
    for(i=0;i<100;i++)  
    {  
        scanf("%ld",&a[i]);  
        if(a[i]==0)  
        {  
            m=i-1;  
            goto p;  
        }  
    }  
p:  for(i=0;i<m;i++)  
    {  
        for(j=0;j<m;j++)  
        {  
            if(a[j]>a[j+1])  
            {  
                temp=a[j];  
                a[j]=a[j+1];  
                a[j+1]=temp;  
            }  
        }  
    }  
    for(j=0;j<m;j++)  
    {  
        x=a[j];  
        for(i=j+1;i<100;i++)  
        {  
            if(a[i]==x)  
            {  
                for(k=i;k<m+1;k++)  
                {  
                    a[k]=a[k+1];  
                }  
                 m=m-1; 
            }  
        }  
    }  
      
        if(a[0]==100&&a[1]==100)
        {
        	printf("100\n");
		}
		else
		{for(i=0;i<m+1;i++)  
    {
			printf("%d\n",a[i]); 
		}
		 
    }  
}  