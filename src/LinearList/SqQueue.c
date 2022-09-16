
#include "LinearList/SqQueue.h"


Status InitSqQueue(SqQueue* queue){
    queue->front = 0;
    queue->rear = 0;
    queue->tag = 0;
    queue->count = 0;
    return OK;
}

Status SqQueueEmpty(SqQueue* queue){
    if ( queue->front == queue->rear && queue->tag == 0 && queue->count == 0 ) {
        return TRUE;
    }
    return FALSE;

//    //使用标记为判空
//    if ( queue->tag == 0 ) {
//        return TRUE;
//    }
//    return FALSE;

//    使用队列计数判空
//    if (queue->count == 0 ) {
//        return TRUE;
//    }


}

Status SqQueueFull(SqQueue* queue){
    //利用单元来判满
    if((queue->rear + 1)%MaxSize == (queue-> front)%MaxSize){
        return TRUE;
    }
    return FALSE;


//    //利用TAG位判满
//    if(queue->tag == 1){
//        return TRUE;
//    }
//    return FALSE;
//
//    //利用计数位COUNT判满
//    if(queue->count == MaxSize){
//        return OK;
//    }
//    return FALSE;
}

Status EnSqQueue(SqQueue* queue, ElemType x){
    if( SqQueueFull(queue) ) return OVERFLOW;

    queue->data[queue->rear++] = x;
    queue->rear %= MaxSize;
    queue->count++;

    if ( queue->front == queue->rear ) queue->tag = 1;

    return OK;
}

Status DeSqQueue(SqQueue* queue, ElemType* x){
    if ( SqQueueEmpty(queue) ) return OVERFLOW;

    *x = queue->data[queue->front++];
    queue->front %= MaxSize;
    queue->count--;

    queue->tag = 0;

    return OK;
}

Status GetHeadSqQueue(SqQueue* queue, ElemType* x){
    if( SqQueueEmpty(queue) ) return OVERFLOW;
    *x = queue->data[queue->front];
    return OK;
}

int SqQueueCount(SqQueue* queue){
//    return queue->count;
    return (queue->rear + MaxSize - queue->front)%MaxSize;
}
