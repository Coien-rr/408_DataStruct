

#include <stdlib.h>
#include "LinearList/LiStack.h"

LiStack InitLiStack(){
    LiStack stack= (LiStack)malloc(sizeof(LiStack));
    stack->data = 0;
    stack->next = NULL;
    return stack;
}                                                           //初始化一个链栈

Status LiStackEmpty(LiStack stack){
    if(stack->next == NULL){
        return TRUE;
    }
    return FALSE;
//    if(stack->data == 0){
//        return TRUE;
//    }
//    return FALSE;
}                                                           //判断链栈是否为空

Status Push_LiStack(LiStack stack, ElemType x){
    LiStackNode* node = (LiStackNode* )malloc(sizeof(LiStackNode));
    if(!node) return OVERFLOW;  //请求分配内存空间失败
    node->data = x;
    node->next = stack->next;
    stack->next = node;
    stack->data++;
    return OK;
}                                                           //链栈的压栈

Status Pop_LiStack(LiStack stack, ElemType* x){
    //参数检查
    if(LiStackEmpty(stack)) return OVERFLOW;

    LiStackNode* node = stack->next;
    *x = node->data;
    stack->next = node->next;
    stack->data--;
    node->next = NULL;
    free(node);
    return OK;
}                                                           //链栈的谭栈

Status GetTop_LiStack(LiStack stack, ElemType* x){
    //参数检查
    if(LiStackEmpty(stack)) return OVERFLOW;

    *x = stack->next->data;
    return OK;
}                                                           //获取链栈栈顶元素

Status Destroy_LiStack(LiStack stack){
    while(!LiStackEmpty(stack)){
        int x = 0;
        Pop_LiStack(stack, &x);
    }
    free(stack);
    return OK;
}                                                           //销毁链栈

int LiStackCount(LiStack stack){
    return stack->data;
}

DLiStack InitDLiStack(){
    DLiStack stack = (DLiStack)malloc(sizeof(DLiStack));

    if(!stack) exit(OVERFLOW);

    stack->next = NULL;
    stack->prev = NULL;
    return stack;
}

Status DLiStackEmpty(DLiStack stack){
    if(stack->next == NULL) return TRUE;
    return FALSE;
}

Status Push_DLiStack(DLiStack stack, ElemType x){
    DLiStackNode* node = (DLiStackNode*)malloc(sizeof(DLiStackNode));

    if(!node) return OVERFLOW;

    node->next = stack->next;
    node->data = x;
    node->prev = stack;

    stack->next = node;

    return OK;
}

Status Pop_DLiStack(DLiStack stack, ElemType *x){
    if(DLiStackEmpty(stack)) return OVERFLOW;

    DLiStackNode* node = stack->next;

    *x = node->data;
    node->prev = NULL;
    stack->next = node->next;
    node->next = NULL;

    free(node);

    if(!DLiStackEmpty(stack)){
        stack->next->prev = stack;
    }

    return OK;
}

Status GetTop_DLiStack(DLiStack stack, ElemType *x){
    if(DLiStackEmpty(stack)) return OVERFLOW;

    *x = stack->next->data;

    return OK;
}

Status Destroy_DLiStack(DLiStack stack){
    while(!DLiStackEmpty(stack)){
        int x = 0;
        Pop_DLiStack(stack, &x);
    }
    free(stack);
    return OK;
}