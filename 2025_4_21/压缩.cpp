
    #include<stdio.h>  
    #include<string.h>  
    int main(){  
        int word=0,i=0,j=0,k=0,flag=1,m=0;  
        char s[500],words[10000][100],a[500];  
        for(i=0;i<10000;i++)  
           for(j=0;j<100;j++)  
              words[i][j]='\0';  
        while(gets(a) != NULL){//得到一行  
            if('\0'==a[0]){printf("\n");continue;}//只有一个换行符，那就换行  
            //有意义的一行，初始化  
            for(i=0;a[i]!='\0';i++)s[i+1]=a[i];
            s[0]='.';s[i+1]='\0';k=0; i=1; 
            while(s[i]!='\0'){//依次处理每个字符  
               if((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z')){  
                   //这是一个字母  
                   if(!((s[i-1]>='a' && s[i-1]<='z')||(s[i-1]>='A' && s[i-1]<='Z'))){
					   word++;k=0;words[word][k++]=s[i];}//这是一个单词的开头   
                   else{words[word][k++]=s[i]; }//把这个字母放好了，干点儿别的
				   if(!((s[i+1]>='a' && s[i+1]<='z')||(s[i+1]>='A' && s[i+1]<='Z'))){ //单词结束就审判 
                       words[word][k]='\0';  
                       flag=1;  
                       for(j=1;j<word;j++){  
                           if(!strcmp(words[j],words[word])){  
                               printf("%d",j);  
                               for(m=0;m<100;m++){words[word][m]='\0';} 
                               word--;   
                               flag=0;  
                               break;  
                            }  
                        }  
                        if(flag){printf("%s",words[word]);}}   
               }else{  
                   putchar(s[i]);  
               }i++;  }
            printf("\n"); 
            }    
        return 0;  
    }