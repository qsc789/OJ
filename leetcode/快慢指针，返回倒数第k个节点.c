输入一个链表，输出该链表中倒数第k个结点。
示例1
输入
1,{1,2,3,4,5}
输出
{5}
/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

/**
 * 
 * @param pListHead ListNode类 
 * @param k int整型 
 * @return ListNode类
 */
struct ListNode* FindKthToTail(struct ListNode* pListHead, int k ) {
    // 快慢指针
    //快指针先走k步，然后快慢指针一起走，fast==NULL时，slow为目标结点
    
    if(pListHead==NULL)
    {
        return NULL;
    }
    else
    {
        if(pListHead->next==NULL)
        {
            return pListHead;
        }
        else
        {
            struct ListNode* n=pListHead;
            int sum=0;
            while(n!=NULL)
            {
                sum++;
                n=n->next;
            }
            if(k>sum||k==0)
            {
                return NULL;
            }
            struct ListNode* fast=pListHead;
            struct ListNode* slow=pListHead;
    
    
    for(int i=1;i<=k;i++)
    {
        fast=fast->next;
    }
    while(fast!=NULL)
    {
        slow=slow->next;
        fast=fast->next;
    }
   //slow->next=NULL;
    return slow;
    }
    }

}