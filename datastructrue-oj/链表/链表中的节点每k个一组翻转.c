//�������������еĽڵ�ÿ k ��һ�鷭ת�����ط�ת�������
//��������еĽڵ������� k �ı����������ʣ�µĽڵ㱣��ԭ��
//�㲻�ܸ��Ľڵ��е�ֵ��ֻ�ܸ��Ľڵ㱾��
//������������
//
//1��2��3��4��5
//����
//k = 2, ��Ӧ�÷���
//2��1��4��3��5
//����
//
//k = 3, ��Ӧ�÷���
//
//3��2��1��4��5


struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if (head == NULL || k <= 1)
        return head;
    struct ListNode* tmp1, * tmp2, * cur;
    cur = head;
    tmp1 = NULL;
    tmp2 = NULL;
    //����Ƿ���k���ڵ�
    for (int i = 1; i <= k; i++) {
        if (cur == NULL)
            return head;
        cur = cur->next;
    }
    cur = head;
    //ͷ��
    for (int i = 1; i <= k; i++) {
        tmp1 = cur->next;//��¼
        cur->next = tmp2;//�൱���ÿ�
        tmp2 = cur;
        cur = tmp1;
    }
    head->next = reverseKGroup(tmp1, k);
    return tmp2;

}