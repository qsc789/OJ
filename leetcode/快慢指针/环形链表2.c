//LCR 022. �������� II
//����һ��������������ʼ�뻷�ĵ�һ���ڵ㡣 �������ͷ�ڵ㿪ʼ���� next ָ����뻷�ĵ�һ���ڵ�Ϊ������ڽڵ㡣��������޻����򷵻� null��
//Ϊ�˱�ʾ���������еĻ�������ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ���� ��� pos �� - 1�����ڸ�������û�л���ע�⣬pos ���������ڱ�ʶ�����������������Ϊ�������ݵ������С�
//˵�����������޸ĸ���������

struct ListNode* detectCycle(struct ListNode* head) {
    struct ListNode* slow = head, * fast = head;
    while (fast != NULL && fast->next != NULL) //�ߵ�����һ��û��
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow) //�ҿ���ָ����������������ָ���ͷ��������ͬʱ�ߣ�������Ϊ��һ���ڵ�
        {
            struct ListNode* ptr = head;
            while (ptr != slow) {
                ptr = ptr->next;
                slow = slow->next;
            }
            return ptr;
        }
    }
    return NULL;


}