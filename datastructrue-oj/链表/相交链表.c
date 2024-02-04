/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//leetcode 160
//给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 null 。

//题目数据 保证 整个链式结构中不存在环。

//注意，函数返回结果后，链表必须 保持其原始结构 。


struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) 
{
    struct ListNode* tailA=headA;
    struct ListNode* tailB=headB;
    int sum1=1,sum2=1;
    while(tailA->next)
    {
        tailA=tailA->next;
        sum1++;//统计两个链表的长度
    }
     while(tailB->next)
    {
        tailB=tailB->next;
        sum2++;
    }
    if(tailA!=tailB)
    {
        return NULL;//尾结点不同则不可能相交
    }
    else
    {
       struct ListNode* head1=headA;
       struct ListNode* head2=headB;
       //让较长链表的头指针先走两链表之差
            if(sum1>sum2)
            {
                for(int i=1;i<=sum1-sum2;i++)
                {
                   head1=head1->next;
                }
            }
            else if(sum1<sum2)
            {
                for(int i=1;i<=sum2-sum1;i++)
                {
                   head2=head2->next;
                }
            }
            //可能两个指针没一起走就已经相交1，2,3和1,2,3   1,2,3,4,5和3,4,5
            if(head1==head2)
            {
                return head1;
            }
            //然后两个指针一起走
            for(int i=1;i<(sum1<sum2?sum1:sum2);i++)
            {
                head1=head1->next;
                head2=head2->next;
                if(head1==head2)
                {
                   return head1;
                }
            }
        
    }
return NULL;
}