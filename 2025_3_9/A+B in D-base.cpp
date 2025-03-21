#include<stdio.h>
#include<string.h>
#include<math.h>

#define N 1000
int main(){
	int i=0,j=0,k=0,l=0,m=0,x=0,n=0,a=0,b=0,r=0;
	char num[N];
	scanf("%d %d %d",&a, &b, &r);
	m=a+b;
	while(1){
		if(m<r){
			num[i]=m+'0';
			break;
		}
		else{
			num[i]=m%r+'0';
			m=m/r;
			i++;
		}
	}
	l=strlen(num);
	for(j=l-1; j>=0; j--){
		printf("%c",num[j]);
	}
	printf("\n");
	return 0;
}