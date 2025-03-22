#include<stdio.h>
#include<math.h>
#define N 1000

int count(int start, int end, int num[]){
	int i=start, sum=0;
	for(;i<=end;i++){
		sum=sum+num[i];
	}
	return sum;
}

int main(){
	int a=0, b=0, suma=0, sumb=0, delta=100000;
	int i=0, j=0, start=0, end=0;
	int numa[N], numb[N];
	scanf("%d %d",&a, &b);
	for(; i<a; i++){
		scanf("%d", &numa[i]);
	}
	for(; j<b; j++){
		scanf("%d",&numb[j]);
	}
	suma=count(0, a-1, numa);
	//printf("%d\n",suma);
	if(b==1){
		printf("%d\n",numb[0]);
	}
	else{
		//双重循环表示子集
		for(i=0; i<b; i++){
			for(j=i, sumb=0; j<b; j++){
				sumb=sumb+numb[j];
				if(sumb<suma){
					//b的子集和小于a的和
					if(delta>suma-sumb){
						delta=suma-sumb;
						start=i;
						end=j;
					}
				}
				else{
					//b的子集和大于a的情况
					if(delta>sumb-suma){
						delta=sumb-suma;
						start=i;
						end=j;
					}
					continue;
				}
				
			}
		}
		for(; start<=end; start++){
			printf("%d ", numb[start]);
		}
		printf("\n");
	}
	return 0;	
}