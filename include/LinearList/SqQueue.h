//
// Created by Lenovo on 2022/9/15.
//

#ifndef INC_408_DATASTRUCT_SQQUEUE_H
#define INC_408_DATASTRUCT_SQQUEUE_H

#include "BasicType.h"


//-----------循环队列--------------//
//使用数组实现
typedef struct {
    ElemType data[MaxSize];
    int front, rear;
    int tag;                                  //用于循环队列判空
    int count;                               //用于循环队列判满
} SqQueue;

Status InitSqQueue(SqQueue* queue);
Status SqQueueEmpty(SqQueue* queue);
Status SqQueueFull(SqQueue* queue);
Status EnSqQueue(SqQueue* queue, ElemType x);
Status DeSqQueue(SqQueue* queue, ElemType* x);
Status GetHeadSqQueue(SqQueue* queue, ElemType* x);
int SqQueueCount(SqQueue* queue);

#endif //INC_408_DATASTRUCT_SQQUEUE_H
