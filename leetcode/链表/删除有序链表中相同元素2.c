//ţ��BM16
//����һ���������������ɾ�������е������ظ����ֵ�Ԫ�أ�ֻ����ԭ������ֻ����һ�ε�Ԫ�ء�
//���磺
//����������Ϊ
//1��2��3��3��4��4��5, ����1��2��5.
//����������Ϊ
//1��1��1��2��3, ����2��3.

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL)
    {
        return NULL;
    }
    if (head->next == NULL)
    {
        return head;
    }
    struct ListNode* newHead = (struct ListNode*)malloc(sizeof(struct ListNode));//�ڱ�λ
    newHead->next = head;
    struct ListNode* cur = newHead;
    while (cur->next != NULL && cur->next->next != NULL)
    {
        if (cur->next->val == cur->next->next->val)//head��head->next
        {
            int num = cur->next->val;//��¼
            while (num == cur->next->val && cur->next != NULL)
            {
                cur->next = cur->next->next;
            }
        }
        else 
        {
            cur = cur->next;
        }
    }
    struct ListNode* tmp = newHead->next;
    free(newHead);
    return tmp;
}