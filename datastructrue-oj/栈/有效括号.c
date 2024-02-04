//力扣20
// 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
//有效字符串需满足：
//左括号必须用相同类型的右括号闭合。
//左括号必须以正确的顺序闭合。
//每个右括号都有一个对应的相同类型的左括号。

//数组加字符串，不用栈
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

//栈
typedef char STDataType;
typedef struct Stack
{
    STDataType* a;
    int top;//栈顶
    int capacity;//容量
}ST;//结构体类型
void StackInit(ST* ps);
void StackDestroy(ST* ps);
void StackPush(ST* ps, STDataType x);//进数据
void StackPop(ST* ps);//出数据
STDataType StackTop(ST* ps);//取栈顶数据
int StackSize(ST* ps);
bool StackEmpty(ST* ps);//判断栈是否为空

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
void StackPush(ST* ps, STDataType x)//进数据
{
    assert(ps);
    if (ps->top == ps->capacity)//扩容
    {
        int newCapacity = (ps->capacity == 0 ? 4 : ps->capacity * 2);
        STDataType* tmp = realloc(ps->a, sizeof(STDataType) * newCapacity);//扩容
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

void StackPop(ST* ps)//出数据
{
    assert(ps);
    assert(ps->top > 0);
    ps->top--;
}

STDataType StackTop(ST* ps)//取栈顶数据
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
bool StackEmpty(ST* ps)//判断栈是否为空
{
    assert(ps);//断言
    return ps->top == 0;//反的
}

bool isValid(char* s) //左括号就入栈，右括号就出栈，看是否匹配
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
            if (StackEmpty(&st))//栈为空
            {
                StackDestroy(&st);
                return false;
            }
            char top = StackTop(&st);
            StackPop(&st);
            if ((*s == '}' && top != '{') || (*s == ']' && top != '[') || (*s == ')' && top != '('))//不匹配
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
    StackDestroy(&st);//防止内存泄漏
    return ret;
}