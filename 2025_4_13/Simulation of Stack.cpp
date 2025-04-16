#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

void reverse(char *print, const int printlen)
{
    int left = 0;
    int right = printlen;
    while(right && print[right] != ' ')
    {
        left = right--;
    }
    right = printlen;
    while(left < right)
    {
        char temp = print[left];
        print[left] = print[right];
        print[right] = temp;
        left++;
        right--;
    }

}

int main()
{
    char arr[20] = {'\0'};
    char stack[100] = {'\0'};
    char print[100000] = {'\0'};
    int i = 0;
    int arrlen = 0;
    int stacklen = 0;
    int printlen = 0;
    int pushflag = 0;
    while(scanf("%s", arr) != EOF)
    {
        arrlen = strlen(arr);
        stacklen = strlen(stack);
        pushflag = 0;
        //压栈操作
        if(strncmp(arr, "push", 4) == 0)
        {
            if(stacklen)
            {
                stack[stacklen++] = ' ';
            }
            for(i = 0; i < arrlen; i++)
            {
                if(arr[i] == '(')
                {
                    pushflag = 1;
                    i++;
                }
                if(arr[i] == ')')
                {
                    pushflag = 0;
                }
                if(pushflag)
                {
                    stack[stacklen++] = arr[i]; 
                }
            }
        }

        //出栈操作
        else if(strncmp(arr, "pop", 3) == 0)
        {
            for(i = stacklen; i >= 0; i--)
            {
                if(stack[i] != ' ')
                {
                    print[printlen++] = stack[i];
                    stack[i] = '\0';
                    stacklen--;
                }
                else
                {
                    stack[i--] = '\0';
                    stacklen--;
                    break;
                }
            }
            reverse(print, printlen);
            print[printlen++] = ' ';
        }
        else if(strcmp(arr, "sequence") == 0)
        {
            printf("%s\n", stack);
        }
        else
        {
            printf("%s ", print);
            for(i = stacklen; i >= 0; i--)
            {
                printf("%c", stack[i]);
            }
            printf("\n");
        }
    }

    return 0;
}