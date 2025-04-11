#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>

// 读取输入的数据，保存每组字符串和进制。
// 将每组字符串根据对应的进制转换为十进制数值。
// 对所有转换后的数据进行排序，按照指定的规则。
// 输出排序后的结果。

typedef struct
{
    long long decimal;
    int base;
}Number;

//char_to_value函数处理字符到数值的转换
int char_to_value(char c)
{
    c = tolower(c);
    if(c >= '0' && c <= '9')
    {
        return c - '0';
    }
    else
    {
        return 10 + (c - 'a');
    }
}

//convert_to_decimal函数实现任意进制到十进制的转换
long long convert_to_decimal(char *str, int base)
{
    long long res = 0;
    for(int i = 0; str[i]; i++)
    {
        int v = char_to_value(str[i]);
        res = res * base + v;
    } 
    return res;
}

//自定义比较函数实现先按原进制降序，再按十进制值降序：
int compare(const void *a, const void *b)
{
    const Number *numA = (const Number *)a;
    const Number *numB = (const Number *)b;
    if(numA->base != numB->base)
    {
        return numB->base - numA->base;
    }
    else
    {
        if(numB->decimal > numA->decimal)
            return 1;
        else if(numB->decimal < numA->decimal)
            return -1;
        else
            return 0;
    }

}

int main() {
    int n;
    scanf("%d", &n);
    
    Number *numbers;
    
    for (int i = 0; i < n; i++) {
        char str[9];
        int base;
        scanf("%s %d", str, &base);
        numbers[i].decimal = convert_to_decimal(str, base);
        numbers[i].base = base;
    }
    
    qsort(numbers, n, sizeof(Number), compare);
    
    for (int i = 0; i < n; i++) {
        printf("%lld %d\n", numbers[i].decimal, numbers[i].base);
    }
    
    //free(numbers);
    return 0;
}

