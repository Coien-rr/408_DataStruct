//
// Created by Lenovo on 2022/9/21.
//

#ifndef INC_408_DATASTRUCT_SQTREE_H
#define INC_408_DATASTRUCT_SQTREE_H

#include "BasicType.h"

//--------双亲表示法定义顺序树（森林）-------------//
typedef struct SqTreeNode {
    char data;
    int parentIndex;
} SqTreeNode;


typedef struct SqTree {
    int count;
    SqTreeNode node[MaxSize];
} SqTree;

Status initSqTree(SqTree *tree);
int getSqTreeParent(SqTree *tree, int index);

//辅助函数
Status createDemoSqTree(SqTree *tree);


#endif //INC_408_DATASTRUCT_SQTREE_H
