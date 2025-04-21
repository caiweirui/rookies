#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int f(char s[])
{
	int sum=0;
	if(s[0]=='H')
	sum+=60;
	else if(s[0]=='S')
	sum+=45;
	else if(s[0]=='D')
	sum+=30;
	else if(s[0]=='C')
	sum+=15;
	if(s[1]>='2'&&s[1]<='9')
	sum+=s[1]-'0';
	else if(s[1]=='1')
	sum+=10;
	else if(s[1]=='J')
	sum+=11;
	else if(s[1]=='Q')
	sum+=12;
	else if(s[1]=='K')
	sum+=13;
	else if(s[1]=='A')
	sum+=14;
	return sum;
}
int main()
{
	char A[5][10]={},B[5][10]={},c,d;
	int a[5]={0},b[5]={};
	int i,j,k=0,t=0,l,m,n;
	for(i=0;i<3;i++)
	scanf("%s",A[i]);//输入A的牌
	for(i=0;i<3;i++)
	scanf("%s",B[i]);//输入B的牌 
	for(i=0;i<3;i++)
	{
		if(strlen(A[i])==2)
		{
			c=A[i][0];
			d=A[i][1];
			if(!(c=='D'||c=='H'||c=='S'||c=='C'))
			{
				printf("Input Error!\n");
				return 0;
			}
			if(!((d>='2'&&d<='9')||d=='J'||d=='Q'||d=='K'||d=='A'))
			{
				printf("Input Error!\n");
				return 0;
			}
		}
		else if(strlen(A[i])==3)
		{
			c=A[i][0];
			if(!(c=='D'||c=='H'||c=='S'||c=='C'))
			{
				printf("Input Error!\n");
				return 0;
			}
			if(A[i][1]!='1'||A[i][2]!='0')
			{
				printf("Input Error!\n");
				return 0;
			}
		}
		if(strlen(B[i])==2)
		{
			c=B[i][0];
			d=B[i][1];
			if(!(c=='D'||c=='H'||c=='S'||c=='C'))
			{
				printf("Input Error!\n");
				return 0;
			}
			if(!((d>='2'&&d<='9')||d=='J'||d=='Q'||d=='K'||d=='A'))
			{
				printf("Input Error!\n");
				return 0;
			}
		}
		else if(strlen(B[i])==3)
		{
			c=B[i][0];
			if(!(c=='D'||c=='H'||c=='S'||c=='C'))
			{
				printf("Input Error!\n");
				return 0;
			}
			if(B[i][1]!='1'||B[i][2]!='0')
			{
				printf("Input Error!\n");
				return 0;
			}
		}
	}
	for(i=0;i<3;i++)
	{
		a[i]=f(A[i]);
		b[i]=f(B[i]);
	}
	int C[3]={0,1,2},D[3]={0,1,2},tmp;
	for(i=0;i<2;i++)
	{
		for(j=0;j<2-i;j++)
		{
			if(a[j]<a[j+1])
			{
				C[j]=j+1;
				C[j+1]=j;
			}
			else if(a[j]==a[j+1])
			{
				printf("Input Error!\n");
				return 0;
			}
			if(b[j]<b[j+1])
			{
				D[j]=j+1;
				D[j+1]=j;
			}
			else if(b[j]==b[j+1])
			{
				printf("Input Error!\n");
				return 0;
			}
		}
	}//冒泡+记录排序后次序关系
	for(i=0;i<3;i++)
	{
		if(a[C[i]]>b[D[i]])
		{
			printf("Winner is A!\n");
			printf("A: %s %s %s\n",A[C[0]],A[C[1]],A[C[2]]);
			printf("B: %s %s %s\n",B[D[0]],B[D[1]],B[D[2]]);
			return 0;
		}
		else if(a[C[i]]<b[D[i]])
		{
			printf("Winner is B!\n");
			printf("A: %s %s %s\n",A[C[0]],A[C[1]],A[C[2]]);
			printf("B: %s %s %s\n",B[D[0]],B[D[1]],B[D[2]]);
			return 0;
		}
	}
	printf("Winner is X!\n");
	printf("A: %s %s %s\n",A[C[0]],A[C[1]],A[C[2]]);
	printf("B: %s %s %s\n",B[D[0]],B[D[1]],B[D[2]]);
	return 0; 
}
