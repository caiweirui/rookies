#include<stdio.h>

int h(int n, int x){
	if(n==0){
		return 1;
	}
	else if(n==1){
		return 2*n;
	}
	else{
		return 2*x*h(n-1, x)-2*(n-1)*h(n-2, x);
	}
}

int main(){
	int n, x;
	scanf("%d %d", &n, &x);
	printf("%d\n", h(n, x));
	return 0;
}