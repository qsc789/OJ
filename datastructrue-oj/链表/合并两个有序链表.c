将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例 1：

输入：l1 = [1,2,4], l2 = [1,3,4]
输出：[1,1,2,3,4,4]

//无哨兵位
/**
 * Definition for singly-linked list. 
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if(l1==NULL)
    {
        return l2;
    }
    if(l2==NULL)
    {
        return l1;
    }
    struct ListNode* head=NULL,*tail=NULL;
  
    while(l1&&l2)//有一个为空则结束
    {
        if(l1->val<l2->val)//挑小的接在后面
        {
            if(tail==NULL)
           {
              head=tail=l1;
           }
            else
           {
              tail->next=l1;
              tail=tail->next;
            }
          l1=l1->next;
        }
        else
        {
           if(tail==NULL)
         {
            head=tail=l2;
        
         }
            else
         {
             tail->next=l2;
             tail=tail->next;
         }
          l2=l2->next;
        }
    }
    //一个为空，则把另一个整体接在后面
    if(l1)
    {
        tail->next=l1;
    }
   if(l2)
    {
        tail->next=l2;
    }
   
    return head;

}


//有哨兵位
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (l1 == NULL) {
        return l2;
    }
    if (l2 == NULL) {
        return l1;
    }
    struct ListNode *head = NULL, *tail = NULL;
    head = tail = (struct ListNode*)malloc(sizeof(struct ListNode)); //哨兵位
    while (l1 && l2) //有一个为空则结束
    {
        if (l1->val < l2->val) //挑小的接在后面
        {
            tail->next = l1;
            tail = tail->next;
            l1 = l1->next;
        } else {

            tail->next = l2;
            tail = tail->next;

            l2 = l2->next;
        }
    }
    //一个为空，则把另一个整体接在后面
    if (l1) {
        tail->next = l1;
    }
    if (l2) {
        tail->next = l2;
    }
    struct ListNode* list = head->next;
    free(head); //防止内存泄漏
    return list;
}