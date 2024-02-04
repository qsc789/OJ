//力扣148
//给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
//
// 题目链接：https://leetcode.cn/problems/sort-list
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* merge(struct ListNode* head1,struct ListNode* head2)
{
    struct ListNode* newhead=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* tmp=newhead;
    struct ListNode* tmp1=head1;
    struct ListNode* tmp2=head2;
    while(tmp1!=NULL&&tmp2!=NULL)
    {
        if(tmp1->val<=tmp2->val)
        {
            tmp->next=tmp1;
            tmp1=tmp1->next;
        }
        else
        {
            tmp->next=tmp2;
            tmp2=tmp2->next;
        }
        tmp=tmp->next;
    }
    if(tmp1!=NULL)
    {
        tmp->next=tmp1;
    }
    else if(tmp2!=NULL)
    {
        tmp->next=tmp2;
    }
    struct ListNode* phead=newhead->next;
    free(newhead);
    return phead;
}
struct ListNode* toSortList(struct ListNode* head,struct ListNode* tail)
{
    if(head==NULL)
    {
        return head;
    }
    if(head->next==tail)
    {
        head->next=NULL;
        return head;
    }
    struct ListNode* slow=head;
    struct ListNode* fast=head;
    while(fast!=tail)
    {
        slow=slow->next;
        fast=fast->next;
        if(fast!=tail)
        {
            fast=fast->next;
        }
    }
    struct ListNode* mid=slow;
    return merge(toSortList(head,mid),toSortList(mid,tail));
}
struct ListNode* sortList(struct ListNode* head) {
    return toSortList(head,NULL);
}