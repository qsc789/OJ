//ţ��NC90
//����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ��������СԪ�ص� min �������������ʱ��֤ pop��top �� min ��������ʱ��ջ��һ����Ԫ�ء�
//
//��ջ�����ķ����У�
//push(value) :��valueѹ��ջ��
//pop() : ����ջ��Ԫ��
//top() : ��ȡջ��Ԫ��
//min() : ��ȡջ����СԪ��

typedef int STDataType;
typedef struct Stack
{
    STDataType* a;
    int top;//ջ��
    int capacity;//����
}ST;//�ṹ������
ST ps;
void StackBuy()
{
    if (ps.top == ps.capacity)//����
    {
        int newCapacity = (ps.capacity == 0 ? 4 : ps.capacity * 2);
        STDataType* tmp = realloc(ps.a, sizeof(STDataType) * newCapacity);//����
        if (tmp == NULL)
        {
            printf("realloc fail\n");
            exit(-1);
        }
        ps.a = tmp;
        ps.capacity = newCapacity;
    }
}

void push(int value) {
    StackBuy();
    ps.a[ps.top] = value;
    ps.top++;

}


void pop() {

    ps.top--;

}


bool StackEmpty()//�ж�ջ�Ƿ�Ϊ��
{
    //assert(ps);//����
    return ps.top == 0;//����
}

int top()
{
    int p = ps.top;
    p--;
    return ps.a[p];


}


int min() {
    int min = 0;
    int MIN = 999999;
    for (int i = 0; i < ps.top; i++)
    {
        if (ps.a[i] < MIN)
        {
            MIN = ps.a[i];
        }
    }
    min = MIN;
    return min;
}