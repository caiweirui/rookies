#include<stdio.h>
int main(){
    int hz[51]={0};int i=0,n=0,re=0,j=0;
    for(i=1;i<51;i++){
        hz[i]=0;
    }
    scanf("%d %d",&re,&n);
    for(i=1;i<=re;i++){
        hz[i]=1;
    }
    i=1;j=0;
    for(i=1,j=0;1;i++){
        if(i==51){i=1;}
        if(hz[i]){
            j++;
        }
        if(j==n){
            hz[i]=0;
            re--;
            j=0;
        }
        if(1==re){
            break;
        }
    }
    for(i=1;i<51;i++){
        if(hz[i]){
            break;
        }
    }
    printf("The left child is NO %d.\n",i);
    return 0;
}
