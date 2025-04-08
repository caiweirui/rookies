#include <stdio.h>
#include <string.h>
#include <assert.h>
#include<math.h>

// 4->10->20->34->52->74->100
// Δ = 6, 10, ...(4n + 2)
// fn+1 - fn = 4n + 2

int main()
{
    long long num1 = 0;
    long long num2 = 0;
    scanf("%lld %lld", &num1, &num2);
    printf("%lld %lld\n", 2 * num1 * num1 + 2, 2 * num2 * num2 + 2);
    return 0;
}

