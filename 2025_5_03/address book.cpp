#include<bits/stdc++.h>

// 实现一个通讯录
// 人的信息：名字，年龄，性别，电话，地址
// 功能:    1. 存放100人的信息
//         2. 增删改查联系人
//         3. 排序
//         4. 显示
//

#define MAX 100
#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TELE 12
#define MAX_ADDR 100
#define DEFAULT_SIZE 3
#define DEFAULT_ADD 2

enum Options
{
    EXIT,
    ADD,
    DEL,
    SEARCH,
    MODIFY,
    SHOW,
    SORT,
};

// 头文件应该包括结构体
// 人的信息
typedef struct PeoInfo
{
    char name[MAX_NAME];      // 名字
    int age;            // 年龄
    char sex[MAX_SEX];        // 性别
    char tele[MAX_TELE];      // 电话
    char addr[MAX_ADDR];     // 地址
}PeoInfo;

// 通讯录静态版本
// typedef struct Contact
// {
//     PeoInfo data[MAX];  // 存放人的信息
//     int DataCount;  // 通讯录人的个数
// }Contact;

// 通讯录动态版本
typedef struct Contact
{
    PeoInfo* data;  // 存放人的信息
    int DataCount;  // 通讯录人的个数
    int capacity; // 内存容量
}Contact;

// 菜单
void menu()
{
    printf("对通讯录可进行如下操作：\n");
    printf("增加联系人：输入1\n");
    printf("删除联系人：输入2\n");
    printf("查找联系人：输入3\n");
    printf("修改联系人：输入4\n");
    printf("显示联系人：输入5\n");
    printf("排序联系人：输入6\n");
    printf("退出：输入0\n");
}

// 初始化通讯录--静态
// void InitContact(Contact* con)
// {
//     assert(con);
//     con->DataCount = 0;
//     memset(con->data, 0, sizeof(con->data));
// }

// 初始化通讯录--动态
void InitContact(Contact* con)
{
    assert(con);
    con->DataCount = 0;

    // 初始分配内存
    con->data = (PeoInfo*)calloc(DEFAULT_SIZE, sizeof(PeoInfo));

    if(con->data == NULL)
    {
        printf("%s\n", strerror(errno));
    }

    con->capacity = DEFAULT_SIZE;
}

// 增加联系人--静态
// void AddContact(Contact* con)
// {
//     assert(con);

//     // 通讯录满的情况
//     if(con->DataCount == MAX)
//     {
//         printf("\n通讯录已满\n");
//         return;
//     }

//     // 通讯录未满的情况，将数据输入到下标为DataCount的位置
//     printf("请输入名字:");
//     scanf("%s", con->data[con->DataCount].name);
//     printf("请输入年龄:");
//     scanf("%d", &(con->data[con->DataCount].age));
//     printf("请输入性别:");
//     scanf("%s", con->data[con->DataCount].sex);
//     printf("请输入电话:");
//     scanf("%s", con->data[con->DataCount].tele);
//     printf("请输入地址:");
//     scanf("%s", con->data[con->DataCount].addr);

//     con->DataCount++;

//     printf("\n增加成功!\n\n");

// }

// 扩容
void CheckCapacity(Contact* con)
{
    // 通讯录满的情况，需要扩容
    if(con->DataCount == con->capacity)
    {
        PeoInfo* temp = (PeoInfo*)realloc(con->data, (con->capacity + DEFAULT_ADD) * sizeof(PeoInfo));
        if(temp == NULL)
        {
            printf("%s\n", strerror(errno));
            return;
        }
        else
        {
            con->data = temp;
            con->capacity = con->capacity + DEFAULT_ADD;
            printf("\n增容成功！\n");
        }
    }
}

// 删除通讯录
void DestoryContact(Contact* con)
{
    assert(con);
    free(con->data);
    con->data = NULL;
    con = NULL;
}

// 增加联系人--动态
void AddContact(Contact* con)
{
    assert(con);

    CheckCapacity(con);

    // 通讯录未满的情况，将数据输入到下标为DataCount的位置
    printf("请输入名字:");
    scanf("%s", con->data[con->DataCount].name);
    printf("请输入年龄:");
    scanf("%d", &(con->data[con->DataCount].age));
    printf("请输入性别:");
    scanf("%s", con->data[con->DataCount].sex);
    printf("请输入电话:");
    scanf("%s", con->data[con->DataCount].tele);
    printf("请输入地址:");
    scanf("%s", con->data[con->DataCount].addr);

    con->DataCount++;

    printf("\n增加成功!\n\n");
}

// 查找联系人，找到输出下标，否则输出-1
int FindByName(const Contact* con, const char* name)
{
    assert(con && name);
    if(con->DataCount == 0)
    {
        printf("\n通讯录为空，无法进行查找。\n");
        return -1;
    }
    for(int i = 0; i < con->DataCount; i++)
    {
        if(0 == strcmp(con->data[i].name, name))
        {
            return i;
        }
    }
    return -1;
}

// 删除联系人
void DelContact(Contact* con)
{
    assert(con);
    int i = 0;
    if(con->DataCount == 0)
    {
        printf("\n通讯录为空，没有信息可以删除\n");
        return;
    }
    printf("\n输出你要删除的联系人名字：");
    char name[MAX_NAME] = {0};
    scanf("%s", name);
    int flag = FindByName(con, name);
    if(flag == -1)
    {
        printf("\n你要删除的联系人不存在。\n");
        return;
    }
    else
    {
        for(i = flag; i < con->DataCount - 1; i++)
        {
            con->data[i] = con->data[i + 1];
        }
    }
    con->DataCount--;
    printf("\n删除成功!\n");

}

// 查找联系人
void SearchContact(Contact* con)
{
    char name[MAX_NAME] = {0};
    printf("\n请输入要查找的联系人名字：");
    scanf("%s", name);
    int flag = FindByName(con, name);
    if(flag == -1)
    {
        printf("\n不存在该联系人。\n");
        return;
    }
    else
    {
        printf("\n查找结果如下：\n");
        printf("\n%-20s\t%-5s\t%-5s\t%-12s\t%-30s", "名字", "年龄", "性别", "电话", "地址");
        printf("\n%-20s\t%-3d\t%-5s\t%-12s\t%-30s\n", 
            con->data[flag].name, 
            con->data[flag].age, 
            con->data[flag].sex, 
            con->data[flag].tele, 
            con->data[flag].addr);
    }
}

// 修改联系人
void ModifyContact(Contact* con)
{
    assert(con);
    if(con->DataCount == 0)
    {
        printf("\n通讯录为空，无法进行修改\n");
        return;
    }
    printf("\n请输入你要修改的联系人的名字：");
    char name[MAX_NAME] = {0};
    scanf("%s", name);
    int flag = FindByName(con, name);
    if(flag == -1)
    {
        printf("\n要修改的联系人不存在！\n");
        return;
    }
    else
    {
        printf("请输入修改后的名字:");
        scanf("%s", con->data[flag].name);
        printf("请输入修改后的年龄:");
        scanf("%d", &(con->data[flag].age));
        printf("请输入修改后的性别:");
        scanf("%s", con->data[flag].sex);
        printf("请输入修改后的电话:");
        scanf("%s", con->data[flag].tele);
        printf("请输入修改后的地址:");
        scanf("%s", con->data[flag].addr); 
        
        printf("\n修改成功\n");
    }
}       

// 打印通讯录
void ShowContact(const Contact* con)
{
    assert(con);
    int i = 0;

    // 打印表头
    printf("\n%-20s\t%-5s\t%-5s\t%-12s\t%-30s", "名字", "年龄", "性别", "电话", "地址");
    for(i = 0; i < con->DataCount; i++)
    {
        printf("\n%-20s\t%-3d\t%-5s\t%-12s\t%-30s\n", 
                    con->data[i].name, 
                    con->data[i].age, 
                    con->data[i].sex, 
                    con->data[i].tele, 
                    con->data[i].addr);
    }
}

int cmp(const void *e1, const void *e2)
{
    return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
}

// 排序联系人
void SortContact(Contact* con)
{
    assert(con);
    qsort(con->data, con->DataCount, sizeof(PeoInfo), cmp);   //排序
    printf("\n排序成功！\n");
}

int main()
{
    int MenuInput = 0;
    Contact con;

    //初始化通讯录
    InitContact(&con);

    do
    {
        printf("\n");
        menu();
        printf("\n请输入操作：");
        scanf("%d", &MenuInput);
        printf("\n");
        switch(MenuInput)
        {
            case ADD:
                AddContact(&con);                       //增加
                break;
            case DEL:
                DelContact(&con);                       //删除
                break;
            case SEARCH:
                SearchContact(&con);                    //查找
                break;
            case MODIFY:
                ModifyContact(&con);                    //修改
                break;
            case SHOW:
                ShowContact(&con);                      //显示
                break;
            case SORT:
                SortContact(&con);                      //排序
                break;
            case EXIT:
                DestoryContact(&con);                   //释放空间
                printf("您已退出\n");                   //退出
                break;
            default:
                printf("输入错误，请重新输入\n");
                break;
        }
    } while (MenuInput);
    
    return 0;
}
