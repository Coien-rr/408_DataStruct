

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


//----------------双链表实现链栈--------------//

DLiStack InitDLiStack(){
    DLiStack stack = NULL;
    return stack;
}

Status DLiStackEmpty(DLiStack stack){
    if(stack == NULL) return TRUE;
    return FALSE;
}

DLiStack Push_DLiStack(DLiStack stack, ElemType x){
    DLiStackNode* node = (DLiStackNode*)malloc(sizeof(DLiStackNode));

    if(!node) exit(OVERFLOW);

    node->next = NULL;
    node->data = x;
    node->prev = stack;

    if(stack) {
        stack->next = node;
    }
    stack = node;

    return stack;
}

DLiStack Pop_DLiStack(DLiStack stack, ElemType *x){
    if(DLiStackEmpty(stack)) exit(OVERFLOW);

    DLiStackNode* node = stack;

    *x = node->data;
    stack = stack->prev;

    if(stack) stack->next = NULL;

    free(node);

    return stack;
}

Status GetTop_DLiStack(DLiStack stack, ElemType *x){
    if(DLiStackEmpty(stack)) return OVERFLOW;

    *x = stack->data;

    return OK;
}

Status Destroy_DLiStack(DLiStack stack){
    while(!DLiStackEmpty(stack)){
        int x = 0;
        stack = Pop_DLiStack(stack, &x);
    }
    free(stack);
    return OK;
}