#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <ctype.h>

int main()
{
    char ch = '0';
    int max = 0;
    int min = 0;
    int flag = 0;
    while(scanf("%c", &ch) != '=')
    {
        getchar();
        if(!flag)
        {
            max = ch - '0';
            min = ch - '0';
            flag++;
        }
        if(!isdigit(ch))
        {
            switch (ch)
            {
                case '+':printf("%d+%d=%d\n", max, min, max + min);break;
                case '-':printf("%d-%d=%d\n", max, min, max - min);break;
                case '*':printf("%d*%d=%d\n", max, min, max * min);break;
                case '/':
                        if(min == 0)
                        {
                            printf("Error!\n");
                        }
                        else
                        {
                            printf("%d/%d=%d\n", max, min, max / min);
                        }
                        break;
                case '%':printf("%d", max);
                            printf("%");
                            printf("%d=%d", min, max % min);
                            break;
            
                default:break;
            }
        }

        if(max < ch - '0')
        {
            max = ch - '0';
        }
        if(min > ch - '0')
        {
            min = ch - '0';
        }
        
    }
    return 0;
}

