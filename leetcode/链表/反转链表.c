//206. ��ת����
//���㵥�����ͷ�ڵ� head �����㷴ת���������ط�ת�������


//��ָ��
struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL)
    {
        return NULL;
    }
    if (head->next == NULL)
    {
        return head;
    }
    struct ListNode* n1 = NULL;
    struct ListNode* n2 = head;
    struct ListNode* n3 = head->next;
    while (n3 != NULL)
    {
        n2->next = n1;
        n1 = n2;
        n2 = n3;
        n3 = n3->next;
    }
    n2->next = n1;
    return n2;
}
//ͷ�巨
struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL)
    {
        return NULL;
    }
    if (head->next == NULL)
    {
        return head;
    }
    struct ListNode* newHead = NULL;
    struct ListNode* cur = head;

    while (cur != NULL)
    {
        struct ListNode* next = cur->next;
        cur->next = newHead;
        newHead = cur;
        cur = next;
    }

    return newHead;
}