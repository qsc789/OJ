现有一链表的头指针 ListNode* pHead，给一定值x，编写一段代码将所有小于x的结点排在其余结点之前，且不能改变原来的数据顺序，返回重新排列后的链表的头指针。
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
//新建两个链表，一个放小的，一个放大的，最后连起来
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        struct ListNode* lesshead,*lesstail,*greaterhead,*greatertail;
        //开一个哨兵位头结点，方便尾插
        lesshead=lesstail=(struct ListNode*)malloc(sizeof(struct ListNode));
        lesstail->next=NULL;
         greaterhead=greatertail=(struct ListNode*)malloc(sizeof(struct ListNode));
        greatertail->next=NULL;
struct ListNode* cur=pHead;
while(cur)
{
    if(cur->val<x)
    {
        lesstail->next=cur;
        lesstail=cur;
    }
    else
    {
        greatertail->next=cur;
        greatertail=cur;
    }
    cur=cur->next;
}
        lesstail->next=greaterhead->next;
        greatertail->next=NULL;
        struct ListNode* pphead=lesshead->next;
        free(lesshead);
        free(greaterhead);

        return pphead;
    }
};