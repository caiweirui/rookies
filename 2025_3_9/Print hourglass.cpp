#include<stdio.h>
#include<string.h>
#include<math.h>

#define N 1000
int flour(int x){
	int n=1;
	for(; x>=0; n+=2){
		if(n==1){
			x--;
		}
		else{
			x-=n*2;
		}
	}
	return n-4;
}

int result(int x){
    // 初始化变量n为1，用于计数
	int n=1;
    // 使用for循环，条件为x大于等于0，每次循环n增加2
	for(; x>=0; n+=2){
        // 如果n等于1，表示第一次循环，x减1
		if(n==1){
			x--;
		}
        // 否则，x减去n的两倍
		else{
			x-=n*2;
		}
	}
    // 返回x加上2倍的(n-2)，调整最终结果
	return x+2*(n-2);
}

int main(){
	int i=0,j=0,k=0,l=0,m=0,x=0,n=0;
	char c='0';
	scanf("%d %c",&x, &c);
	n=flour(x);
	k=result(x);
	j=n;
	for(; i<=n; i++, j-=2){
		if(j==-1){
			continue;
		}
		else{
			for(m=abs(j); m<n; m+=2){
				printf(" ");
			}
			for(l=0; l<abs(j); l++){
				printf("%c",c);
			}
			printf("\n");
		}	
	}
	printf("%d\n",k);
	return 0;
}