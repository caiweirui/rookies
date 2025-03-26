/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */  
 
#include <stdio.h>  
#include <string.h>  
  
/** 
 * @param arr int整型一维数组 the array 
 * @param arrLen int arr数组长度 
 * @return long长整型 
 */  
  
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */  

long long min(long long a, long long b){
	if(a>b){
		return b;
	}
	else{
		return a;
	}
}

long long maxWater(int* arr, int arrlen){
	long long i=0, j=0, k=0, maxleft=0, maxright=0;
	//int flagleft=0, flagright=0, flagleft2=0, flagright2=0;
	long long count=0;
	long long minheight=0, result=0;
	for(i=1; i<arrlen-1; i++){
		for(j=0, maxleft=0; j<i; j++){
			//左高点
			if(arr[j]>maxleft){
				maxleft=arr[j];
			}
		}
		for(k=i+1, maxright=0; k<arrlen; k++){
			//右高点
			if(arr[k]>maxright){
				maxright=arr[k];
			}
		}
		//
		minheight=min(maxleft, maxright);
		if(minheight<arr[i]){
			continue;
		}
		else{
			result=result+minheight-arr[i];
		}
	}
	return result;
}


/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */  
  
int main() {  
    char input[400000];  
    int arr[200000], arrLen = 0;  
      
    // 读入字符串数组  
    scanf("%s", input);  
    // 逐个提取数字并存储到数组中  
    char *token = strtok(input, "[],");  
    while (token != NULL) {  
        sscanf(token, "%d", &arr[arrLen++]);  
        token = strtok(NULL, "[],");  
    }  
      
    // 计算接到雨水的最大量并打印  
    printf("%d\n", maxWater(arr, arrLen));  
  
    return 0;  
}  
  
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */  