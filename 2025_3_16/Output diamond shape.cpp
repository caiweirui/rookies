#include <stdio.h>
#include<math.h>

int main() {
    int i=0, j=0, x=0, k=0;
    char y;
    scanf("%d %c",&x, &y);
    for(i=1; i<=2*x-1; i++){
    	//输出每行开头的空格
    	for(j=0; j<abs(x-i); j++){
    		printf(" ");
		}
		//输出每行第一个数
		if(i==1||i==2*x-1){
			printf("%c\n", (y+i-1-'A')%26+'A');	
		}
		else
		{
			printf("%c", (y+i-1-'A')%26+'A');
			//输出第二个空格
			if(i<=x){
				for(k=0; k<2*i-3; k++){
					printf(" ");
				}
			}
			else{
				for(k=0; k<2*(2*x-i)-3; k++){
					printf(" ");
				}
			}
			//输出第二个字母
			printf("%c\n", (y+4*(x-1)-i+1-'A')%26+'A');
		}
	}
	return 0;
}
