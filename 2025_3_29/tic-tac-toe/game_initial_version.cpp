//一共四个功能
//1. 打印可输入数据的棋盘
//2. 玩家下棋
//3. 电脑下棋
//4. 判断输赢

#include "game.h"
//#include<stdio.h>


//初始化棋盘
void initial_board(char board[ROW][COL], int row, int col)
{
    int i = 0, j = 0;
    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            board[i][j] = ' ';
        }
    }
}

//打印棋盘
void display_board(char board[ROW][COL], int row, int col)
{
    int i = 0, j = 0;
    //打印列序号
    printf("   ");
    for(i = 0; i < col; i++)
    {
        printf("| %-2d", i+1);
    }
    printf("|\n");
    printf("---");
    for(i = 0; i < col; i++)
    {
        printf("|---", i+1);
    }
    printf("|\n");
    //打印行
    for (i = 0; i < row; i++)
    {
        printf(" %-2d|", i+1);
        //打印数组的列
        for(j = 0; j < col; j++)
        {
            printf(" %c ", board[i][j]);
            if(j < col )
            {
                printf("|");
            }
        }
        printf("\n");
        //打印分割行
        for(j = 0; j <= col; j++)
        {
            printf("---");
            if(j < col)
            {
                printf("|");
            }
        }
        printf("|\n");
    }
}

//玩家下棋
void player_move(char board[ROW][COL], int row, int col ,int *flaginput)
{
    int x = 0;
    int y = 0;
    int correct = 0;
    //三种可能结束函数
    //1. 正确的输入
    //2. 多次越界输入
    //3. 多次重复输入
    scanf("%d %d", &x, &y);
    do
    {
        *flaginput = 0;
        //判断横坐标和纵坐标是否合法
        while(1)
        {
            if(x < 1 || x > row || y < 1 || y > col)
            {
                //判断是否多次输入错误
                (*flaginput)++;
                if(*flaginput <= 3)
                {
                    printf("\n王子公主殿下您输错了，请重新输入：");
                    scanf("%d %d", &x, &y);
                }
                else
                {
                    //情况2：多次越界输入，跳出循环，结束函数
                    correct = 1;
                    break;
                }
            } 
            else
            {
                break;
            }     
        }
        //在数组没有越界的情况下，判断下的位置是否被占据
        if(*flaginput <= 3)
        {
            *flaginput = 0;
            while(1)
            {
                if (board[x-1][y-1] == ' ')
                {
                    //情况2：正确输入，跳出循环，结束函数
                    board[x-1][y-1] = '*';
                    correct = 1;
                    break;
                }
                else
                {
                    (*flaginput)++;
                    if(*flaginput <= 3)
                    {
                        printf("\n王子公主殿下您输入地方已经被占了，请重新输入：");
                        scanf("%d %d", &x, &y);
                    }
                    else
                    {
                        //情况3：多次重复输入，跳出循环，结束函数
                        correct = 1;
                        break;
                    }
                }
            }
        }
    }while(!correct);
}

//电脑自己获胜的情况
int computer_winner(char board[ROW][COL], int row, int col, int *x, int *y);

//阻止玩家胜利的情况
int block_player(char board[ROW][COL], int row, int col, int *x, int *y);

//占据中心的情况
int center_blank(char board[ROW][COL], int *x, int *y);

//电脑下棋
void computer_move(char board[ROW][COL], int row, int col)
{
    int x = 0, y = 0;
    int flag = 0;
    int cw = computer_winner(board, row, col, &x, &y);
    if(cw)
    {
        board[x][y] = '#';
        flag = 1;
    }
    else
    {
        int bp = block_player(board, row, col, &x, &y);
        if(bp)
        {
            board[x][y] = '#';
            flag = 1;
        }
        else
        {
            int cb = center_blank(board, &x, &y);
            if(cb)
            {
                board[x][y] = '#';
                flag = 1;
            }
        }
    }
    while(!flag)
    {
        x = rand() % row;
        y = rand() % col;
        if(board[x][y] == ' ')
        {
            board[x][y] = '#';
            break;
        }
    }
}

//获胜条件
//玩家获胜
int player_win(char board[ROW][COL], int row, int col);

//电脑获胜
int computer_win(char board[ROW][COL], int row, int col);

//判断结果
void who_win(char board[ROW][COL], int row, int col, int *flagwin)
{
    int i = 0, j = 0, countblank = 0;
    int pw = player_win(board, row, col);
    int cw = computer_win(board, row, col);
    if(pw)
    {
        printf("\n公主王子殿下太棒了！\n\n\n");
        *flagwin = 1;
    }
    else if(cw)
    {
        printf("\n回家吧，孩子，回家吧，这个游戏不适合你。\n\n\n");
        *flagwin = 1;
    }
    else
    {
        for(i = 0; i < row; i++)
        {
            for(j = 0; j < col; j++)
            {
                if(board[i][j] == ' ')
                {
                    countblank++;
                }
            }
        }
        if(countblank == 0)
        {
            printf("\n平局了孩子。\n\n\n");
            *flagwin = 1;
        }
    }


}

void game()
{
    int row = ROW;
    int col = COL;
    int flaginput = 0;
    int flagwin = 0;
    char board[ROW][COL] = {0};
    //初始化棋盘
    initial_board(board, row, col);
    //打印棋盘
    display_board(board, row, col);
    //下棋
    printf("\n王子公主请下棋：\n");
    printf("输入行数和列数，示例：1 1，即下在第1行第1列\n");
    while(!flagwin)
    {
        //玩家下棋
        printf("\n你的回合！请输入：");
        player_move(board, row, col, &flaginput);

        //多次坐标输入错误
        if(flaginput > 3)
        {
            printf("\n回家吧，孩子，回家吧，这个游戏不适合你。\n\n\n");
            break;
        }
        //输出棋盘
        display_board(board, row, col);

        //判断胜利
        who_win(board, row, col, &flagwin);

        //避免平局或刚好填满获胜后，电脑进入死循环
        if(!flagwin)
            {
            //电脑下棋
            printf("\n电脑的回合，请稍后。\n");
            sleep(2);
            computer_move(board, row, col);
            display_board(board, row, col);
            who_win(board, row, col, &flagwin);
        }
    }
    

}

int main()
{
    //菜单
    // printf("Would you like to play the tic-tac-toe?\n");
    // printf("If you'd like to play, please input 1.\n");
    // printf("If not, input 0.\n");
    // printf("Input your choice:");
    int countinput = 0;
    printf("\n\n王子公主想要玩三子棋吗？\n");
    printf("输入1进行游戏，输入0退出游戏:");
    int flag = 0;
    do
    {
        scanf("%d", &flag);
        if(1 == flag || 0 == flag)
        {
            break;
        }
        else
        {
            countinput++;
            if(countinput<=3)
            printf("\n<'_'>?再试一次吧？");
            else
            {
                printf("\n回家吧，孩子，这个游戏不适合你。\n\n\n");
                break;
            }
        }
    }while(1);
    printf("\n\n");

    //生成随机数
    srand((unsigned int)time(NULL));

    //是否继续游戏
    while(1 == flag)
    {
        game();
        printf("\n公主王子还想继续吗？\n");
        printf("输入1再来一把，输入0退出游戏：");
        int reinput = 0;
        int reflag = 0;
        for(reflag = 0; reflag < 3; reflag++)
        {
            scanf("%d", &reinput);
            if(1 == reinput)
            {
                printf("\n尊敬的公主王子殿下，您选择了再来一把\n\n\n");
                break;
            }
            else if(0 == reinput)
            {
                printf("退出游戏。\n");
                flag =0;
                break;
            }
            else
            {
                printf("\n<'_'>?再试一次吧？\n");
            }
        }
        if(reflag ==3)
        {
            printf("\n回家吧，孩子，这个游戏不适合你。\n\n\n");
            break;
        }
        
    }
    return 0;
}

//电脑自己获胜的情况
int computer_winner(char board[ROW][COL], int row, int col, int *x, int *y)
{
    int i = 0;
    //检查所有的行
    for(i = 0; i < row ; i++)
    {
        if(board[i][0] == '#' && board [i][1] == '#' && board[i][2] == ' ')
        {
            *x = i;
            *y = 2;
            return 1;
        }
        if(board[i][0] == '#' && board [i][2] == '#' && board[i][1] == ' ')
        {
            *x = i;
            *y = 1;
            return 1;
        }
        if (board[i][1] == '#' && board [i][2] == '#' && board[i][0] == ' ')
        {
            *x = i;
            *y = 1;
            return 1;
        }
    }
    //检查所有的列
    for(i = 0; i < col; i++)
    {
        if(board[0][i] == '#' && board [1][i] == '#' && board[2][i] == ' ')
        {
            *x = 2;
            *y = i;
            return 1;
        }
        if(board[0][i] == '#' && board [2][i] == '#' && board[1][i] == ' ')
        {
            *x = 1;
            *y = i;
            return 1;
        }
        if(board[2][i] == '#' && board [1][i] == '#' && board[0][i] == ' ')
        {
            *x = 0;
            *y = i;
            return 1;
        }
    }
    //检查对角线
    //检查左上到右下
    if(board[0][0] == '#' && board [1][1] == '#' && board[2][2] == ' ')
    {
        *x = 2;
        *y = 2;
        return 1;
    }
    if(board[0][0] == '#' && board [2][2] == '#' && board[1][1] == ' ')
    {
        *x = 1;
        *y = 1;
        return 1;
    }
    if(board[2][2] == '#' && board [1][1] == '#' && board[0][0] == ' ')
    {
        *x = 0;
        *y = 0;
        return 1;
    }
    //检查右上到左下
    if(board[2][0] == '#' && board [1][1] == '#' && board[0][2] == ' ')
    {
        *x = 0;
        *y = 2;
        return 1;
    }
    if(board[2][0] == '#' && board [0][2] == '#' && board[1][1] == ' ')
    {
        *x = 1;
        *y = 1;
        return 1;
    }
    if(board[0][2] == '#' && board [1][1] == '#' && board[2][0] == ' ')
    {
        *x = 2;
        *y = 0;
        return 1;
    }
    return 0;
}

//阻止玩家获胜的情况
int block_player(char board[ROW][COL], int row, int col, int *x, int *y)
{
    int i = 0;
    //检查所有的行
    for(i = 0; i < row ; i++)
    {
        if(board[i][0] == '*' && board [i][1] == '*' && board[i][2] == ' ')
        {
            *x = i;
            *y = 2;
            return 1;
        }
        if(board[i][0] == '*' && board [i][2] == '*' && board[i][1] == ' ')
        {
            *x = i;
            *y = 1;
            return 1;
        }
        if (board[i][1] == '*' && board [i][2] == '*' && board[i][0] == ' ')
        {
            *x = i;
            *y = 1;
            return 1;
        }
    }
    //检查所有的列
    for(i = 0; i < col; i++)
    {
        if(board[0][i] == '*' && board [1][i] == '*' && board[2][i] == ' ')
        {
            *x = 2;
            *y = i;
            return 1;
        }
        if(board[0][i] == '*' && board [2][i] == '*' && board[1][i] == ' ')
        {
            *x = 1;
            *y = i;
            return 1;
        }
        if(board[2][i] == '*' && board [1][i] == '*' && board[0][i] == ' ')
        {
            *x = 0;
            *y = i;
            return 1;
        }
    }
    //检查对角线
    //检查左上到右下
    if(board[0][0] == '*' && board [1][1] == '*' && board[2][2] == ' ')
    {
        *x = 2;
        *y = 2;
        return 1;
    }
    if(board[0][0] == '*' && board [2][2] == '*' && board[1][1] == ' ')
    {
        *x = 1;
        *y = 1;
        return 1;
    }
    if(board[2][2] == '*' && board [1][1] == '*' && board[0][0] == ' ')
    {
        *x = 0;
        *y = 0;
        return 1;
    }
    //检查右上到左下
    if(board[2][0] == '*' && board [1][1] == '*' && board[0][2] == ' ')
    {
        *x = 0;
        *y = 2;
        return 1;
    }
    if(board[2][0] == '*' && board [0][2] == '*' && board[1][1] == ' ')
    {
        *x = 1;
        *y = 1;
        return 1;
    }
    if(board[0][2] == '*' && board [1][1] == '*' && board[2][0] == ' ')
    {
        *x = 2;
        *y = 0;
        return 1;
    }
    return 0;
}   

//下在中心点的情况
int center_blank(char board[ROW][COL], int *x, int *y)
{
    if(board[1][1] == ' ')
    {
        *x = 1;
        *y = 1;
        return 1;
    }
    return 0;
}

int player_win(char board[ROW][COL], int row, int col)
{
    int i = 0;
    //检查所有的行
    for(i = 0; i < row ; i++)
    {
        if(board[i][0] == '*' && board [i][1] == '*' && board[i][2] == '*')
        {
            return 1;
        }
    }
    //检查所有的列
    for(i = 0; i < col; i++)
    {
        if(board[0][i] == '*' && board [1][i] == '*' && board[2][i] == '*')
        {
            return 1;
        }
    }
    //检查对角线
    //检查左上到右下
    if(board[0][0] == '*' && board [1][1] == '*' && board[2][2] == '*')
    {
        return 1;
    }
    //检查右上到左下
    if(board[2][0] == '*' && board [1][1] == '*' && board[0][2] == '*')
    {
        return 1;
    }
    return 0;
}

int computer_win(char board[ROW][COL], int row, int col)
{
    int i = 0;
    //检查所有的行
    for(i = 0; i < row ; i++)
    {
        if(board[i][0] == '#' && board [i][1] == '#' && board[i][2] == '#')
        {
            return 1;
        }
    }
    //检查所有的列
    for(i = 0; i < col; i++)
    {
        if(board[0][i] == '#' && board [1][i] == '#' && board[2][i] == '#')
        {
            return 1;
        }
    }
    //检查对角线
    //检查左上到右下
    if(board[0][0] == '#' && board [1][1] == '#' && board[2][2] == '#')
    {
        return 1;
    }
    //检查右上到左下
    if(board[2][0] == '#' && board [1][1] == '#' && board[0][2] == '#')
    {
        return 1;
    }
    return 0;
}