char** fizzBuzz(int n, int* returnSize) {
    if (n <= 0) {
        *returnSize = 0;
        return NULL;
    }
    
    char** answer = (char**)malloc(n * sizeof(char*));
    *returnSize = n;
    
    for (int i = 1; i <= n; i++) {
        if (i % 15 == 0) {
            answer[i-1] = (char*)malloc(9 * sizeof(char));
            strcpy(answer[i-1], "FizzBuzz");
        } else if (i % 3 == 0) {
            answer[i-1] = (char*)malloc(5 * sizeof(char));
            strcpy(answer[i-1], "Fizz");
        } else if (i % 5 == 0) {
            answer[i-1] = (char*)malloc(5 * sizeof(char));
            strcpy(answer[i-1], "Buzz");
        } else {
            // 计算数字字符串所需长度
            int len = snprintf(NULL, 0, "%d", i) + 1;
            answer[i-1] = (char*)malloc(len * sizeof(char));
            snprintf(answer[i-1], len, "%d", i);
        }
    }
    
    return answer;
}