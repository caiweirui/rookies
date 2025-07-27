/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode;

int length(ListNode* L)
{
    int len = 0;
    ListNode* p = L;


    while(p != NULL)
    {
        len++;
        p = p->next;
    }
    return len;
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int len = length(head);
    if(len == 1)
    {
        return NULL;
    }

    n = len - n;
    if(n == 0)
    {
        ListNode* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    
    int j = 0;
    ListNode* p = head;
    while(p != NULL && j < n - 1)
    {
        p = p->next;
        j++;
    }

    ListNode* q = p->next;

    p->next = q->next;
    free(q);

    return head;
}