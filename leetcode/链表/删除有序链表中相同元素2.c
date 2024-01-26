//牛客BM16
//给出一个升序排序的链表，删除链表中的所有重复出现的元素，只保留原链表中只出现一次的元素。
//例如：
//给出的链表为
//1→2→3→3→4→4→5, 返回1→2→5.
//给出的链表为
//1→1→1→2→3, 返回2→3.

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL)
    {
        return NULL;
    }
    if (head->next == NULL)
    {
        return head;
    }
    struct ListNode* newHead = (struct ListNode*)malloc(sizeof(struct ListNode));//哨兵位
    newHead->next = head;
    struct ListNode* cur = newHead;
    while (cur->next != NULL && cur->next->next != NULL)
    {
        if (cur->next->val == cur->next->next->val)//head和head->next
        {
            int num = cur->next->val;//记录
            while (num == cur->next->val && cur->next != NULL)
            {
                cur->next = cur->next->next;
            }
        }
        else 
        {
            cur = cur->next;
        }
    }
    struct ListNode* tmp = newHead->next;
    free(newHead);
    return tmp;
}