//牛客BM2
//将一个节点数为 size 链表 m 位置到 n 位置之间的区间反转，
//例如：
//给出的链表
//1→2→3→4→5→NULL,
//m = 2, n = 4,
//返回
//1→4→3→2→5→NULL.

struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    // write code here
    if (head->next == NULL || head == NULL)
        return head;
    struct ListNode* H = malloc(sizeof(struct ListNode));
    H->next = head;//哨兵位
    struct ListNode* p, * temp, * cur = H;
    //定位反转区间
    for (int i = 0; i < m - 1; i++)
    {
        cur = cur->next;
    }
    temp = cur;//区间的头结点
    struct ListNode* q;
    cur = cur->next;//反转区间第一个节点
    q = cur;//保存反转区间第一个节点
    //头插法反转链表
    for (int i = 0; i < n - m + 1; i++)
    {
        p = cur;
        cur = cur->next;
        p->next = temp->next;
        temp->next = p;
    }
    q->next = cur;//反转区间第一个节点与原链表反转区间后的第一个节点相连
    struct ListNode* newHead = H->next;
    free(H);
    return newHead;
}