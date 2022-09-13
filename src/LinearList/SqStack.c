//
// Created by Lenovo on 2022/9/13.
//
#include "LinearList/SqStack.h"

Status InitSqStack(SqStack* stack){
    stack->top = -1;
    return OK;
}                                                       //初始化一个顺序栈

Status SqStackEmpty(SqStack* stack){
    if(stack->top == -1){
        return TRUE;
    }
    return FALSE;
}                                                       //判断顺序栈是否为空

Status Push_SqStack(SqStack* stack, ElemType x){
    //参数检查
    if(stack->top == MaxSize-1){
        return OVERFLOW;
    }
    stack->data[++stack->top] = x;
    return OK;
}                                                       //压栈

Status Pop_SqStack(SqStack* stack, ElemType* x){
    //参数检查
    if(SqStackEmpty(stack)){
        return OVERFLOW;
    }
    *x = stack->data[stack->top--];
    return OK;
}                                                        //弹栈

Status GetTop_SqStack(SqStack* stack, ElemType* x){
    //参数检查
    if(SqStackEmpty(stack)){
        return OVERFLOW;
    }
    *x = stack->data[stack->top];
    return OK;
}                                                        //获取栈顶元素

Status Destroy_SqStack(SqStack* stack){
    stack->top = -1;
    return OK;
}                                                         //销毁栈

