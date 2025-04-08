#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>

//A 0100 0001
//B 0100 0010
char new_ascii(char *ch1, char *ch2)
{
    char ch3 = '0';
    char ch4 = '0';
    char chl = 15;//0000 1111
    char chh = -16;//1111 0000

    //最低4位进行异或运算
    ch3 = *ch1 ^ *ch2;
    ch3 = ch3 & chl;
    
    //最高4位进行与运算
    ch4 = *ch1 & *ch2;
    ch4 = ch4 & chh;
    
    return (ch3 | ch4);
}

int main()
{
    char ch1 = '0';
    char ch2 = '0';
    scanf("%c%c", &ch1, &ch2);
    char ret = new_ascii(&ch1, &ch2);
    printf("%c\n", ret);
    return 0;
}