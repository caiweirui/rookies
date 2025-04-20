#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

// 模拟strlen()
// 1. 计数器方法
// 2. 指针-指针
// 3. 递归的方法
// size_t my_strlen(const char *arr)
// {
//     //arr不能为空
//     assert(arr);
//     size_t i = 0;
//     while(*(arr + (++i)));
//     return i;
// }

// 递归
// size_t my_strlen(const char *arr)
// {
//     if(*arr)
//     {
//         return my_strlen(arr + 1) + 1;
//     }
//     else
//     {
//         return 0;
//     }
// }

// 模拟strcpy()
// char* my_strcpy(char *destination, const char *arr)
// {
//     assert(destination && arr);
//     while(*(destination++) = *(arr++));
//     return destination;
// } 

// 模拟strcat
// char* my_strcat(char *destination, const char *arr)
// {
//     assert(destination && arr);
//     char *p = destination;
//     while(*(++destination));
//     while(*destination++ = *arr++);
//     return p;
// }

// 模拟strcmp
// int my_strcmp(const char *str1, const char *str2)
// {
//     assert(str1 && str2);
//     while(!(*str1 - *str2) && *str1 && *str2)
//     {
//         str1++;
//         str2++;
//     }
//     return (*str1 - *str2);
// }

// 模拟strstr
//三个指针，主串p1和子串p2用于比较，p用于临时存放p1第一个匹配的位置，
//如果比较不相等，p1回到p的下一位重新比较
// char *my_strstr(char * mainstr, char *substr)
// {
//     assert(mainstr && substr);
//     char* p1 = mainstr;
//     char* p2 = substr;
//     char* p = NULL;

//     while(*p1)
//     {
//         if(*p1 == *p2)
//         {
//             // 保存p1的初始状态
//             p = p1;
//             while(*p2)
//             {
//                 if(*p1 == *p2)
//                 {
//                     p1++;
//                     p2++;
//                 }
//                 else
//                 {
//                     p1 = p + 1;
//                     p2 = substr;
//                     break;
//                 }
//             }

//             //证明存在子串，返回记录的地址p
//             if(*p2 == '\0')
//             {
//                 return p;
//             }
//         }
//         else
//         {
//             p1++;
//         }
//     }

//     return NULL;
// }

// 模拟memcpy
// void *my_memcpy(void * destination, void * source, size_t num)
// {
//     assert(destination && source);
//     char *dest = (char *)destination;
//     char *src = (char *)source;
//     while(num--)
//     {
//         *dest++ = *src++;
//     }
//     return destination;
// }

// 模拟memmove
void *my_memmove(void * destination, void * source, size_t num)
{
    assert(destination && source);

    char *p1 = (char *)destination;
    char *p2 = (char *)source;

    // 从后往前拷贝
    if(destination > source)
    {
        while(num--)
        {
            *(p1 + num) = *(p2 + num);
        }
    }
    //从前往后拷贝
    else if(destination < source)
    {
        while(num--)
        {
            *p1++ = *p2++;
        }
    }
    else
    {
        return destination;
    }
    return destination;
}


int main()
{
    // char arr[1000] = {'0'};
    // gets(arr);

    // // 模拟strlen()
    // // size_t len = my_strlen(arr);
    // // printf("%u\n", len);

    // // 模拟strcpy
    // char destination[1000] = "123654789";
    // const char *sep = "68";
    // char arr2[1000] = {'0'};
    // strcpy(arr2, arr); 
    
    // char *ret = NULL;

    // // 除了第一次使用，后面在使用strtok时，str均为空指针
    // // 用static记录这个记忆的位置
    // for(ret = strtok(arr2, sep); ret != NULL; ret = strtok(NULL, sep))
    // {
    //     printf("%s\n", ret);
    // }
    
    // my_strcpy(destination, arr); 
    // printf("%s\n", destination);

    // 模拟strcat
    // my_strcat(destination, arr);
    // printf("%s\n", destination);

    // 模拟strcmp
    // int ret = my_strcmp(arr, destination);
    // if(ret > 0)
    // {
    //     printf(">\n");
    // }
    // else if(ret == 0)
    // {
    //     printf("=\n");
    // }
    // else
    // {
    //     printf("<\n");
    // }

    // 模拟strstr
    // char *ret = my_strstr(destination, arr);

    // if(ret == NULL)
    // {
    //     printf("没找到\n");
    // }
    // else
    // {
    //     printf("%s\n", ret);
    // }


    int arr1[] = {1,2,3,4,5,6,7,8,9,10};
    int arr2[] = {1,2,3,2,1,2,3};

    // 模拟实现memcpy
    // my_memcpy(arr1 + 2, arr1, 20);

    // 模拟实现memmove
    my_memmove(arr1, arr1 + 2, 20);

    for(int i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++)
    {
        printf("%d ", arr1[i]);
    }
    printf("\n");
    return 0;
}



