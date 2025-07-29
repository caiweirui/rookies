struct ListNode* swapPairs(struct ListNode* head) {
    // 创建哑节点简化操作
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* prev = &dummy;
    
    while (prev->next != NULL && prev->next->next != NULL) {
        // 定位要交换的两个节点
        struct ListNode* first = prev->next;
        struct ListNode* second = prev->next->next;
        
        // 执行交换
        prev->next = second;          // 前置节点连第二个节点
        first->next = second->next;   // 第一个节点连第三个节点
        second->next = first;         // 第二个节点连第一个节点
        
        // 移动prev指针
        prev = first;
    }
    
    return dummy.next;  // 返回新头节点
}