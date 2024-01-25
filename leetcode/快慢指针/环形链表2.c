//LCR 022. 环形链表 II
//给定一个链表，返回链表开始入环的第一个节点。 从链表的头节点开始沿着 next 指针进入环的第一个节点为环的入口节点。如果链表无环，则返回 null。
//为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 - 1，则在该链表中没有环。注意，pos 仅仅是用于标识环的情况，并不会作为参数传递到函数中。
//说明：不允许修改给定的链表

struct ListNode* detectCycle(struct ListNode* head) {
    struct ListNode* slow = head, * fast = head;
    while (fast != NULL && fast->next != NULL) //走到空则一定没环
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow) //找快慢指针相遇处，让两个指针从头和相遇处同时走，相遇处为第一个节点
        {
            struct ListNode* ptr = head;
            while (ptr != slow) {
                ptr = ptr->next;
                slow = slow->next;
            }
            return ptr;
        }
    }
    return NULL;


}