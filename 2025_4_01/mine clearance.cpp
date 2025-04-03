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
    int i = 0;
    int j = 0;
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
    //循环省事流盘查上下左右
    for(i = -1; i <= 1 ; i++)
    {
        for(j = -1; j <= 1; j++)
        {
            if(mine[x + i][y + j] == '1' && (i != 0 || j != 0))
            {
                show[x][y]++;
            }
        }
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
    int countinput = 0;
    int x = 0, y = 0;
    int markflag = 0;
    printf("\n公主王子殿下是否需要标记雷呢？输入1开始标记功能，输入0继续排查：");
    while(!markflag)
    {
        scanf("%d", &input);
        if(1 == input)
        {
            printf("\n公主王子请输入要标记的地方，举例：输入 1 1 为标记第1行第1列。被标记的地方会显示为\"F\"\n");
            while(1)
            {
                printf("\n公主王子请输入：");
                scanf("%d %d", &x, &y);
                printf("\n");
                if(x >= 1 || x <= ROW || y >= 1 || y <= COL)
                {
                    if(mine[x][y] == '2')
                    {
                        printf("\n公主王子殿下，这个位置已经没有雷了，换个地方标记吧！\n");
                    }
                    else
                    {
                        show[x][y] = 'F';
                        displayboard(show, row, col);
                        printf("\n公主王子殿下是否还要继续标记呢？输入1继续标记，输入0结束标记。");
                        scanf("%d", &input);
                        if(1 == input)
                        {
                            printf("\n请继续标记！\n");
                        }
                        else if(0 == input)
                        {
                            printf("\n结束标记，继续排雷。\n");
                            markflag = 1;
                            break;
                        }
                    }
                }
                else
                {   
                    printf("\n输入错误，请重新输入：");
                }
            }
        }
        else if(0 == input)
        {
            printf("\n不进行标记，继续扫雷。\n");
            break;
        }
        else
        {
            printf("\n输入错误，请重新输入: \n");
        }
    }
}

//排查雷
void findmine(char mine[ROW + 2][COL + 2], char show[ROW + 2][COL + 2],int row, int col, int minecount)
{
    int countinput = 0;
    int winflag = 0;
    printf("\n公主王子请输入要排查的地方，举例：输入 1 1 为排查第1行第1列.\n");
    countinput = 0;
    while(!winflag)
    {
        int x = 0;
        int y = 0;
        printf("\n\n公主王子请输入：");
        while(1)
        {
            scanf("%d %d", &x, &y);
            if(x > ROW || y > COL || x < 1 || y < 1 )
            {
                countinput++;
                if(countinput <= 3)
                {
                    printf("\n输入错误，请重新输入：");
                }
                else
                {
                    printf("\n孩子，你无敌了！\n请重新输入：");
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
                printf("\n公主王子殿下太棒了！\n");
                displayboard(show, row, col);
                break;
            }
            displayboard(show, row, col);
        }
        else if(mine[x][y] == '1')
        {
            //排到雷了
            countinput = 0;
            printf("\nboom!\n太好了，是地雷，我们没救了！游戏结束\n\n");
            show[x][y] = '*';
            displayboard(show, row, col);
            break;
        }
        else
        {
            //重复输入
            printf("\n公主王子殿下，这个位置已经被排查过了，去探索后面的区域吧！\n");
            //scanf("%d %d", &x, &y);
            printf("\n\n");
            countinput++;
            if(countinput >=3 )
            {
                printf("你无敌了，孩子！\n\n");
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
        printf("\n公主王子请输入地雷的数量，输入 0 ~ 40 的数字：");
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
        printf("\n公主王子还想要再来一把吗？输入1继续游戏，输入0退出游戏：");
        scanf("%d", &reinput);
        while(1) 
        {
            printf("\n\n");
            if(1 == reinput)
            {
                printf("公主王子殿下，您选择了再来一把！\n\n");
                break;
            }
            else if(0 == reinput)
            {
                printf("小美女小帅哥下次来玩吧。\n\n");
                break;
            }
            else
            {
                printf("\n输入错误，八嘎！\n");
                printf("尊敬的公主王子请重新输入:");
                scanf("%d", &reinput);
                countinput++;
                if(countinput>=3)
                {
                    printf("\n\n孩子，你无敌了！\n\n");
                    flaginput = 1;
                    break;
                }
            }
        }     
    }
}

int main()
{
    printf("公主王子想要玩扫雷游戏吗？\n");
    printf("输入1开始游戏，输入0退出游戏: ");
    int menuinput = 0;
    int menuinputworry = 0;
    scanf("%d", &menuinput);
    printf("\n");

    while(1)
    {
        if(1 == menuinput)
        {
            printf("\n尊敬的王子公主殿下，请开始游戏：\n\n");
            break;
        }
        else if(0 == menuinput)
        {
            printf("小美女小帅哥下次来玩吧。\n\n");
            break;
        }
        else
        {
            while(1)
            {
                printf("\n输入错误，八嘎！\n");
                printf("尊敬的公主王子请重新输入:");
                scanf("%d", &menuinput);
                menuinputworry++;
                if(menuinputworry>=3)
                {
                    printf("\n\n孩子，你无敌了！\n\n");
                    break;
                }
            }
            if(menuinputworry>=3)
            {
                printf("\n\n孩子，你无敌了！\n\n");
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