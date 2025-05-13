#include<bits/stdc++.h>

char* addStrings(char* num1, char* num2) {
    int num1Len = strlen(num1);
    int num2Len = strlen(num2);
    int retLen = 10001;
    char* ret = (char*)calloc(retLen, sizeof(char));
    int i = 0;
    int cf = 0;
    int temp = 0;
    int left = 0;
    int right = 0;
    for(i = 0; i < retLen - 1; i++)
    {
        temp = 0;
        if(num1Len - i - 1 >= 0)
        {
            temp += num1[num1Len - i - 1] - '0';
        }
        if(num2Len - i - 1 >= 0)
        {
            temp += num2[num2Len - i - 1] - '0';
        }
        temp += cf;
        if(temp >= 10)
        {
            temp -= 10;
            cf = 1;
        }
        else
        {
            cf = 0;
        }
        ret[i] = temp + '0';
    } 

    if(cf == 1)
    {
        ret[retLen - 1] = '1';
    }

    right = retLen - 1 - (cf == 0);

    while(left < right)
    {
        temp = ret[left];
        ret[left] = ret[right];
        ret[right] = temp;
        left++;
        right--;
    }
    while(*ret == '0' && *(ret + 1) != '\0')
    {
        ret++;
    }
    return ret;
}

int main()
{
    char num1[] = "1";
    char num2[] = "9";
    char *ret = addStrings(num1, num2);
    printf(ret);
    return 0;
}