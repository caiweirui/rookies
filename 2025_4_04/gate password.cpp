#include<stdio.h>
#include<string.h>
#include<math.h>

int is_prime(int num)
{
    int i = 0;
    for(i = 2; i < (int)pow(num, 0.5) + 1; i++)
    {
        if(num % i == 0)
        {
            return 0;
        }
    }
    return 1;
} 

int greatest_common_divisor(int a, int b)
{
    int r = 1;
    while(r)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int Least_common_multiple(int a, int b)
{
    return (a * b / greatest_common_divisor(a, b));
}

int main()
{
    int K = 0;
    int a = 0;
    int b = 0;
    scanf("%d %d %d", &K, &a, &b);
    //K:第k小的质数
    int i = 2;
    while(K > 0)
    {
        if(is_prime(i))
        {
            K--;
        }
        i++;
    }
    i--;
    //printf("i = %d", i);

    //x满足行列式的个位
    int x = ((24 * 30) / a) % 10;

    //y是最小公约数
    int y = greatest_common_divisor(1234, 4321);

    //z是最小公倍数的十位
    int z = Least_common_multiple(463, b);
    z = (z / 10) % 10;

    printf("%d%d%d%d\n", i, x, y, z);
    return 0;

}