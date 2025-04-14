#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

//第2步需要10min
//第3步需要5min
//第4步需要5min
//第2步的时间=第3步和第4步的时间和
//流水线问题
//第2、4步需要不同的医生
//第5步需要30min->只需要一位医生
//求总最短时间=第2步医生总时间+第4步总时间+第5步时间
//第4，5步需要加上第3步的时间
//医生没有需要服务的学生就会下班

//10->5->5->30
//    10->5->5->30
//    

// int time2(int n, int number)
// {
//     return (n / number * 10) * number + (n % number) * 10;
// }

// int time4(int n, int number)
// {
//     return (n / number * 10) * number + (n % number) * 10 + n * 5 + ;
// }

void mintime(long long *time, int *doctor, int n)
{
    int i = 0;
    int number2 = 0;
    int number4 = 0;

    //第二位医生需要的时间
    

}

int main()
{
    int n = 0;
    scanf("%d", &n);
    long long time = 0;
    int doctor = 0;
    mintime(&time, &doctor, n);
    printf("%d %ld\n", time, doctor);
    return 0;
}
