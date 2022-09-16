//
// Created by Lenovo on 2022/9/16.
//

#include "LinearList/LiQueue.h"
#include <stdlib.h>

LiQueue InitLiQueue(){
    LiQueue queue = (LiQueue)malloc(sizeof(LiQueue));
    queue->front = NULL;
    queue->rear = NULL;
}

Status LiQueueEmpty(LiQueue queue){
    if ( queue->front == NULL && queue->rear == NULL) {
        return TRUE;
    }
    return FALSE;
}

Status EnLiQueue(LiQueue queue, ElemType x){
    LiQueueNode* node = (LiQueueNode*) malloc(sizeof(LiQueueNode));

    if(!node) return ERROR;

    node->data = x;
    node->next = NULL;

    if(queue->rear == NULL){
        //插入第一个数据时
        queue->rear = node;
        queue->front = node;
    } else {
        queue->rear->next = node;
        queue->rear = node;
    }

    return OK;
}

Status DeLiQueue(LiQueue queue, ElemType* x){
    //参数检查
    if ( LiQueueEmpty(queue) ) return OVERFLOW;

    LiQueueNode* node = queue->front;
    *x = node->data;

    queue->front = queue->front->next;
    if ( queue->front == NULL ){
        //删除最后一个数据时
        queue->rear = NULL;
    }
    free(node);

    return OK;
}

Status GetTopLiQueue(LiQueue queue, ElemType* x){
    //参数检查
    if ( LiQueueEmpty(queue) ) return OVERFLOW;

    *x = queue->front->data;

    return OK;
}

Status DestroyLiQueue(LiQueue queue){
    while( !LiQueueEmpty(queue) ){
        int x = 0;
        DeLiQueue(queue, &x);
    }

    free(queue);

    return OK;
}