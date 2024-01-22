//用队列的先进先出实现栈的后进先出
// 两个队列实现一个栈
//入数据，往不为空的队列入，保持另一个队列为空
//出数据时依次出队头的数据,转移到另一个队列保存。只剩最后一个数据pop掉，实现后进先出 
typedef int QDataType;
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QueueNode;
typedef struct Queue
{
	QueueNode* head;
	QueueNode* tail;

}Queue;
typedef struct {
	Queue q1;
	Queue q2;

} MyStack;
void QueueInit(Queue* pq);
void QueueDestroy(Queue* pq);
void QueuePush(Queue* pq, QDataType x);
void QueuePop(Queue* pq);
QDataType QueueFront(Queue* pq);//取队头数据
QDataType QueueBack(Queue* pq);//取队尾数据
int QueueSize(Queue* pq);//计算队里有多少数据
bool QueueEmpty(Queue* pq);
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;
}
void QueuePush(Queue* pq, QDataType x)//尾插
{
	assert(pq);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	newnode->data = x;
	newnode->next = NULL;
	if (pq->head == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
}
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	QueueNode* next = pq->head->next;
	free(pq->head);
	pq->head = next;
	if (pq->head == NULL)
	{
		pq->tail = NULL;//不置空就是野指针 
	}
}
int QueueSize(Queue* pq)
{
	assert(pq);
	int n = 0;
	QueueNode* cur = pq->head;
	while (cur)
	{
		n++;
		cur = cur->next;
	}
	return n;
}
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL;
}
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->head->data;
}
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->tail->data;
}
void QueueDestroy(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->head;
	while (cur != NULL)
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = pq->tail = NULL;
}
MyStack* myStackCreate()
{
	MyStack* st = (MyStack*)malloc(sizeof(MyStack));
	QueueInit(&st->q1);
	QueueInit(&st->q2);
	return st;
}
void myStackPush(MyStack* obj, int x)
{
	if (!QueueEmpty(&obj->q1))
	{
		QueuePush(&obj->q1, x);
	}
	else
	{
		QueuePush(&obj->q2, x);
	}
}
int myStackPop(MyStack* obj)
{
	Queue* emptyQ = &obj->q1;//空
	Queue* nonemptyQ = &obj->q2;//非空
	if (!QueueEmpty(&obj->q1))//q1不为空，就换一下
	{
		emptyQ = &obj->q2;
		nonemptyQ = &obj->q1;
	}
	while (QueueSize(nonemptyQ) > 1)//有多个数据
	{
		QueuePush(emptyQ, QueueFront(nonemptyQ));//倒数据
		QueuePop(nonemptyQ);
	}
	int top = QueueFront(nonemptyQ);
	QueuePop(nonemptyQ);
	return top;
}
int myStackTop(MyStack* obj) {
	if (!QueueEmpty(&obj->q1))
	{
		return QueueBack(&obj->q1);
	}
	else
	{
		return QueueBack(&obj->q2);
	}
}
bool myStackEmpty(MyStack* obj) {
	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}
void myStackFree(MyStack* obj) {
	QueueDestroy(&obj->q1);
	QueueDestroy(&obj->q2);
	free(obj);//不能只有这步
}
