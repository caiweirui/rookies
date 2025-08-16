/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode;
typedef struct ListNode* Linklist;

struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if(right == left || head == NULL || head->next == NULL)
    {
        return head;
    }
    int i = 0;
    ListNode* ret = (ListNode*)malloc(sizeof(ListNode));
    ret->next = head;
    ListNode* phead = ret;
    for(i = 1; i < left; i++)
    {
        phead = phead->next;
    }

    ListNode* ptail = phead;
    for(i = 0; i <= right - left; i++)
    {
        ptail = ptail->next;
    }
    ptail = ptail->next;

    ListNode* temp = phead->next;
    ListNode* r = NULL;
    phead->next = ptail;

    while(right >= left)
    {
        r = temp;
        temp = temp->next;
        r->next = phead->next;
        phead->next = r;
        right--;
    }
    return ret->next;
}