#include<stdio.h>  
#include<string.h>  
main()  
{  
    char a[100],b;  
    int i,j,k,lena;  
    gets(a);  
    lena=strlen(a);
    for(i=0;i<lena;i++)  
    {  
        if(a[i]!='\0')  
        {  
            b=a[i];  
            for(j=i+1;j<lena;j++)  
            {  
                if(a[j]==b)  
                {  
                    for(k=j;k<lena;k++)  
                    {  
                        a[k]=a[k+1];  
                    }
					a[lena]='\0';  
                    j--;  
                }  
            }  
        }  
          
    }  
    printf("%s\n",a);  
}