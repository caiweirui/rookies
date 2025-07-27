/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode;

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    ListNode* p1 = list1;
    ListNode* p2 = list2;
    ListNode* ret = (ListNode*)malloc(sizeof(ListNode));
    ret->next = NULL;
    ListNode* s, *r = ret;
    int temp = 0;
    while(p1 != NULL || p2 != NULL)
    {
        if(p1 == NULL)
        {
            temp = p2->val;
            p2 = p2->next;
        }
        else if(p2 == NULL)
        {
            temp = p1->val;
            p1 = p1->next;
        }
        else
        {
            if(p1->val < p2->val)
            {
                temp = p1->val;
                p1 = p1->next;
            }
            else
            {
                temp = p2->val;
                p2 = p2->next;
            }
        }
        s = (ListNode*)malloc(sizeof(ListNode));
        s->val = temp;
        r->next = s;
        r = s;
    }
    r->next = NULL;
    return ret->next;
}