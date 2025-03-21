#include<stdio.h>
#include<string.h>
#define N 1000

int main(){
	char num[N];
	int j=1, count[10]={0};
	gets(num);
	for(int i=0; i<strlen(num); i++){
		count[num[i]-'0']++;
	}
	for(int i=0; i<10; i++)
	{
		if(count[i]>0){
			printf("%d:%d\n", i, count[i]);
		}
	}
	return 0;
}