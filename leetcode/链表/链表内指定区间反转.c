//ţ��BM2
//��һ���ڵ���Ϊ size ���� m λ�õ� n λ��֮������䷴ת��
//���磺
//����������
//1��2��3��4��5��NULL,
//m = 2, n = 4,
//����
//1��4��3��2��5��NULL.

struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    // write code here
    if (head->next == NULL || head == NULL)
        return head;
    struct ListNode* H = malloc(sizeof(struct ListNode));
    H->next = head;//�ڱ�λ
    struct ListNode* p, * temp, * cur = H;
    //��λ��ת����
    for (int i = 0; i < m - 1; i++)
    {
        cur = cur->next;
    }
    temp = cur;//�����ͷ���
    struct ListNode* q;
    cur = cur->next;//��ת�����һ���ڵ�
    q = cur;//���淴ת�����һ���ڵ�
    //ͷ�巨��ת����
    for (int i = 0; i < n - m + 1; i++)
    {
        p = cur;
        cur = cur->next;
        p->next = temp->next;
        temp->next = p;
    }
    q->next = cur;//��ת�����һ���ڵ���ԭ����ת�����ĵ�һ���ڵ�����
    struct ListNode* newHead = H->next;
    free(H);
    return newHead;
}