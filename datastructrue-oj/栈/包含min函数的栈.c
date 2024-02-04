//牛客NC90
//定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的 min 函数，输入操作时保证 pop、top 和 min 函数操作时，栈中一定有元素。
//
//此栈包含的方法有：
//push(value) :将value压入栈中
//pop() : 弹出栈顶元素
//top() : 获取栈顶元素
//min() : 获取栈中最小元素

typedef int STDataType;
typedef struct Stack
{
    STDataType* a;
    int top;//栈顶
    int capacity;//容量
}ST;//结构体类型
ST ps;
void StackBuy()
{
    if (ps.top == ps.capacity)//扩容
    {
        int newCapacity = (ps.capacity == 0 ? 4 : ps.capacity * 2);
        STDataType* tmp = realloc(ps.a, sizeof(STDataType) * newCapacity);//扩容
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


bool StackEmpty()//判断栈是否为空
{
    //assert(ps);//断言
    return ps.top == 0;//反的
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