#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

// int main()
// {
//     //p1 = p2       
//     //理由：abcdef是放在静态区里面，只需要有一份就可以了，p1和p2指向相同的字符串
//     //arr1 != arr2
//     //理由：初始化的开辟了一个空间用于存放，显然开辟的不是同一个空间
//     const char *p1 = "abcdef";
//     const char *p2 = "abcdef";

//     char arr1[] = "abcdef";
//     char arr2[] = "abcdef";
//     //*p = 'w';
    
//     if(p1 == p2)
//     {
//         printf("p1 = p2\n");
//     }
//     else
//     {
//         printf("p1 != p2");
//     }

//     if(arr1 == arr2)
//     {
//         printf("arr1 = arr2\n");
//     }
//     else
//     {
//         printf("arr1 != arr2");
//     }

//     return 0;
// }

// qsort排序整型
//大于返回1.等于返回0，小于返回-1
// int cmp1(const void *e1, const void *e2)
// {
//     return (*(int *)e1 - *(int *)e2);
// }

// int cmp2(const void *e1, const void *e2)
// {
//     return (*(int *)e2 - *(int *)e1);
// }

// int main()
// {
//     int arr[100] = {0};
//     int n = 0;
//     scanf("%d", &n);
//     getchar();
//     int i = 0;
//     for(i = 0; i < n; i++)
//     {
//         scanf("%d", &arr[i]);
//     }
//     //升序
//     //qsort(arr, n, sizeof(int), cmp1);

//     //降序
//     qsort(arr, n, sizeof(int), cmp2);

//     for(i = 0; i < n; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");

//     return 0;
// }

// 用qsort改造冒泡排序和排序结构体
struct stu
{
    char name[10];
    int age;
    int height;
    double weigh;
};

int cmp_stu_name(const void *e1, const void * e2)
{
    return strcmp(((stu *)e1)->name, ((stu *)e2)->name);
}

int cmp_stu_age(const void *e1, const void * e2)
{
    return (((stu *)e1)->age - ((stu *)e2)->age);
}


void swap(char *buff1, char *buff2, int width)
{
    int i = 0;
    for(i = 0; i < width; i++)
    {
        char temp = *buff1;
        *buff1 = *buff2;
        *buff2 = temp;
        buff1++;
        buff2++;
    }
}

void bubble_sort(void* base, size_t len, size_t width, int(* cmp)(const void *e1, const void *e2))
{
    size_t i = 0;
    size_t j = 0;
    for(i = 0; i < len - 1; i++)
    {
        for(j = 0; j < len - i - 1; j++)
        {
            //强制类型转换成char*，结合宽度进行比较
            if(cmp((char*)base + j * width, (char *)base + (j + 1) * width) > 0)
            {
                //交换，按照每个字节进行交换
                swap((char*)base + j * width, (char *)base + (j + 1) * width, width);
            }
        }
    }

}

int main()
{
    stu s[100];
    int n = 0;
    int i = 0;
    scanf("%d", &n);
    getchar();
    for(i = 0; i < n; i++)
    {
        scanf("%s %d %d %lf", &(s[i].name), &(s[i].age), &(s[i].height), &(s[i].weigh));
        getchar();
    }
    
    // qsort(s, n, sizeof(s[0]), cmp_stu_name);
    // qsort(s, n, sizeof(s[0]), cmp_stu_age);
    bubble_sort(s, n, sizeof(s[0]), cmp_stu_name);

    for(i = 0; i < n; i++)
    {
        printf("%s %d %d %lf", (s[i].name), (s[i].age), (s[i].height), (s[i].weigh));
        printf("\n");
    }

    return 0;
}

