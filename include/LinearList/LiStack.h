//
// Created by Lenovo on 2022/9/13.
//

#ifndef INC_408_DATASTRUCT_LISTACK_H
#define INC_408_DATASTRUCT_LISTACK_H

#include "BasicType.h"

//-------------链栈--------------//
//采用头节点的方式实现-----头节点记录栈内元素数
typedef struct {
    ElemType data;
    struct LinkNode* next;
} LinkNode, *LiStack;

LiStack InitLiStack();                         //初始化一个链栈
Status LiStackEmpty(LiStack* stack);                        //判断链栈是否为空
Status Push_LiStack(LiStack* stack, ElemType x);            //链栈的压栈
Status Pop_LiStack(LiStack* stack, ElemType* x);            //链栈的谭栈
Status GetTop_LiStack(LiStack* stack, ElemType* x);         //获取链栈栈顶元素
Status Destroy_LiStack(LiStack* stack);                     //销毁链栈
Status LiStackCount(LiStack* stack); //

#endif //INC_408_DATASTRUCT_LISTACK_H
