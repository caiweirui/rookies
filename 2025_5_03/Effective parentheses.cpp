#include<bits/stdc++.h>

// bool isValid(char* s) {
//     int len = strlen(s);
//     if (len == 0) return true;         // 空字符串视为有效
//     if (len % 2 != 0) return false;    // 奇数长度直接返回false

//     char* stack = (char*)malloc(len * sizeof(char));
//     int top = -1;

//     for (int i = 0; i < len; i++) {
//         char c = s[i];
//         if (c == '(' || c == '[' || c == '{') {
//             stack[++top] = c;          // 左括号入栈
//         } else {
//             if (top == -1) {           // 栈为空，无法匹配右括号
//                 free(stack);
//                 return false;
//             }
//             char topChar = stack[top--];
//             // 检查括号类型是否匹配
//             if ((c == ')' && topChar != '(') ||
//                 (c == ']' && topChar != '[') ||
//                 (c == '}' && topChar != '{')) {
//                 free(stack);
//                 return false;
//             }
//         }
//     }

//     bool result = (top == -1);  // 栈空表示所有括号正确闭合
//     free(stack);
//     return result;
// }


bool isValid(char* s) {
    int len = strlen(s);
    if (len == 0) return true;         // 空字符串视为有效
    if (len % 2 != 0) return false;    // 奇数长度直接返回false

    char *stack = (char *)calloc(len, sizeof(char));
    int top = -1;

    int i = 0;
    for(i = 0; i < len; i++)
    {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            stack[++top] = s[i];
        }
        else
        {
            if(i == 0)
            {
                free(stack);
                return false;
            }
            else
            {
                if(top != -1 && (stack[top] == '(' && s[i] == ')' || stack[top] == '[' && s[i] == ']' || stack[top] == '{' && s[i] == '}')) 
                {
                    top--;
                }
                else
                {
                    free(stack);
                    return false;
                }
            }
        }
    }
    if(top == -1)
    {
        free(stack);
        return true;
    }
    else
    {
        free(stack);
        return false;
    }
}


int main()
{
    char s[] = "()[]{}";
    bool ret = isValid(s);
    if(ret)
    {
        printf("true");
    }
    else
    {
        printf("false");
    }
    return 0;
}