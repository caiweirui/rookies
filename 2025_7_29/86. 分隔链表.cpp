/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode;
typedef struct ListNode* Linklist;

struct ListNode* partition(struct ListNode* head, int x) {
    Linklist ret = (Linklist)malloc(sizeof(ListNode));
    ListNode* retp = ret;
    ListNode* cur = head;
    while(cur)
    {
        if(cur->val < x)
        {
            ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
            temp->val = cur->val;
            retp->next = temp;
            retp = temp;
        }
        cur = cur->next;
    }  
    cur = head;
    while(cur)
    {
        if(cur->val >= x)
        {
            ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
            temp->val = cur->val;
            retp->next = temp;
            retp = temp;
        }
        cur = cur->next;
    }  
    retp->next = NULL;
    return ret->next;
}