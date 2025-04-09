#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <ctype.h>

int main()
{
    double a1 = 0.0, b1 = 0.0, c1 = 0.0;
    double a2 = 0.0, b2 = 0.0, c2 = 0.0;
    scanf("%lf %lf %lf", &a1, &b1, &c1);
    getchar();
    scanf("%lf %lf %lf", &a2, &b2, &c2);
    double v1 = a1 * b1 *c1;
    double v2 = a2 * b2 *c2;
    int count = 0;
    count = (int)(a1 / a2) * (int)(b1 / b2) * (int)(c1 / c2);
    printf("%.2f", (count * v2 / v1) * 100);
    printf("%c", '%');
    printf("\n");

    return 0;
}

//格里高利公式：π/4=1−1/3+1/5−1/7+...