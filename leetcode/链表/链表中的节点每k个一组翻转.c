//将给出的链表中的节点每 k 个一组翻转，返回翻转后的链表
//如果链表中的节点数不是 k 的倍数，将最后剩下的节点保持原样
//你不能更改节点中的值，只能更改节点本身。
//给定的链表是
//
//1→2→3→4→5
//对于
//k = 2, 你应该返回
//2→1→4→3→5
//对于
//
//k = 3, 你应该返回
//
//3→2→1→4→5


struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if (head == NULL || k <= 1)
        return head;
    struct ListNode* tmp1, * tmp2, * cur;
    cur = head;
    tmp1 = NULL;
    tmp2 = NULL;
    //检查是否有k个节点
    for (int i = 1; i <= k; i++) {
        if (cur == NULL)
            return head;
        cur = cur->next;
    }
    cur = head;
    //头插
    for (int i = 1; i <= k; i++) {
        tmp1 = cur->next;//记录
        cur->next = tmp2;//相当于置空
        tmp2 = cur;
        cur = tmp1;
    }
    head->next = reverseKGroup(tmp1, k);
    return tmp2;

}