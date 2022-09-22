//
// Created by Lenovo on 2022/9/22.
//

#ifndef INC_408_DATASTRUCT_UFSET_H
#define INC_408_DATASTRUCT_UFSET_H

#include "BasicType.h"
#include "SqTree.h"

//-------------并查集------------//
//双亲表示法表示集合
//根结点数据的绝对值为集合内元素数量
typedef struct UFSet {
    SqTreeNode setNode[MaxSize];
    int count; // 结点总数
} UFSet;

Status initUFSet(UFSet* ufSet);

Status unionUFSet(UFSet* ufSet, int root1, int root2);
int findUFSet(UFSet* ufSet, int index);


//辅助函数
Status createDemoUfSet(UFSet* ufSet);
Status printUFSet(UFSet *ufSet);

void testUFSetFunc();


#endif //INC_408_DATASTRUCT_UFSET_H
