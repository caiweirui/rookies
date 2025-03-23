/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */  
 
#include <stdio.h>  
#include <string.h>  
  
/** 
 * @param arr int整型一维数组 the array 
 * @param arrLen int arr数组长度 
 * @return int整型 
 */  
  
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */

int maxLength(int *arr, int arrlen){
	int i=0, j=0, max=0, count=0, k=0, flag=0;
	for(i=0; i<arrlen; i++){
		for(j=i+1, count=1; j<arrlen; j++){
			for(k=i, flag=0; k<j; k++){
				if(arr[j]==arr[k]){
					flag=1;
					continue;
				}
			}
			if(flag){
				continue;
			}
			count++;
			
			if(max<count){
				max=count;
			}
		}
	}
	return max;
}
/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */  
  
int main() {  
    char input[100000];  
    int arr[100000], arrLen = 0;  
      
    // 读入字符串数组  
    scanf("%s", input);  
    // 逐个提取数字并存储到数组中  
    char *token = strtok(input, "[],");  
    while (token != NULL) {  
        sscanf(token, "%d", &arr[arrLen++]);  
        token = strtok(NULL, "[],");  
    }  
      
    // 计算最长无重复子数组并打印  
    printf("%d\n", maxLength(arr, arrLen));  
  
    return 0;  
}  
  
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */   