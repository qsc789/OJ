//力扣147
//题目链接：https://leetcode.cn/problems/insertion-sort-list
//给定单个链表的头 head ，使用 插入排序 对链表进行排序，并返回 排序后链表的头 。
//插入排序 算法的步骤:
//插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
//每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
//重复直到所有输入数据插入完为止。
//下面是插入排序算法的一个图形示例。部分排序的列表(黑色)最初只包含列表中的第一个元素。每次迭代时，从输入数据中删除一个元素(红色)，并就地插入已排序的列表中。
//对链表进行插入排序。
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head) {
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    struct ListNode* newhead=(struct ListNode*)malloc(sizeof(struct ListNode));
    newhead->next=head;
    struct ListNode* prev=head;
    struct ListNode* cur=head->next;

    while(cur!=NULL)
    {
        if(prev->val<=cur->val)
        {
            prev=prev->next;
        }
        else
        {
            struct ListNode* tmp=newhead;
            while(tmp->next->val<=cur->val)//找到合适位置，cur插到tmp后边
            {
                tmp=tmp->next;
            }
            prev->next=cur->next;//跳过cur
            cur->next=tmp->next;
            tmp->next=cur;
        }
        cur=prev->next;
    }
    return newhead->next;
}