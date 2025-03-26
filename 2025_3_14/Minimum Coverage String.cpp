/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */  
 
#include <stdio.h>  
#include <string.h>  
#define MAX_LEN 10000  
 
#include <stdlib.h>  
/** 
 * @param S string字符串  
 * @param T string字符串  
 * @return string字符串 
 */  
  
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */  

#define CHAR_SET_SIZE 128 // ASCII字符集大小

char* minWindow(char* s, char* t) {
    int need[CHAR_SET_SIZE] = {0};      // 目标字符计数
    int window[CHAR_SET_SIZE] = {0};    // 滑动窗口计数
    int needCnt = 0;                    // 不同字符种类数
    
    // 1. 统计目标字符串t的字符分布
    for (int i = 0; t[i] != '\0'; i++) {
        if (need[t[i]] == 0) needCnt++;
        need[t[i]]++;
    }
    
    int left = 0, right = 0;          // 滑动窗口指针
    int valid = 0;                    // 满足条件的字符种类数
    int start = 0, minLen = INT_MAX;  // 结果记录
    
    // 2. 滑动窗口遍历主字符串
    while (s[right] != '\0') {
        char c = s[right];
        right++;
        
        // 更新窗口计数
        if (need[c] > 0) {
            window[c]++;
            // 当窗口计数刚好达到需求时，有效种类+1
            if (window[c] == need[c]) {
                valid++;
            }
        }
        
        // 当满足所有字符需求时，尝试收缩窗口
        while (valid == needCnt) {
            // 更新最小窗口记录
            if (right - left < minLen) {
                start = left;
                minLen = right - left;
            }
            
            // 收缩左边界
            char d = s[left];
            left++;
            
            if (need[d] > 0) {
                // 当窗口计数刚好等于需求时，有效种类-1
                if (window[d] == need[d]) {
                    valid--;
                }
                window[d]--;
            }
        }
    }
    
    // 3. 构造结果字符串
    if (minLen == INT_MAX) return "none";
    
    char* res = (char*)malloc((minLen + 1) * sizeof(char));
    strncpy(res, s + start, minLen);
    res[minLen] = '\0';
    return res;
}


/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */  
  
int main() {  
    char input[100000];  
    char S[MAX_LEN], T[MAX_LEN];  
  
    // 读取一整个字符串  
    scanf("%s", input);  
      
    // 使用 strtok() 函数分割字符串  
    // 第一个字符串存入S  
    char *ptr = strtok(input, ",");  
    if (ptr != NULL) {  
        int len = strlen(ptr);  
        if (len >= 2 && ptr[0] == '"' && ptr[len-1] == '"') {  
            ptr[len-1] = '\0';  
            memmove(ptr, ptr+1, len-1);  
        }  
        strncpy(S, ptr, len);  
        S[len - 1] = '\0';  
    }  
      
    // 第二个字符串存入T   
    ptr = strtok(NULL, ",");  
    if (ptr != NULL) {  
        int len = strlen(ptr);  
        if (len >= 2 && ptr[0] == '"' && ptr[len-1] == '"') {  
            ptr[len-1] = '\0';  
            memmove(ptr, ptr+1, len-1);  
        }  
        strncpy(T, ptr, len);  
        T[len - 1] = '\0';  
    }  
      
    // 求最小覆盖字串并打印  
    printf("\"%s\"\n", minWindow(S, T));  
  
    return 0;  
}  
  
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */  