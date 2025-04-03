#include<stdio.h>
#include<math.h>

// //不产生中间变量交换两个数

// //a=a+b, b=a-b, a=a-b
// //会溢出

// //位操作符
// //a = a ^ b
// //b = a ^ b
// //a = a ^ b

// //求一个整数存储在内存中的二进制中1的个数
// int binary_count_of_1(int num)
// {
//     int i = 0;
//     int num2 = 1;
//     int count = 0;
//     for(i = 0; i < 32; i++)
//     {
//         num2 = 1 << i;
//         // == 的优先级比 & 高
//         if((num & num2) != 0)
//         {
//             count++;
//         }
//     }
//     return count;
// }

// int main()
// {
//     int num = 0;
//     scanf("%d", &num);
//     int count = binary_count_of_1(num);
//     printf("%d\n", count);
//     return 0;
// }


// int binary_count_of_1(int num) {
//     int count = 0;
//     for (int i = 0; i < 32; i++) {  // 覆盖所有32位
//         int mask = 1 << i;          // 使用位移替代pow()
//         if ((num & mask) != 0) {    // 明确优先级，直接判断是否为1
//             count++;
//         }
//     }
//     return count;
// }

// int main() {
//     int num;
//     printf("请输入一个整数：");
//     scanf("%d", &num);
//     printf("二进制中1的个数：%d\n", binary_count_of_1(num));
//     return 0;
// }

