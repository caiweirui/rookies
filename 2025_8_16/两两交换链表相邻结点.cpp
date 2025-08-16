typedef struct ListNode ListNode;

struct ListNode* swapPairs(struct ListNode* head) {
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    ListNode* temp = head;
    head = head->next;
    temp->next = head->next;
    head->next = temp;

    ListNode* pre = head->next;
    ListNode* cur = head->next->next;
    
    while(cur != NULL && cur->next != NULL)
    {
        temp = cur;
        pre->next = cur->next;
        cur->next = cur->next->next;
        pre->next->next = temp;
        pre = cur;
        cur = cur->next;
    }
    return head;
}