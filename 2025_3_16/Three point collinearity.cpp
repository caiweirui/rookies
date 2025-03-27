#include <stdio.h>

int main() {
    double i=0, j=0, b=0, k=0;
    double ax=0, ay=0, bx=0, by=0, cx=0, cy=0;
    char num[15];
    gets(num);
    ax=num[1]-'0';
    ay=num[3]-'0';
    bx=num[6]-'0';
    by=num[8]-'0';
    cx=num[11]-'0';
    cy=num[13]-'0';
    if(ax==bx&&ax==cx||ay==by&&ay==cy){
    	printf("Yes\n");
	}
	else{
		if((by-ay)/(bx-ax)==(cy-ay)/(cx-ax)){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
	}
	return 0;
}
