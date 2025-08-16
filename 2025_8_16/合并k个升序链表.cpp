/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode;

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    ListNode* ret = (ListNode*)malloc(sizeof(ListNode));
    ListNode* retp = ret;
    ret->next = NULL;
    int* hash = (int*)malloc(sizeof(int) * 20001);
    int i = 0;
    ListNode* temp = NULL;

    for(i = 0; i < listsSize; i++)
    {
        temp = lists[i];
        while(temp != NULL)
        {
            hash[temp->val + 10000]++;
            temp = temp->next;
        }
    }
    
    for(i = 0; i < 20001; i++)
    {
        while(hash[i] > 0)
        {
            temp = (ListNode*)malloc(sizeof(ListNode));
            temp->next = NULL;
            temp->val = i - 10000;
            retp->next = temp;
            retp = temp;
            hash[i]--;
        }
    }
    return ret->next;
}