
#include "LinearList/SqQueue.h"


Status InitSqQueue(SqQueue* queue){
    queue->front = 0;
    queue->rear = 0;
    return OK;
}

Status SqQueueEmpty(SqQueue* queue){
    if(queue->front == 0 && queue->rear == 0){
        return TRUE;
    }
    return FALSE;
}

Status SqQueueFull(SqQueue* queue){
    if(queue->rear == MaxSize){
        return TRUE;
    }
    return FALSE;
}

Status EnSqQueue(SqQueue* queue, ElemType x){
    if( SqQueueFull(queue) ) return OVERFLOW;
    queue->data[queue->rear++] = x;
    return OK;
}

Status DeSqQueue(SqQueue* queue, ElemType* x){
    if ( SqQueueEmpty(queue) ) return OVERFLOW;
    *x = queue->data[queue->front++];
    return OK;
}

Status GetHeadSqQueue(SqQueue* queue, ElemType* x){
    if( SqQueueEmpty(queue) ) return OVERFLOW;
    *x = queue->data[queue->front];
    return OK;
}