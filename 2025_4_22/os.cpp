#include<iostream>
#include<cstdio>
#include<cstdlib> 
#include<algorithm>
#include<string>
using namespace std;

// 内存块结构体
struct memory
{
    int startaddre;    // 起始地址
    int endaddre;      // 结束地址
    int id;            // 占用进程ID
    int size;          // 分区大小
    int state;         // 占用状态：0空闲，1占用
    struct memory* next; 
};

// 进程控制块结构体
typedef struct node
{
    int no;            // 进程序号
    int id;            // 进程ID
    int operation;     // 操作类型：1分配，2释放
    int volume;        // 请求内存大小
} PCB;

PCB pcb[1010];         // 进程请求数组
int sig = 0;           // 算法选择标志：1-FF，2-BF，3-WF
int num = 0;           // 进程请求数量
int total;             // 内存总容量

// 函数声明
void FF(memory* p);
void BF(memory* p, memory* head);
void WF(memory* p, memory* head);
void FFallocate(PCB pc, memory* p);
void BFallocate(PCB pc, memory* p, memory* head);
void WFallocate(PCB pc, memory* p, memory* head);
void free_(PCB pc, memory* p);
void input();
void output(PCB pc, memory* p);

// 主函数：初始化内存链表，根据算法选择执行分配策略
int main()
{
    input();  // 读取输入数据

    memory *head, *p;
    head = (memory*)malloc(sizeof(memory));  // 初始化内存链表头节点
    head->next = NULL;
    head->size = total;
    head->startaddre = 0;
    head->endaddre = total - 1;
    head->state = 0;
    p = head;

    switch (sig)  // 根据算法标志选择分配策略
    {
        case 1: FF(p); break;     // 首次适应
        case 2: BF(p, head); break; // 最佳适应
        case 3: WF(p, head); break; // 最坏适应
    }
    return 0;
}

// 输入函数：读取算法标志、内存容量和进程请求序列
void input()
{
    cin >> sig;        // 读取算法标志
    cin >> total;      // 读取总内存容量
    // 读取进程请求，格式为 序号/ID/操作/内存大小
    while (~scanf("%d/%d/%d/%d", &pcb[num].no, &pcb[num].id, &pcb[num].operation, &pcb[num].volume))
    {
        num++;
    }
}

// 输出函数：打印当前内存分区状态
void output(PCB pc, memory* p)
{
    printf("%d", pc.no);  // 输出进程序号
    while (p != NULL)
    {
        if (p->next != NULL)  // 非最后一个节点
        {
            if (p->state == 1)
                printf("/%d-%d.%d.%d", p->startaddre, p->endaddre, p->state, p->id);
            else
                printf("/%d-%d.%d", p->startaddre, p->endaddre, p->state);
        }
        else  // 最后一个节点换行
        {
            if (p->state == 1)
                printf("/%d-%d.%d.%d\n", p->startaddre, p->endaddre, p->state, p->id);
            else
                printf("/%d-%d.%d\n", p->startaddre, p->endaddre, p->state);
        }
        p = p->next;
    }
}

// 首次适应分配算法：顺序查找第一个可用的内存块
void FFallocate(PCB pc, memory* p)
{
    while (p != NULL)
    {
        // 找到空闲且足够大的分区
        if (p->state == 0 && pc.volume <= p->size)
        {
            p->id = pc.id;
            p->state = 1;
            p->endaddre = p->startaddre + pc.volume - 1;
            // 分裂剩余空间为新节点
            if (p->size > pc.volume)
            {
                memory* add = (memory*)malloc(sizeof(memory));
                add->startaddre = p->endaddre + 1;
                add->size = p->size - pc.volume;
                add->endaddre = add->startaddre + add->size - 1;
                add->state = 0;
                add->next = p->next;
                p->next = add;
                p->size = pc.volume;
            }
            break;
        }
        p = p->next;
    }
}

// 最佳适应分配算法：查找剩余空间最小的可用块
void BFallocate(PCB pc, memory* p, memory* head)
{
    int min_sub = -1;     // 最小剩余空间差值
    int location = 0;     // 目标块位置
    int len = 0;          // 当前遍历位置
    memory* target = NULL;

    // 遍历链表，记录最小剩余空间的块位置
    while (p != NULL)
    {
        if (p->state == 0 && p->size >= pc.volume)
        {
            int sub = p->size - pc.volume;
            if (min_sub == -1 || sub < min_sub)
            {
                min_sub = sub;
                location = len;
            }
        }
        len++;
        p = p->next;
    }

    // 找到目标块并分配
    if (min_sub != -1)
    {
        p = head;
        for (int i = 0; i < location; i++) p = p->next;
        p->id = pc.id;
        p->state = 1;
        p->endaddre = p->startaddre + pc.volume - 1;
        // 分裂剩余空间
        if (min_sub > 0)
        {
            memory* add = (memory*)malloc(sizeof(memory));
            add->startaddre = p->endaddre + 1;
            add->size = p->size - pc.volume;
            add->endaddre = add->startaddre + add->size - 1;
            add->state = 0;
            add->next = p->next;
            p->next = add;
            p->size = pc.volume;
        }
    }
}

// 最坏适应分配算法：查找剩余空间最大的可用块
void WFallocate(PCB pc, memory* p, memory* head)
{
    int max_sub = -1;     // 最大剩余空间差值
    int location = 0;     // 目标块位置
    int len = 0;          // 当前遍历位置

    // 遍历链表，记录最大剩余空间的块位置
    while (p != NULL)
    {
        if (p->state == 0 && p->size >= pc.volume)
        {
            int sub = p->size - pc.volume;
            if (sub > max_sub)
            {
                max_sub = sub;
                location = len;
            }
        }
        len++;
        p = p->next;
    }

    // 找到目标块并分配
    if (max_sub != -1)
    {
        p = head;
        for (int i = 0; i < location; i++) p = p->next;
        p->id = pc.id;
        p->state = 1;
        p->endaddre = p->startaddre + pc.volume - 1;
        // 分裂剩余空间
        if (max_sub > 0)
        {
            memory* add = (memory*)malloc(sizeof(memory));
            add->startaddre = p->endaddre + 1;
            add->size = p->size - pc.volume;
            add->endaddre = add->startaddre + add->size - 1;
            add->state = 0;
            add->next = p->next;
            p->next = add;
            p->size = pc.volume;
        }
    }
}

// 释放内存块并合并相邻空闲块
void free_(PCB pc, memory* p)
{
    memory* prev = NULL;  // 前驱节点
    while (p != NULL)
    {
        if (p->id == pc.id)  // 找到目标块
        {
            p->state = 0;
            // 合并前驱空闲块
            if (prev != NULL && prev->state == 0)
            {
                prev->size += p->size;
                prev->endaddre = p->endaddre;
                prev->next = p->next;
                free(p);
                p = prev;
            }
            // 合并后继空闲块
            if (p->next != NULL && p->next->state == 0)
            {
                p->size += p->next->size;
                memory* temp = p->next;
                p->endaddre = temp->endaddre;
                p->next = temp->next;
                free(temp);
            }
            break;
        }
        prev = p;
        p = p->next;
    }
}

// 首次适应算法主流程
void FF(memory* p)
{
    for (int i = 0; i < num; i++)
    {
        if (pcb[i].operation == 1)
        {
            FFallocate(pcb[i], p);
            output(pcb[i], p);
        }
        else
        {
            free_(pcb[i], p);
            output(pcb[i], p);
        }
    }
}

// 最佳适应算法主流程
void BF(memory* p, memory* head)
{
    for (int i = 0; i < num; i++)
    {
        if (pcb[i].operation == 1)
        {
            BFallocate(pcb[i], p, head);
            output(pcb[i], p);
        }
        else
        {
            free_(pcb[i], p);
            output(pcb[i], p);
        }
    }
}

// 最坏适应算法主流程
void WF(memory* p, memory* head)
{
    for (int i = 0; i < num; i++)
    {
        if (pcb[i].operation == 1)
        {
            WFallocate(pcb[i], p, head);
            output(pcb[i], p);
        }
        else
        {
            free_(pcb[i], p);
            output(pcb[i], p);
        }
    }
}