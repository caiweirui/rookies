//一个数的二进制数中有多少个1
//用十进制转化成二进制的方法
//参数必须转换成无符号数
// int count_of_1(unsigned int num)
// {
//     int i = 0;
//     int count = 0; 
//     while(num >= 1)
//     {
//         if(num % 2 == 1)
//         {
//             count++;
//         }
//         num /= 2;
//     }
//     return  count;
// }


// //n = n & (n - 1)效果，去除n最右边的一个1
// int count_of_1(unsigned int num)
// {
//     int count = 0;
//     while(num != 0)
//     {
//         num = num & (num - 1); 
//         count++;
//     }
//     return count;
// }

// int main()
// {
//     int num = 0;
//     scanf("%d", &num);
//     int count = count_of_1(num);
//     printf("%d\n", count);
//     return 0;
// }

//求两个不同数之间不同的二进制的个数
//1101
//1011
//&1001
//|1111

// int count_of_1(unsigned int num)
// {
//     int count = 0;
//     // while(num != 0)
//     // {
//     //     num = num & (num - 1); 
//     //     count++;
//     // }
//     //获取一个数二进制的每一位
//     int i = 0;
//     for(i = 0; i < 32; i++)
//     {
//         count += (num >> i) & 1;
//     }
//     return count;
// }

// int main()
// {
//     int num1 = 0;
//     int num2 = 0;
//     scanf("%d %d", &num1, &num2);
//     //按位或的1的个数减去按位与的1的个数
//     // int count1 = count_of_1(num1 & num2);
//     // int count2 = count_of_1(num1 | num2); 
//     // printf("%d\n", count2 - count1);

//     //按位异或的1的个数
//     int count3 = count_of_1(num1 ^ num2);
//     printf("%d\n", count3);

//     return 0;
// }
