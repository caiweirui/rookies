#include<stdio.h>

// void swap(int *px, int *py)
// {
//     int temp = *px;
//     *px = *py;
//     *py = temp;
// }

// //升序冒泡排序
// void bubble_sort(int* arr, int len)
// {
//     int i = 0;
//     int j = 0;
//     //n个元素个数需要(n-1)次冒泡排序
//     for(i = 0; i < len - 1; i++)
//     {
//         //每一次需要len-i-1次冒泡排序
//         for(j = 0; j < len - i - 1; j++)
//         {
//             if(arr[j] > arr[j+1])
//             {
//                 swap(&arr[j], &arr[j+1]);
//             }
//         }
//     }
// }

// int main()
// {
//     int arr[1000];
//     int len = 0;
//     scanf("%d", &arr[len++]);
//     while(getchar() != '\n')
//     {
//         scanf("%d", &arr[len++]);
//     }
//     //传递的arr本质是指针变量
//     bubble_sort(arr, len);
//     for(int i = 0; i < len; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
//     return 0;
// }



