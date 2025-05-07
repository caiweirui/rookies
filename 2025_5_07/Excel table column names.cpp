// char* convertToTitle(int columnNumber) {
//     char *temp = "ZABCDEFGHIJKLMNOPQRSTUVWXY";
//     int len = 0;
//     char *ret = (char *)malloc(40);
//     memset(ret, 0, 40);
//     while(columnNumber > 26)
//     {
//         ret[len++] = temp[columnNumber % 26];
//         columnNumber /= 26;
//     }
//     ret[len++] = temp[columnNumber % 26];
//     char *left = ret;
//     char *right = ret + len - 1;
//     char temp1 = 0;
//     while(left < right)
//     {
//         temp1 = *left;
//         *left = *right;
//         *right = temp1;
//         left++;
//         right--;
//     }
//     return ret;
// }

char* convertToTitle(int columnNumber) {
    char temp[100]; // 临时数组，足够大以存储结果字符
    int index = 0;
    
    while (columnNumber > 0) {
        columnNumber--; // 调整到0-25的范围
        int mod = columnNumber % 26;
        temp[index++] = 'A' + mod; // 转换为对应的字符
        columnNumber /= 26;
    }
    
    // 分配结果字符串的内存
    char* result = (char*)malloc(index + 1);
    for (int i = 0; i < index; i++) {
        result[i] = temp[index - 1 - i]; // 反转字符顺序
    }
    result[index] = '\0'; // 字符串结束符
    
    return result;
}