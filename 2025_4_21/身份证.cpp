#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,Y,sum,j;
    char s[20]={},a;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	scanf("%s",s);
    int len;
    len=strlen(s);
	if(len==15)
	{
        int j;
        for(j=14;j>=6;j--)
		{
            s[j+2]=s[j];                 //move hou mian qu
        }
	    if(s[14]=='9'&&s[15]=='9'&&(s[16]=='6'||s[16]=='7'||s[16]=='8'||s[16]=='9'))
		{
			s[6]='1';
		    s[7]='8';
		}
        else
        {
        	s[6]='1';
        	s[7]='9';
		}                               //bianbie shi 18nian or 19nian
		sum=(s[0]-'0')*7+(s[1]-'0')*9+(s[2]-'0')*10+(s[3]-'0')*5+(s[4]-'0')*8+(s[5]-'0')*4+(s[6]-'0')*2+1*(s[7]-'0')+(s[8]-'0')*6+(s[9]-'0')*3+(s[10]-'0')*7+(s[11]-'0')*9+(s[12]-'0')*10+(s[13]-'0')*5+(s[14]-'0')*8+(s[15]-'0')*4+(s[16]-'0')*2;
		Y=sum%11;
		switch(Y)
		    {
		    	case 0:a='1';break;case 1:a='0';break;case 2:a='X';break;case 3:a='9';break;
		    	case 4:a='8';break;case 5:a='7';break;case 6:a='6';break;case 7:a='5';break;
		    	case 8:a='4';break;case 9:a='3';break;case 10:a='2';break;
	        }
	    s[17]=a;                        //panduan and choose jiao yan ma
		printf("%s\n",s);         //output ID number 
		for(j=0;j<18;j++)
		s[j]='\0';
    }
    else if(len==18)                           //erdai ID number de situation
    {
    	sum=(s[0]-'0')*7+(s[1]-'0')*9+(s[2]-'0')*10+(s[3]-'0')*5+(s[4]-'0')*8+(s[5]-'0')*4+(s[6]-'0')*2+1*(s[7]-'0')+(s[8]-'0')*6+(s[9]-'0')*3+(s[10]-'0')*7+(s[11]-'0')*9+(s[12]-'0')*10+(s[13]-'0')*5+(s[14]-'0')*8+(s[15]-'0')*4+(s[16]-'0')*2;
		Y=sum%11;
		switch(Y)
		    {
		    	case 0:a='1';break;case 1:a='0';break;case 2:a='X';break;case 3:a='9';break;
		    	case 4:a='8';break;case 5:a='7';break;case 6:a='6';break;case 7:a='5';break;
		    	case 8:a='4';break;case 9:a='3';break;case 10:a='2';break;
	        }
	    if(s[17]==a)                    //yanzheng shibushi valid ID number
	    {
	    	printf("Valid\n");
		}
		else
		{
			printf("Invalid\n");
		}
		for(j=0;j<18;j++)
		s[j]='\0';
	}
	}
	return 0;
}
