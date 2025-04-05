#include <stdio.h>
#include <math.h>

int main() {
    double x1, y1, x2, y2, x3, y3, x4, y4;
    scanf("(%lf,%lf)(%lf,%lf)(%lf,%lf)(%lf,%lf)", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
    
    double sum = (x1 * y2 + x2 * y3 + x3 * y4 + x4 * y1) 
               - (y1 * x2 + y2 * x3 + y3 * x4 + y4 * x1);
    double area = 0.5 * fabs(sum);
    
    printf("%.2f\n", area);
    return 0;
}