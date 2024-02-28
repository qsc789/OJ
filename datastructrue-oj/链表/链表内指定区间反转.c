//ţ��BM2
//��һ���ڵ���Ϊ size ���� m λ�õ� n λ��֮������䷴ת��
//���磺
//����������
//1��2��3��4��5��NULL,
//m = 2, n = 4,
//����
//1��4��3��2��5��NULL.
struct ListNode* reverseBetween(struct ListNode* head, int m, int n ) {
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    struct ListNode* res=malloc(sizeof(struct ListNode));
    res->next=head;
    struct ListNode* pre=res;
    struct ListNode* cur=head;
   
    for(int i=1;i<m;i++)
    {
        pre=cur;
        cur=cur->next;
    }
    for(int i=m;i<n;i++)
    {
       struct ListNode* temp=cur->next;
       cur->next=temp->next;
       temp->next=pre->next;
       pre->next=temp;
    }
    return res->next;
}

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
    q->next = cur;//��ת�����һ���ڵ���ԭ������ת�����ĵ�һ���ڵ�����
    struct ListNode* newHead = H->next;
    free(H);
    return newHead;
}