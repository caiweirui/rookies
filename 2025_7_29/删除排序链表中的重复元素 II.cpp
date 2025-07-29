/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode ListNode;
typedef struct ListNode* Linklist;

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    ListNode* p = head;
    int hash[201] = {0};
    while(p != NULL)
    {
        hash[p->val + 100]++;
        p = p->next;
    }

    Linklist ret = (Linklist)malloc(sizeof(ListNode));
    ret->next = NULL;
    ListNode* retp = ret;
    ListNode* cur = head;
    while(cur != NULL)
    {
        if(hash[cur->val + 100] == 1)
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