#include<stdio.h>
#include<string.h>

// int main()
// {
//     int i=0;
//     for(i=1;i<=100;i++)
//     {
//         if(i%2==1)
//         {
//             printf("%d ",i);
//         }
//     }
//     return 0;
// }

// int main()
// {
//     int m = 2;
//     int n = 1;
//     switch (n)
//     {
//     case 1: m++;
//     case 2: n++;
//     case 3: 
//         switch (n)
//         {
//             case 1: n++;
//             case 2: m++;n++;
//             break;
//         }
//     case 4: m++; break;
//     default:
//         break;
//     }
//     printf("m = %d n = %d",m,n);
//     return 0;
// }


int main()
{
    char ch[1000]={0};
    int i=0;
    gets(ch);
    while( i < strlen(ch))
    {
        //判断是否为二位数或者三位数
        if(ch[i+1]!=',' && (i+1)<strlen(ch))
        {
            //判断是否为三位数
            if (ch[i+2]!= ',' && (i+2)<strlen(ch))
            {
                printf("%c",((ch[i]-'0')*100+(ch[i+1]-'0')*10+(ch[i+2]-'0')));
                i+=3;
            }
            else
            {
                //判断是否为二位数
                printf("%c",((ch[i]-'0')*10+(ch[i+1]-'0')));
                i+=2;
            }
        }
        else
        {
            //一位数的情况直接输出数字对应的字符
            printf("%c",(ch[i]-'0'));
            i+=1;
        }
        if (ch[i] == ',') 
        {
            i++;
        }
    }
    return 0;
}
