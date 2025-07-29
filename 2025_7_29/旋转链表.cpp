/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode;
typedef struct ListNode* Linklist;

int length(Linklist L)
{
    int len = 0;
    ListNode* p = L;
    while(p != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}

struct ListNode* rotateRight(struct ListNode* head, int k) {
    int len = length(head);
    if(len <= 1)
    {
        return head;
    }
    k = len - k % len;
    Linklist ret = (ListNode*)malloc(sizeof(ListNode));
    ListNode* retp = ret;
    ret->next = NULL;
    int i = 0;
    ListNode* p = head;
    while(p != NULL && i < k)
    {
        p = p->next;
        i++;
    }
    while(p != NULL && i < len)
    {
        retp->next = p;
        retp = p;
        p = p->next;
        i++;
    }
    i = 0;
    p = head;
    while(i < k)
    {
        retp->next = p;
        retp = p;
        p = p->next;
        i++;
    }
    retp->next = NULL;
    return ret->next;
}