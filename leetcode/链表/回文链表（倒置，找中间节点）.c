//对于一个链表，请设计一个时间复杂度为O(n),额外空间复杂度为O(1)的算法，判断其是否为回文结构。

//给定一个链表的头指针A，请返回一个bool值，代表其是否为回文结构。保证链表长度小于等于900。

//测试样例：
//1->2->2->1
//返回：true


struct ListNode* middleNode(struct ListNode* head) {//找中间节点，偶数个则返回靠后的一个
    if (head == NULL) {
        return NULL;
    } else {
        if (head->next == NULL)
            return head;
        else {
            struct ListNode* cur = head;
            int sum = 0;
            while (cur != NULL) {
                cur = cur->next;
                sum++;
            }
            int num = sum / 2;
            cur = head;
            for (int i = 1; i <= num; i++) {
                cur = cur->next;
            }
            return cur;
        }
    }

}
struct ListNode* reverseList(struct ListNode* head) {//倒置链表
    if (head == NULL) {
        return NULL;
    } else {
        if (head->next == NULL) {
            return head;
        } else {
            struct ListNode* cur = head->next;
            struct ListNode* prev = head;
            struct ListNode* phead = head;
            while (cur->next != NULL) {
                struct ListNode* n = cur->next;
                cur->next = prev;

                prev = cur;
                cur = n;
            }
            head = cur;
            cur->next = prev;
            phead->next = NULL;
            return head;
        }
    }
}
class PalindromeList {
  public:
    bool chkPalindrome(ListNode* A) {
struct ListNode* mid=middleNode(A);
struct ListNode* rHead=reverseList(mid);
struct ListNode* curA=A;
struct ListNode* curR=rHead;
while(curA&&curR)
{
    if(curA->val!=curR->val)
    {
        return false;
    }
    else {
    curA=curA->next;
    curR=curR->next;
    }
}
return true;


    }
};