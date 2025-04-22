#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 
void reverse(char str[], int start, int end)
{
	int len,count=0;
	char t;
	len=strlen(str);
	if(start+1==len)
	{
		return;
	}
	else
	{
		if(end>=len)
	    {
		end=len-1;
    	}
	    if(start==end)
	    {
		return;
	    }
	    else if(end==start+1)
	    {
		t=str[end];
		str[end]=str[start];
		str[start]=t;
		return;
	    }
	    else if(end-start>=2)
	    {
		t=str[end];
		str[end]=str[start];
		str[start]=t;
		return reverse(str, (start+1), (end-1));
	    }
	}
	
}
int main( )  
{   char str[100];  
    int start, end;  
    gets(str);  
    scanf("%d%d", &start, &end);  
    reverse( str, start, end );  
    printf("%s\n", str);  
    return 0;  
}