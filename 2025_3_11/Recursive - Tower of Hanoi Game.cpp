#include<stdio.h>

int fun(int n){
	if(n==1){
		return 2;
	}
	else if(n==2){
		return 8;
	}
	else{
		return 3*fun(n-1)+2;
	}
}

int main(){
	int n;
	scanf("%d",&n);
	printf("%d\n", fun(n));
	return 0;
}
