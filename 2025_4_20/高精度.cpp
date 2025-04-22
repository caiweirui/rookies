#include<stdio.h>
#include<string.h>
int main()
{
	int n,i,j,k,t,sum,u,v,e,f,delta;                              
	char a[100]={},b[100]={},s[100]={},c[100]={},d[100]={};                //a[100] is NUM 1;  b[100] is NUM 2;  s[100] is sum;  c[100] is cha;
	int lena,lenb,len,flag=0,l,flag1=0,flag2=0;                       
    char fuhao;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		lena=0;
		lenb=0;
		flag1=0;
		flag2=0;
		scanf("%s",d);
		l=strlen(d);
		for(j=0;j<l;j++)
		{
			if(d[j]=='+'||d[j]=='-')
			{
				fuhao=d[j];
				flag1=1;
			}
			else if(flag1==0)
			a[lena++]=d[j];
			else if(flag1==1)
			b[lenb++]=d[j];
		}
    if(lena>lenb)       //panduan length
    {
    	len=lena-lenb;
    	for(k=lenb-1;k>=0;k--)
    	{
    		b[k+len]=b[k];
		}
		for(k=len-1;k>=0;k--)
		{
			b[k]='0';    //two shu zu liang liang dui qi
		}
		switch(fuhao)
		{
		case '+':          //panduan fuhao 
		for(t=lena-1;t>=0;t--)
		{
			s[t]=a[t]+b[t]-'0'+flag;  
			if((s[t]-'0')>=10)
			{
				s[t]=s[t]-10;
				flag=1; //panduan jin wei
			}
			else
			{
				flag=0;
			}
		}
		if(a[0]+b[0]-'0'-10+flag>='0')
			{
				for(u=lena-1;u>0;u--)
				{
					s[u+1]=s[u];	
				}
				s[0]='1';
			}
		printf("%s\n",s);  //output s[100]
		for(j=0;j<lena;j++)
		s[j]='\0';
		break;
		case '-':
		for(t=lena-1;t>=0;t--)
		{
			c[t]=a[t]-b[t]+'0'-flag;
			if((c[t]>='0'))
			{
				flag=0;
			}
			else
			{
				c[t]=c[t]+10;
				flag=1; //panduan shifou jie '1'
			}
		}
		for(j=0;j<lena;j++)
		{
			if(c[j]!='0')
			flag2=1;
			if(flag2==1)
			printf("%c",c[j]);
			c[j]='\0';
		}
		printf("\n");
		//output c[100]
		break;
		}
	}
	else //the same as the former
	{
		len=lenb-lena;
    	for(k=lena-1;k>=0;k--)
    	{
    		a[k+len]=a[k];
		}
		for(k=len-1;k>=0;k--)
		{
			a[k]='0';
		}
		switch(fuhao)
		{
		case '+':
		for(t=lenb-1;t>=0;t--)
		{
			s[t]=a[t]+b[t]-'0'+flag;
			if((s[t]-'0')>=10)
			{
				s[t]=s[t]-10;
				flag=1;
			}
			else
			{
				flag=0;
			}
		}
		if(a[0]+b[0]-'0'-10+flag>='0')
			{
				for(u=lena-1;u>=1;u--)
				{
					s[u+1]=s[u];	
				}
				s[0]='1';
			}
		printf("%s\n",s);
		for(j=0;j<lenb;j++)
		s[j]='\0';
		break;
		case '-':
		if(lena==lenb)
		{
			for(v=0;v<n;v++)
			{
				delta=strcmp(a,b);
				if(delta>0)
				{
					e=v;
					goto p;
				}
				else
				{
					e=lenb;
				}
			}
p:          for(v=0;v<n;v++)
            {
                delta=strcmp(a,b);
                if(delta<0)
                {
                	f=v;
                	goto q;
				}
				else
				{
					f=lenb;
				}
		    }
q:			if(e<f)
            {
            for(t=lenb-1;t>=0;t--)
		    {
			    c[t]=a[t]-b[t]+'0'+10*flag;
			    if((c[t]>=0))
			    {
				    flag=0;
			    }
			    else
			    {
			    	flag=1;
			    	c[t]=c[t]+10;
			    }
		    }
            for(j=0;j<lenb;j++)
	        {
			if(c[j]!='0')
			flag2=1;
			if(flag2==1)
			printf("%c",c[j]);
			c[j]='\0';
		    }
	    	printf("\n");
		    }
			else
			{
				goto o;
			}
			break;	
		}
		else
		{
o:			for(t=lenb-1;t>=0;t--)
		{
			c[t]=b[t]-a[t]+'0'+10*flag;
			if((c[t]>=0))
			{
				flag=0;
			}
			else
			{
				flag=1;
				c[t]=c[t]+10;
			}
		}
		printf("-");
        for(j=0;j<lenb;j++)
		{
			if(c[j]!='0')
			flag2=1;
			if(flag2==1)
			printf("%c",c[j]);
			c[j]='\0';
		}
		printf("\n");
	    }
		break;
		}
	}
	for(j=0;j<lena;j++)
    a[j]='\0';
    for(j=0;j<lenb;j++)
    b[j]='\0';
}
    return 0;
}

