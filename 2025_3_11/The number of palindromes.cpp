#include<stdio.h>
#include<string.h>
#include<math.h>
#define N 1000

//非回文数的自加
/*void add(char num[], int r){
	int len=strlen(num), int i=0;
	char numadd[N], cf=0;
	for(i=0; i<len; i++){
		numadd[i]=cf+(num[i]-'0')+(num[len-1-i]-'0')+'0';
		if(numadd[i]-'0'>=r){
			cf=1;
			numadd[i]=numadd[i]-r;
		}
		else{
			cf=0;
		}
	}
}*/

//判断回文数，是返回1，不是返回0
int test(char num[]){
	int x=1;
	int i=0, j=0;
	int len=strlen(num);
	for(j=len-1; i<j; i++, j--){
		if(num[i]==num[j]){
			x=1;
		}
		else{
			x=0;
			break;
		}
	}
	return x;
} 

int main(){
	char r1, num[N], numadd[N];
	int count=0, cf=0, i=0, len=0, r=0;
	scanf("%c", &r1);
	scanf("%s", &num);
	
	//初始化numadd
	strcpy(numadd, num);
	
	//确定r进制
	switch(r1){
		case 'A':r=r1-r1+10;break;
		case 'B':r=r1-r1+11;break;
		case 'C':r=r1-r1+12;break;
		case 'D':r=r1-r1+13;break;
		case 'E':r=r1-r1+14;break;
		case 'F':r=r1-r1+15;break;
		case 'G':r=r1-r1+16;break;
		default:r=r1-'0';break;
	}
	
	//循环确定累加的次数
	while(test(numadd)==0){
		//r进制的加减法
		len=strlen(num);
		printf("len(numadd)=%d\n", len);
		for(i=0, cf=0; i<len; i++){
			numadd[i]=cf+(num[i]-'0')+(num[len-1-i]-'0')+'0';
			if(numadd[i]-'0'>=r){
				cf=1;
				numadd[i]=numadd[i]-r;
			}
			else{
				cf=0;
			}
			if(i==len-1&&cf==1){
				numadd[len]='1';
			}
		}
		
		for(i=0; i<strlen(numadd); i++){
			printf("%c ", numadd[i]);
		}
		printf("\n");
		
		strcpy(num, numadd);
		
		count++;
		if(count>30){
			break;
		}
		printf("count=%d\n",count);
	}
	//最终数组
	for(i=0; i<strlen(num); i++){
		printf("%c ", numadd[i]);
	}
	printf("\n");
	
	//步数的输出
	if(count>30){
		printf("Impossible!\n");
	}
	else{
		printf("STEP=%d\n",count);
	}
	return 0;
}