/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode;
typedef struct ListNode* Linklist;

// struct ListNode* deleteDuplicates(struct ListNode* head) {
//     if(head == NULL || head->next == NULL)
//     {
//         return head;
//     }
//     ListNode* p = head;
//     int hash[201] = {0};
//     while(p != NULL)
//     {
//         hash[p->val + 100]++;
//         p = p->next;
//     }

//     Linklist ret = (Linklist)malloc(sizeof(ListNode));
//     ret->next = NULL;
//     ListNode* retp = ret;
//     for(int i = 0; i < 201; i++)
//     {
//         if(hash[i] >= 1)
//         {
//             ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
//             temp->val = i - 100;
//             retp->next = temp;
//             retp = temp;
//         }
//     }
//     retp->next = NULL;

//     return ret->next;
// }

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    ListNode* pre = head;
    ListNode* cur = head->next;
    while(cur != NULL)
    {
        if(cur->val != pre->val)
        {
            pre->next->val = cur->val;
            pre = pre->next;
        }
        cur = cur->next;
    }
    pre->next = NULL;
    return head;
}