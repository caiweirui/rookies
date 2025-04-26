#include<stdio.h>
#include<math.h>

int main()
{
    int num = 0;
    scanf("%d", &num);
    int i = 0;
    int temp = (int)pow(num, 0.5) + 1;
    for(i = 2; i <= temp; i++)
    {
        if(num % i == 0)
        {
            printf("no\n");
            return 0;
        }
    }
    printf("yes\n");
    return 0;
}