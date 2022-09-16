//
// Created by Lenovo on 2022/9/16.
//

#ifndef INC_408_DATASTRUCT_LIQUEUE_H
#define INC_408_DATASTRUCT_LIQUEUE_H

#include "BasicType.h"

//-------单链表实现队列------//
//通过带头节点的方式实现
typedef struct LiQueueNode {
    ElemType data;
    struct LiQueueNode *next;
} LiQueueNode;

typedef struct LiQueue {
    LiQueueNode *front, *rear;
} *LiQueue;

LiQueue InitLiQueue( );
Status LiQueueEmpty(LiQueue queue);
Status EnLiQueue(LiQueue queue, ElemType x);
Status DeLiQueue(LiQueue queue, ElemType* x);
Status GetTopLiQueue(LiQueue queue, ElemType* x);
Status DestroyLiQueue(LiQueue queue);


#endif //INC_408_DATASTRUCT_LIQUEUE_H
