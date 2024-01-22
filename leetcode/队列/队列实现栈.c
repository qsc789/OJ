//�ö��е��Ƚ��ȳ�ʵ��ջ�ĺ���ȳ�
// ��������ʵ��һ��ջ
//�����ݣ�����Ϊ�յĶ����룬������һ������Ϊ��
//������ʱ���γ���ͷ������,ת�Ƶ���һ�����б��档ֻʣ���һ������pop����ʵ�ֺ���ȳ� 
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
QDataType QueueFront(Queue* pq);//ȡ��ͷ����
QDataType QueueBack(Queue* pq);//ȡ��β����
int QueueSize(Queue* pq);//��������ж�������
bool QueueEmpty(Queue* pq);
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;
}
void QueuePush(Queue* pq, QDataType x)//β��
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
		pq->tail = NULL;//���ÿվ���Ұָ�� 
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
	Queue* emptyQ = &obj->q1;//��
	Queue* nonemptyQ = &obj->q2;//�ǿ�
	if (!QueueEmpty(&obj->q1))//q1��Ϊ�գ��ͻ�һ��
	{
		emptyQ = &obj->q2;
		nonemptyQ = &obj->q1;
	}
	while (QueueSize(nonemptyQ) > 1)//�ж������
	{
		QueuePush(emptyQ, QueueFront(nonemptyQ));//������
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
	free(obj);//����ֻ���ⲽ
}
