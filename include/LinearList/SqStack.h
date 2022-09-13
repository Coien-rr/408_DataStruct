//
// Created by Lenovo on 2022/9/13.
//

#ifndef INC_408_DATASTRUCT_SQSTACK_H
#define INC_408_DATASTRUCT_SQSTACK_H

#include "BasicType.h"

//---------------------顺序栈—————————————————————//
typedef struct {
    ElemType data[MaxSize];
    int top;                // 栈顶指针
} SqStack;
Status InitSqStack(SqStack* stack);                     //初始化一个顺序栈
Status SqStackEmpty(SqStack* stack);                    //判断顺序栈是否为空
Status Push_SqStack(SqStack* stack, ElemType x);        //压栈
Status Pop_SqStack(SqStack* stack, ElemType* x);        //弹栈
Status GetTop_SqStack(SqStack* stack, ElemType* x);     //获取栈顶元素
Status Destroy_SqStack(SqStack* stack);                 //销毁栈


#endif //INC_408_DATASTRUCT_SQSTACK_H
