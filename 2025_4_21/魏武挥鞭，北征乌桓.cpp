#include<stdio.h>   
#define N 500000   
main()   
{   
  long int n,num[N],count=0;   
 int i,j,k,l;   
   while(scanf("%d",&n)!=EOF)   
 {   
      count=0;   
       for(i=0;i<n;i++)   
        {   
          scanf("%d",&num[i]);   
       }   
      for(i=0;i<n;i++)   
        {   
          for(j=i+1;j<n;j++)   
          {   
              if(num[i]>num[j])   
               {   
                  count++;   
               }   
          }   
      }   
      printf("%d\n",count);   
  }   
}  
/*#include<stdio.h>
#define N 10000
main()
{
	long long int n,num[N],num1[N],num2[N],count=0;
	int i,j,k,l1,l2;
	while(scanf("%d",&n)!=EOF)
	{
		count=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&num[i]);
		}
		for(i=0;i<n;i++)
			{
				for(j=i+1;j<n;j++)
				{
					if(num[i]>num[j])
					{
						count+=(num[i]>num[j]);;
					}
				}
			}
		printf("%d\n",count);
	}
}
/*#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
int a[100], b[100],flag[100];
int main(){
	int n, circle = 0;
	map<int, int> mp;
	cin >> n;
	for(int i = 1; i <= n; i++){
		scanf("%d",&a[i]);
		b[i] = a[i];
		mp[a[i]] = i;
	}
	sort(b+1,b+1+n);
	for(int j = 1; j <= n; j++){
		if(!flag[j]){
			int tp = j;
			while(!flag[tp]){
				flag[tp] = 1;
				tp = mp[b[tp]];
			}
			circle++;//循环节大小 
		}
	}
	cout << n - circle;//最小交换次数 
	return 0;
}
if(n%2==0)
		{
			for(i=0;i<n;i+=2)
			{
				if(num[i]>num[i+1])
				{
					num1[l1]=num[i];
					num2[l2]=num[i+1];
					count++;
					l1++;
					l2++;
				}
				else
				{
					num1[l1]=num[i+1];
					num2[l2]=num[i];
					l1++;l2++;
				}
			}
			num1[l1]=num[n-1];
			l1++;
			for(i=0;i<l1;i++)
			{
				for(j=i+1;j<l1;j++)
				{
					if(num1[i]>num1[j])
					{
						count++;
					}
				}
			}
			for(i=0;i<l2;i++)
			{
				for(j=i+1;j<l2;j++)
				{
					if(num2[i]>num2[j])
					{
						count++;
					}
				}
			}
			for(i=0;i<l1;i++)
			{
				for(j=0;j<l2;j++)
				{
					if(num1[i]>num2[j])
					{
						count++;
					}
				}
			}
		}
		else
		{
			for(i=0;i<n;i+=2)
			{
				if(num[i]>num[i+1])
				{
					num1[l1]=num[i];
					num2[l2]=num[i+1];
					count++;
					l1++;
					l2++;
				}
				else
				{
					num1[l1]=num[i+1];
					num2[l2]=num[i];
					l1++;l2++;
				}
			}
			for(i=0;i<l1;i++)
			{
				for(j=i+1;j<l1;j++)
				{
					if(num1[i]>num1[j])
					{
						count++;
					}
				}
			}
			for(i=0;i<l2;i++)
			{
				for(j=i+1;j<l2;j++)
				{
					if(num2[i]>num2[j])
					{
						count++;
					}
				}
			}
			for(i=0;i<l1;i++)
			{
				for(j=0;j<l2;j++)
				{
					if(num1[i]>num2[j])
					{
						count++;
					}
				}
			}
		}*/