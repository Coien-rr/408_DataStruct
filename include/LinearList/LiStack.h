//
// Created by Lenovo on 2022/9/13.
//

#ifndef INC_408_DATASTRUCT_LISTACK_H
#define INC_408_DATASTRUCT_LISTACK_H

#include "BasicType.h"

//-------------链栈--------------//
//采用头节点的方式实现-----头节点记录栈内元素数
typedef struct LiStackNode {
    ElemType data;
    struct LiStackNode* next;
} LiStackNode, *LiStack;

LiStack InitLiStack();                         //初始化一个链栈
Status LiStackEmpty(LiStack stack);                        //判断链栈是否为空
Status Push_LiStack(LiStack stack, ElemType x);            //链栈的压栈
Status Pop_LiStack(LiStack stack, ElemType* x);            //链栈的谭栈
Status GetTop_LiStack(LiStack stack, ElemType* x);         //获取链栈栈顶元素
Status Destroy_LiStack(LiStack stack);                     //销毁链栈
Status LiStackCount(LiStack stack); //


//----------------双链表实现链栈----------//
//采用不含头结点方式实现-----栈顶在链尾
typedef struct DLiStackNode{
    ElemType data;
    struct DLiStackNode *prev, *next;

} DLiStackNode, *DLiStack;

//-----------基本操作函数----------//
DLiStack InitDLiStack();
Status DLiStackEmpty(DLiStack stack);
DLiStack Push_DLiStack(DLiStack stack, ElemType x);
DLiStack Pop_DLiStack(DLiStack stack, ElemType *x);
Status GetTop_DLiStack(DLiStack stack, ElemType *x);
Status Destroy_DLiStack(DLiStack stack);

#endif //INC_408_DATASTRUCT_LISTACK_H
