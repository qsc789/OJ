//����20
// ����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ��� s ���ж��ַ����Ƿ���Ч��
//��Ч�ַ��������㣺
//�����ű�������ͬ���͵������űպϡ�
//�����ű�������ȷ��˳��պϡ�
//ÿ�������Ŷ���һ����Ӧ����ͬ���͵������š�

//������ַ���������ջ
char pairs(char a) {
    if (a == '}') return '{';
    if (a == ']') return '[';
    if (a == ')') return '(';
    return 0;
}

bool isValid(char* s) {
    int n = strlen(s);
    if (n % 2 == 1) {
        return false;
    }
    int stk[n + 1], top = 0;
    for (int i = 0; i < n; i++) {
        char ch = pairs(s[i]);
        if (ch) {
            if (top == 0 || stk[top - 1] != ch) {
                return false;
            }
            top--;
        }
        else {
            stk[top++] = s[i];
        }
    }
    return top == 0;
}

//ջ
typedef char STDataType;
typedef struct Stack
{
    STDataType* a;
    int top;//ջ��
    int capacity;//����
}ST;//�ṹ������
void StackInit(ST* ps);
void StackDestroy(ST* ps);
void StackPush(ST* ps, STDataType x);//������
void StackPop(ST* ps);//������
STDataType StackTop(ST* ps);//ȡջ������
int StackSize(ST* ps);
bool StackEmpty(ST* ps);//�ж�ջ�Ƿ�Ϊ��

void StackInit(ST* ps)
{
    assert(ps);
    ps->a = NULL;
    ps->top = 0;//ps->top=-1;
    ps->capacity = 0;
}
void StackDestroy(ST* ps)
{
    assert(ps);
    free(ps->a);
    ps->a = NULL;
    ps->capacity = ps->top = 0;
}
void StackPush(ST* ps, STDataType x)//������
{
    assert(ps);
    if (ps->top == ps->capacity)//����
    {
        int newCapacity = (ps->capacity == 0 ? 4 : ps->capacity * 2);
        STDataType* tmp = realloc(ps->a, sizeof(STDataType) * newCapacity);//����
        if (tmp == NULL)
        {
            printf("realloc fail\n");
            exit(-1);
        }
        ps->a = tmp;
        ps->capacity = newCapacity;
    }
    ps->a[ps->top] = x;
    ps->top++;
}

void StackPop(ST* ps)//������
{
    assert(ps);
    assert(ps->top > 0);
    ps->top--;
}

STDataType StackTop(ST* ps)//ȡջ������
{
    assert(ps);
    //assert(!StackEmpty(ps));
    return ps->a[ps->top - 1];
}
int StackSize(ST* ps)
{
    assert(ps);
    return ps->top;
}
bool StackEmpty(ST* ps)//�ж�ջ�Ƿ�Ϊ��
{
    assert(ps);//����
    return ps->top == 0;//����
}

bool isValid(char* s) //�����ž���ջ�������žͳ�ջ�����Ƿ�ƥ��
{
    ST st;
    StackInit(&st);
    while (*s != '\0')
    {
        switch (*s)
        {
        case '{':
        case '[':
        case '(':
        {
            StackPush(&st, *s);
            s++;
            break;
        }
        case '}':
        case ']':
        case ')':
        {
            if (StackEmpty(&st))//ջΪ��
            {
                StackDestroy(&st);
                return false;
            }
            char top = StackTop(&st);
            StackPop(&st);
            if ((*s == '}' && top != '{') || (*s == ']' && top != '[') || (*s == ')' && top != '('))//��ƥ��
            {
                StackDestroy(&st);
                return false;
            }
            else
            {
                s++;
            }
            break;
        }
        default:
            break;


        }
    }
    bool ret = StackEmpty(&st);
    StackDestroy(&st);//��ֹ�ڴ�й©
    return ret;
}