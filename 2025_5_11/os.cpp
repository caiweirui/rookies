// #include<bits/stdc++.h>
// #define MAX_QUEUE_COUNT 100000

// void print(char *ret, int *retLen, int *block, int blockCount, int hit)
// {
//     int j = 0;
//     if(*retLen != 0)
//     {
//         ret[*retLen] = '/';
//         *retLen = *retLen + 1;
//     }
//     for(j = 0; j < blockCount; j++)
//     {
//         ret[*retLen] = block[j];
//         *retLen = *retLen + 1;
//         ret[*retLen] = ',';
//         *retLen = *retLen + 1;
//     }
//     ret[*retLen] = hit + '0';
//     *retLen = *retLen + 1;
// }

// // 最佳替换算法
// void OPT(const char *queue, int *block, const int blockCount, char *ret, int *retLen, const int subscript)
// {
//     int i = 0;
//     int j = 0;
//     int hit = 0;
//     int first = 0;
//     int replaceBlock = 0;       
//     int temp[100] = {0};
//     int queueLen = strlen(queue);

//     // 判断和当前下标最近的距离
//     for(i = 0; i < blockCount; i++)
//     {
//         for(j = subscript + 1; j < queueLen; j++)
//         {
//             if(queue[j] != block[i])
//             {
//                 temp[i]++;
//             }
//             else
//             {
//                 break;
//             }
//         }
//     }

//     // 选出最远距离的下标
//     for(i = 0; i < blockCount; i++)
//     {
//         if(first < temp[i])
//         {
//             replaceBlock = i;
//             first = temp[i];
//         }
//     }

//     // 相同temp取最先进入的
//     int flag = subscript;
//     for(i = 0; i < blockCount; i++)
//     {
//         if(temp[i] == first)
//         {
//             for(j = 0; j < subscript; j++)
//             {
//                 if(queue[j] == block[i])
//                 {
//                     if(flag > j)
//                     {
//                         replaceBlock = i;
//                         flag = j;
//                     }
//                 }
//             }
//         }
//     }

//     block[replaceBlock] = queue[subscript];

//     // 打印这次的ret
//     print(ret, retLen, block, blockCount, hit);
// }

// // 先入先出算法
// void FIFO(const char *queue, int *block, const int blockCount, char *ret, int *retLen, const int subscript) 
// {
//     static int replaceIndex = 0;  // 静态变量记录替换位置
//     block[replaceIndex] = queue[subscript];  // 替换最早进入的块
//     replaceIndex = (replaceIndex + 1) % blockCount;  // 循环更新替换位置
//     int hit = 0;
//     print(ret, retLen, block, blockCount, hit);
// }

// // 最久未被使用算法
// void LRU(const char *queue, int *block, const int blockCount, char *ret, int *retLen, const int subscript)
// {
//     int hit = 0;
//     memmove(block, block + 1, (blockCount - 1) * sizeof(int));
//     block[blockCount - 1] = queue[subscript];

//     // 打印这次的ret
//     print(ret, retLen, block, blockCount, hit);
// }

// int main()
// {
//     int i = 0;
//     int j = 0;
//     int option = 0;         // 替换算法
//     int blockCount = 0;     // 内存块数
//     int missing = 0;        // 缺页次数
//     int hit = 0;            // 是否命中
//     int retLen = 0;        

//     // 输入
//     fscanf(stdin, "%d", &option);
//     fgetc(stdin);
//     fscanf(stdin, "%d", &blockCount);
//     fgetc(stdin);

//     char *queue = (char*)calloc(MAX_QUEUE_COUNT, sizeof(char));     // 输入队列
//     int *block = (int*)calloc(blockCount, sizeof(int));             // 内存块情况
//     char *ret = (char*)calloc(MAX_QUEUE_COUNT, sizeof(char));        // 返回字符串
//     queue = fgets(queue, MAX_QUEUE_COUNT, stdin);
//     int queueLen = strlen(queue);
//     int empty = blockCount; // 空闲块数

//     // 初始化block
//     for(i = 0; i < blockCount; i++)
//     {
//         block[i] = '-';
//     }

//     // 去除字符串queue中所有的','
//     for(i = 0; i < queueLen; i++)
//     {
//         if(queue[i] == ',')
//         {
//             for(j = i; j < queueLen - 1; j++)
//             {
//                 queue[j] = queue[j + 1];
//             }
//             queueLen--;
//         }
//     }
//     queueLen--;

//     // 遍历所有操作
//     for(i = 0; i < queueLen; i++)
//     {
//         hit = 0;
//         // 还有空闲内存块的情况，缺页，存放在第一个空的内存块
//         if(empty > 0)
//         {
//             missing++;
//             block[i] = queue[i];
//             hit = 0;
//             print(ret, &retLen, block, blockCount, hit);
//             empty--;
//             continue;
//         }   

//         // 是否命中
//         for(j = 0; j < blockCount; j++)
//         {
//             if(block[j] == queue[i])
//             {
//                 hit = 1;
//                 break;
//             }
//         }

//         // 命中
//         if(hit)
//         {
//             // LRU特殊对待
//             if(option == 3)
//             {
//                 memmove(block, block + 1, (blockCount - 1) * sizeof(int));
//                 block[blockCount - 1] = queue[i];
//             }
//             print(ret, &retLen, block, blockCount, hit);
//         }
//         // 替换
//         else
//         {
//             switch (option)
//             {
//                 case 1: OPT(queue, block, blockCount, ret, &retLen, i);
//                     break;
//                 case 2: FIFO(queue, block, blockCount, ret, &retLen, i);
//                     break;
//                 case 3: LRU(queue, block, blockCount, ret, &retLen, i);
//                     break;
//                 default:
//                     break;
//             } 
//             missing++;
//         }
//     }

//     // 打印结果
//     fprintf(stdout, "%s\n", ret);
//     fprintf(stdout, "%d\n", missing);

//     // 释放内存
//     free(ret);
//     ret = NULL;
//     free(queue);
//     queue = NULL;
//     free(block);
//     block = NULL;

//     return 0;
// }
