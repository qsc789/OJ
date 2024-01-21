//622
//开k+1个空间，否则无法判断空和满
//front==tail空
//(tail+1)%(k+1)==front 满（数组）
//tail->next==front 满（链表）

typedef int SLTDataType;
typedef struct SListNode
{
    SLTDataType data;
    struct SListNode* next;
    struct SListNode* prev;
}SLTNode;
typedef struct {
    SLTNode* a;
    SLTNode* tail;
    SLTNode* front;
    int k;
} MyCircularQueue;
bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);
MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* cq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    cq->a = (SLTNode*)malloc(sizeof(SLTNode));
    SLTNode* tmp = cq->a;
    for (int i = 1; i <= k; i++)
    {
        SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
        tmp->next = newnode;
        newnode->prev = tmp;
        tmp = newnode;
        if (i == k)
        {
            tmp->next = cq->a;
            cq->a->prev = tmp;
        }
    }
    cq->front = cq->tail = cq->a;
    cq->k = k;
    return cq;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (myCircularQueueIsFull(obj))
        return false;

    obj->tail->data = value;
    obj->tail = obj->tail->next;
    return true;

}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return false;
    obj->front = obj->front->next;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return -1;
    return obj->front->data;
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return -1;

    return obj->tail->prev->data;

}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->front == obj->tail;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->tail->next == obj->front;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->a);
    free(obj);
}
