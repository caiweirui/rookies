//扫雷游戏
//1 .初始化棋盘char mine[11][11]，是雷放1，不是雷放0，初始化为'0'
//2. 拷贝棋盘char show[11][11]，用于存放排查出的雷的信息，初始化为*
//3. 判断周围8颗雷需要判断是否越界，解决方法，拓展棋盘，变为11*11的棋盘
//4. 每次排除一点，对应的点如果不是雷，就显示周围8格的雷的数量，如果是雷，游戏结束
//5. 获胜条件，排除所有的雷

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 9
#define COL 9

//初始化地雷棋盘
void initmine(char mine[ROW + 2][COL + 2], int row, int col, int minecount)
{
    int i = 0;
    int j = 0;
    //先全部初始化变成'0'
    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            mine[i][j] = '0';
        }
    }
    int count = 0;
    //在展示的区域放雷
    while(count < minecount)
    {
        //雷的有效范围是1-ROW和1-COL
        int x = 1 + rand() % ROW;
        int y = 1 + rand() % COL;
        if(mine[x][y] == '0')
        {
            mine[x][y] = '1';
            count++;
        }
    }
}

//初始化展示棋盘
void initshow(char show[ROW + 2][COL + 2], int row, int col)
{
    int i = 0;
    int j = 0;
    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            show[i][j] = ' ';
        }
    }
}

//打印棋盘，只需要打印行号，列好和1-ROW行，1-COL列的数据就可以了
void displayboard(char arr[ROW + 2][COL + 2], int row, int col)
{
    int i = 0;
    int j = 0;
    for(i = 0; i < row - 1; i++)
    {
        //第一行数字行
        if(0 == i)
        {
            printf("   |");
            for(j = 0; j < col - 2; j++)
            {
                printf(" %-2d|", j + 1);
            }
            printf("\n");
            for(j = 0; j < col - 1; j++)
            {
                printf("---|");
            }
            printf("\n");
        }
        //后面的行
        else
        {
            //第一列数字列
            printf(" %-2d|", i);
            //每一行的1-ROW列
            for(j = 1; j < col - 1; j++)
            {
                printf(" %c |", arr[i][j]);
            }
            printf("\n");
            for(j = 0; j < col - 1; j++)
            {
                printf("---|");
            }
            printf("\n");
        }
    }
}

//周围雷的数量
void minecountaround(char mine[ROW + 2][COL + 2], char show[ROW + 2][COL + 2], int x, int y)
{
    //终止条件1：超出有效区域（假设有效区域为1~ROW, 1~COL）
    if (x < 1 || x > ROW || y < 1 || y > COL) {
        return;
    }
    // 终止条件2：该位置已处理过
    if (mine[x][y] == '2') {
        return;
    }
    mine[x][y] = '2';
    show[x][y] = '0';
    if(mine[x - 1][y] == '1')
    {
        show[x][y]++;
    }
    if(mine[x - 1][y + 1] == '1')
    {
        show[x][y]++;
    }
    if(mine[x - 1][y - 1] == '1')
    {
        show[x][y]++;
    }
    if(mine[x][y - 1] == '1')
    {
        show[x][y]++;
    }
    if(mine[x][y + 1] == '1')
    {
        show[x][y]++;
    }
    if(mine[x + 1][y] == '1')
    {
        show[x][y]++;
    }
    if(mine[x + 1][y + 1] == '1')
    {
        show[x][y]++;
    }
    if(mine[x + 1][y - 1] == '1')
    {
        show[x][y]++;
    }
    //当该点周围没有雷时，拓展到周围8格，并将地雷棋盘的对应格变成2
    if (show[x][y] == '0') {
        minecountaround(mine, show, x+1, y+1);
        minecountaround(mine, show, x+1, y);
        minecountaround(mine, show, x+1, y-1);
        minecountaround(mine, show, x, y+1);
        minecountaround(mine, show, x, y-1);
        minecountaround(mine, show, x-1, y+1);
        minecountaround(mine, show, x-1, y);
        minecountaround(mine, show, x-1, y-1);
    }
}

//判断是否获胜
void iswin(char mine[ROW + 2][COL + 2], int *winflag, int minecount)
{
    int i = 0;
    int j = 0;
    int explorecount = 0;
    for(i = 1; i <= ROW; i++)
    {
        for(j = 1; j <= COL; j++)
        {
            if('2' == mine[i][j])
            {
                explorecount++;
            }
        }
    }
    //已经排除的地区数量=总地区数-雷的数量时，游戏胜利！
    if(ROW*COL - minecount == explorecount)
    {
        *winflag = 1;
    } 
}

//标记雷
void marklandmine(char mine[ROW + 2][COL + 2], char show[ROW + 2][COL + 2], int row, int col)
{
    int input;
    int x = 0, y = 0;
    int markflag = 0;
    printf("\nDoes Princess and Prince need to mark landmines? \nEnter 1 to start the tagging function, enter 0 to continue troubleshooting:");
    while(!markflag)
    {
        scanf("%d", &input);
        if(1 == input)
        {
            printf("\nPrincess Prince, please enter the place to be marked. \nFor example, enter 1 1 to mark the first row and column. The marked area will be displayed as \"F\".'\n");
            while(1)
            {
                printf("\nPrincess and Prince, please enter:");
                scanf("%d %d", &x, &y);
                printf("\n");
                if(x >= 1 || x <= ROW || y >= 1 || y <= COL)
                {
                    if(mine[x][y] == '2')
                    {
                        printf("\nPrincess and Prince, there is no more thunder in this position. Let's mark it in a different location!\n");
                    }
                    else
                    {
                        show[x][y] = 'F';
                        displayboard(show, row, col);
                        printf("\nDoes Princess and Prince still need to continue marking? \nEnter 1 to continue marking, enter 0 to end marking.");
                        scanf("%d", &input);
                        if(1 == input)
                        {
                            printf("\nPlease continue to mark!\n");
                        }
                        else if(0 == input)
                        {
                            printf("\nEnd marking, continue with mine clearance.\n");
                            markflag = 1;
                            break;
                        }
                    }
                }
                else
                {   
                    printf("\nInput error, please re-enter:");
                }
            }
        }
        else if(0 == input)
        {
            printf("\nDo not mark, continue to mine.\n");
            break;

        }
        else
        {
            printf("\nInput error, please re-enter: \n");
        }
    }
}

//排查雷
void findmine(char mine[ROW + 2][COL + 2], char show[ROW + 2][COL + 2],int row, int col, int minecount)
{
    int countinput = 0;
    int winflag = 0;
    printf("\nDear Princess and Prince, please enter the location to be investigated. \nFor example, enter 1 1 to investigate the first row and column.\n");
    countinput = 0;
    while(!winflag)
    {
        int x = 0;
        int y = 0;
        printf("\n\nPrincess and Prince, please enter:");
        while(1)
        {
            scanf("%d %d", &x, &y);
            if(x > ROW || y > COL || x < 1 || y < 1 )
            {
                countinput++;
                if(countinput <= 3)
                {
                    printf("\nInput error, please re-enter:");
                }
                else
                {
                    printf("\nChild, you are invincible! Please re-enter:");
                }
            }
            else
            {
                break;
            }
        }
        printf("\n\n");
        //判断，有雷爆炸，无雷显示，重复重现输入
        if(mine[x][y] == '0')
        {
            countinput = 0;
            //显示数字
            minecountaround(mine, show, x, y);
            //判断胜利是否胜利
            iswin(mine, &winflag, minecount);
            if(1 == winflag)
            {
                printf("\nPrincess and Prince perform incredibly！\n");
            }
            displayboard(show, row, col);
        }
        else if(mine[x][y] == '1')
        {
            countinput = 0;
            printf("\nboom!\nGreat, it's a landmine, we're hopeless! game over.\n\n");
            show[x][y] = '*';
            displayboard(show, row, col);
            break;
        }
        else
        {
            printf("\nMy dear Princess and Prince, this location has been investigated. Go explore the area behind it!\n");
            //scanf("%d %d", &x, &y);
            printf("\n\n");
            countinput++;
            if(countinput >=3 )
            {
                printf("You are invincible, child!\n\n");
                break;
            }
        }
        //标记雷
        marklandmine(mine, show, row, col);
    }
}

void game()
{
    int minecount = 0;
    char mine[ROW + 2][COL + 2] = {'0'};
    char show[ROW + 2][COL + 2] = {'0'};
    int row = ROW + 2;
    int col = COL + 2;
    int reinput = 0;
    int countinput = 0;
    int flaginput = 0;

    //多次游戏
    while(!flaginput)
    {
        printf("\nPrincess and Prince, please enter the number of landmines, ranging from 0 to 40:");
        scanf("%d", &minecount);
        printf("\n\n");
        //初始化地雷棋盘和展示棋盘
        initmine(mine, row, col, minecount);
        initshow(show, row, col);
        //displayboard(mine, row, col);
        //每次输出为展示棋盘
        displayboard(show, row, col);
        //排查雷
        findmine(mine, show, row, col, minecount);
        printf("\nDoes the princess and prince want another one? Enter 1 to continue the game, enter 0 to exit the game:");
        scanf("%d", &reinput);
        while(1) 
        {
            printf("\n\n");
            if(1 == reinput)
            {
                printf("My dear Princess and Prince, you have chosen to give it another try!\n\n");
                break;
            }
            else if(0 == reinput)
            {
                printf("Come and play next time, little beauty and handsome guy.\n\n");
                break;
            }
            else
            {
                printf("\nInput error, Baga!\n");
                printf("Dear Princess and Prince, please re-enter:");
                scanf("%d", &reinput);
                countinput++;
                if(countinput>=3)
                {
                    printf("You are invincible, child!\n\n");
                    flaginput = 1;
                    break;
                }
            }
        }     
        
    }

}

int main()
{
    printf("Does the princess and prince want to play Minesweeper?\n");
    printf("Enter 1 to start the game, enter 0 to exit the game:");
    int menuinput = 0;
    int menuinputworry = 0;
    scanf("%d", &menuinput);
    while(1)
    {
        if(1 == menuinput)
        {
            printf("\n\nDear Prince Royal Highness Princess, please start the game:\n\n");
            break;
        }
        else if(0 == menuinput)
        {
            printf("\n\nCome and play next time, little beauty and handsome guy.\n\n");
            break;
        }
        else
        {
            while(1)
            {
                printf("\n\nInput error, Baga!\n");
                printf("Dear Princess and Prince, please re-enter:");
                scanf("%d", &menuinput);
                menuinputworry++;
                if(menuinputworry>=3)
                {
                    break;
                }
            }
            if(menuinputworry>=3)
            {
                printf("\n\nYou are invincible, child!\n\n");
                break;
            }
        }
    }
    
    srand((unsigned int)time(NULL));

    if(1 == menuinput)
    {
        game();
    }
    return 0;
}