/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode;

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    // 初始化ret
    ListNode* ret = (ListNode*)malloc(sizeof(ListNode));
    ret->next = NULL;

    int temp = 0;
    int cf = 0;
    ListNode* s1 = l1;
    ListNode* s2 = l2;
    ListNode* s, *r= ret;

    while(s1 != NULL || s2 != NULL)
    {
        temp = cf;
        if(s1 != NULL)
        {
            temp += s1->val;
            s1 = s1->next;
        }
        if(s2 != NULL)
        {
            temp += s2->val;
            s2 = s2->next;
        }

        cf = temp / 10;
        temp = temp % 10;

        s = (ListNode*)malloc(sizeof(ListNode));
        s->next = NULL;
        s->val = temp;
        r->next = s;
        r = s;
    }

    // 处理最终进位
    if(cf == 1)
    {
        s = (ListNode*)malloc(sizeof(ListNode));
        s->next = NULL;
        s->val = cf;
        r->next = s;
        r = s;
    }

    r->next = NULL;

    return ret->next;
}