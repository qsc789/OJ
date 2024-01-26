//牛客BM11
//假设链表中每一个节点的值都在 0 - 9 之间，那么链表整体就可以代表一个整数。
//给定两个这种链表，请生成代表两个整数相加值的结果链表。
//例如：链表 1 为 9->3->7，链表 2 为 6->3，最后生成新的结果链表为 1->0->0->0，类似于竖式计算
struct ListNode* StructTurn(struct ListNode* head) //反转单链表
{
    if (head->next == NULL) {
        return head;
    }
    struct ListNode* cur = head;
    struct ListNode* n1 = NULL;
    struct ListNode* n2 = NULL;
    while (cur->next)
    {
        n2 = cur->next;
        cur->next = n1;
        n1 = cur;
        cur = n2;

    }
    cur->next = n1;
    return cur;
}
struct ListNode* addInList(struct ListNode* head1, struct ListNode* head2) {
    struct ListNode* tmp1 = StructTurn(head1);
    struct ListNode* tmp2 = StructTurn(head2);
    struct ListNode* newhead = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* tmp = newhead;
    newhead->next = NULL;
    int more = 0;
    int v1 = 0, v2 = 0;
    int sum = 0;
    while (tmp1 || tmp2 || more == 1) {

        if (tmp1 != NULL) {
            v1 = tmp1->val;
            tmp1 = tmp1->next;
        }
        else v1 = 0;
        if (tmp2 != NULL) {
            v2 = tmp2->val;
            tmp2 = tmp2->next;
        }
        else v2 = 0;

        sum = v1 + v2 + more;
        if (sum >= 10) {
            more = 1;
            sum = sum % 10;
        }
        else more = 0;

        struct ListNode* n = (struct ListNode*)malloc(sizeof(struct ListNode));
        n->val = sum;
        n->next = NULL;
        tmp->next = n;
        tmp = n;
    }

    return StructTurn(newhead->next);


}