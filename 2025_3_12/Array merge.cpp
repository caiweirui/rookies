/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */  
 
#include <stdio.h>  
#include <string.h>  
  
/** 
 * @param A int整型一维数组 
 * @param m int A数组长度 
 * @param B int整型一维数组 
 * @param n int B数组长度 
 * @return void 
 */  
  
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */  

void merge(int *A, int m, int *B, int n){
	int i=0, j=0;
	int temp;
	for(i=0; i<n; i++){
		A[m+i]=B[i];
	}
	for(i=0; i<m+n-1; i++){
		for(j=0; j<m+n-1; j++){
			if(A[j]>A[j+1]){
				temp=A[j];
				A[j]=A[j+1];
				A[j+1]=temp;
			}
		}
	}
}
/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */  

int main() {  
    char input[100];  
    int A[100], B[100], m = 0, n=0;  
      
    // 读入第一个字符串数组  
    scanf("%s", input);  
    // 逐个提取数字并存储到数组A中  
    char *tokenA = strtok(input, "[],");  
    while (tokenA != NULL) {  
        sscanf(tokenA, "%d", &A[m++]);  
        tokenA = strtok(NULL, "[],");  
    }  
      
    // 读入第二个字符串数组  
    scanf("%s", input);  
    // 逐个提取数字并存储到数组B中  
    char *tokenB = strtok(input, "[],");  
    while (tokenB != NULL) {  
        sscanf(tokenB, "%d", &B[n++]);  
        tokenB = strtok(NULL, "[],");  
    }  
      
    // 合并数组B到数组A中  
    merge(A, m, B, n);  
      
    // 打印数组A  
    printf("[");  
    int i;  
    for(i = 0; i < m+n-1; i++)  
      printf("%d,", A[i]);  
    printf("%d]\n", A[i]);  
  
    return 0;  
}  
  
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */  