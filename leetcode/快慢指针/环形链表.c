//leetcode 141
//给你一个链表的头节点 head ，判断链表中是否有环。
//如果链表中存在环 ，则返回 true 。 否则，返回 false 。
bool hasCycle(struct ListNode *head) {
    struct ListNode* slow=head,*fast=head;
    while(fast&&fast->next)//fast每次走两步，只有确保fast和fast->next都不为空，fast才能往下走
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            return true;
        }
    }
    return false;
}