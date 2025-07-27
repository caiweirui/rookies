#include<bits/stdc++.h>

// 创建单链表(带头结点)
typedef struct LNode
{
    int data;
    struct LNode* next;
}LNode, *LinkList;

// 初始化单链表
LinkList InitList(LinkList L)
{
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL; // 需要这一步
    return L;
}

// 单链表的插入
// 按位序插入
bool ListInsert(LinkList L, int i, int e)
{
    // 头结点不可插入
    if(i < 1)
    {
        return false;
    }

    // p指向第一个结点
    LNode* p;
    p = L;

    // j代表当前指向第几个结点
    int j = 0;

    // 循环找到要插入的位置
    while(p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }

    // 当插入位置大于length时报错
    if(p == NULL)
    {
        return false;
    }

    // 插入操作，将新创建的结点数据部分赋值
    // 将新创建的指针的next指针指向上一个指针的next指针
    // 将上一个结点的next指针指向新创建的结点
    LNode* s = (LNode*)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;

    // return InsertNextNode(p, e);
    return true;
} 

// 后插操作
bool InsertNextNode(LNode* p, int e)
{
    if(p == NULL)
    {
        return false;
    }

    LNode* s = (LNode*)malloc(sizeof(LNode));
    if(s == NULL)
    {
        return false;
    }

    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

// 前插操作（带头结点）
bool InsertPriorNode1(LNode* p, int e, LNode* L)
{
    if(L == NULL && p == NULL)
    {
        return false;
    }

    // 找到前驱
    LNode* q = L;
    while(q != NULL)
    {
        if(q->next == p)
        {
            break;
        }
        q = q->next;
    }

    // 后插操作
    LNode* s = (LNode*)malloc(sizeof(LNode));
    s->data = e;
    s->next = p;
    q->next = s;
    return true;

    //return InsertNextNode(q, e);
}

// 前插操作（不带头结点）
bool InsertPriorNode1(LNode* p, int e)
{
    if(p == NULL)
    {
        return false;
    }

    // 后插操作+交换数据
    LNode* s = (LNode*)malloc(sizeof(LNode));
    s->next = p->next;
    p->next = s;
    s->data = p->data;
    p->data = e;

    return true;
}

// 单链表的删除
// 按位序删除
bool ListDelete(LNode* L, int i, int &e)
{
    if(i < 1)
    {
        return false;
    }

    LNode* p = L;

    int j = 0;
    while(p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }

    // 删除操作，将上一个结点的next指针指向要删除结点的next指针
    // 返回要删除结点的数据
    // 释放要删除结点的空间
    LNode* q = p->next;
    p->next = q->next;
    e = q->data;
    free(q);

    return true;
}

// 指定结点删除
bool DeleteNode(LNode* p)
{
    if(p == NULL)
    {
        return false;
    }

    // 将下一个结点的信息复制给要删除的结点
    // 释放下一个结点的空间
    LNode* q = p->next;
    p->data = q->data;
    p->next = q->next;
    free(q);

    return true;
}

// 单链表的查找
// 按位查找
LNode* GetElem(LinkList L, int i)
{
    if(i < 0)
    {
        return NULL;
    }

    LNode* p = L;
    int j = 0;
    while(p != NULL && j < i)
    {
        p = p->next;
        j++; 
    }
    return p;
}

// 按值查找
LNode* LocateElem(LinkList L, int e)
{
    LNode* p = L;
    while(p != NULL && p->data != e)
    {
        p = p->next;
    }
    return p;
}

// 求单链表的长度
int length(LinkList L)
{
    int len = 0;
    LNode* p = L;
    while(p != NULL)
    {
        len++;
        p = p->next;
    }
    return len;
}

// 单链表的建立
// 尾插法（对尾结点进行后插）
LinkList ListTailInsert(LinkList L)
{
    int x = 0;
    LNode* s, *r = L;
    while(scanf("%d", &x) != EOF && x != -1)
    {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
    }
    r->next = NULL;
    return L;
}

// 头插法（对头结点进行后插）
LinkList ListHeadInsert(LinkList L)
{
    int x = 0;
    LNode* s = L;
    while(scanf("%d", &x) != EOF && x != -1)
    {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
    }
    return L;
}

// 链表的逆序
void LinkListReverse(LinkList L)
{
    if (L == NULL || L->next == NULL) return; // 空表或单节点无需逆序
    
    LNode *p = L->next;    // 指向第一个有效节点
    LNode *temp;           // 临时保存下一个节点
    L->next = NULL;        // 头节点断开连接
    
    while (p != NULL) {
        temp = p->next;    // 保存下一个节点
        p->next = L->next; // 当前节点指向原首节点
        L->next = p;       // 头节点指向当前节点
        p = temp;          // 移动到下一个节点
    }
}

// 打印单链表
void LinkListPrint(LinkList L)
{
    LNode* p = L->next;
    while(p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}

int main()
{
    LinkList L = InitList(L);
    L = ListTailInsert(L);
    LinkListPrint(L);
    LinkListReverse(L);
    LinkListPrint(L);
    return 0;
}