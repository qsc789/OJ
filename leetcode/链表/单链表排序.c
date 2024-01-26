//ţ��BM12
//����һ���ڵ���Ϊn�������������䰴��������

//����ӿ���
int cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}
struct ListNode* sortInList(struct ListNode* head)
{
    int num[1000000];
    int i = 0;
    while (head != NULL)
    {
        num[i] = head->val;//���������valֵ
        head = head->next;
        i++;
    }
    qsort(num, i, sizeof(int), cmp);//����
    struct ListNode* H = (struct ListNode* )malloc(sizeof(struct ListNode));
    struct ListNode* cur = H;
    int j = 0;
    //����������
    while (j != i)
    {
        struct ListNode* temp = (struct ListNode* )malloc(sizeof(struct ListNode));
        temp->next = NULL;
        temp->val = num[j];
        cur->next = temp;
        cur = temp;
        j++;
    }
    return H->next;
}
//����ָ��
struct ListNode* sortInList(struct ListNode* head) {
    if (head == NULL)
    {
        return head;
    }

    // �ݹ��ս�����,�ҵ�β���
    if (head->next == NULL)
    {
        return head;
    }

    // ����ָ�뷽���ҵ��м�ڵ�
    struct ListNode* fast = head->next, * slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    struct ListNode* middle = slow->next;
    struct ListNode* left = NULL, * right = NULL;
    slow->next = NULL;

    left = sortInList(head);
    right = sortInList(middle);
    struct ListNode* newHead = NULL;
    struct ListNode* newTail = NULL;

    struct ListNode newNode = { 0 };
    newNode.next = NULL;
    newHead = newTail = &newNode;
    while (left != NULL && right != NULL)
    {
        if (left->val < right->val)
        {
            newTail->next = left;
            left = left->next;
        }
        else
        {
            newTail->next = right;
            right = right->next;
        }
        newTail = newTail->next;
        newTail->next = NULL;
    }

    if (left == NULL)
    {
        newTail->next = right;
    }
    if (right == NULL)
    {
        newTail->next = left;
    }

    return newHead->next;
}
