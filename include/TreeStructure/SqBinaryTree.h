//
// Created by Lenovo on 2022/9/19.
//

#ifndef INC_408_DATASTRUCT_SQBINARYTREE_H
#define INC_408_DATASTRUCT_SQBINARYTREE_H

#include "BasicType.h"

//------------顺序二叉树-------------//
//使用数组实现
//若顺序二叉树从数组下标1开始存储结点，则：
//● 结点 i 的父结点编号为 i/2
//● 结点 i 的左孩子编号为 i*2
//● 结点 i 的右孩子编号为 i*2+1
//
//若顺序二叉树从数组下标0开始存储结点，则：
//● 结点 i 的父结点编号为 [(i+1)/2] - 1
//● 结点 i 的左孩子编号为 [(i+1)*2] - 1 = 2*i + 1
//● 结点 i 的右孩子编号为 [(i+1)*2+1] - 1 = 2*i + 2

typedef struct SqBiTreeNode {
    ElemType data;
    Status isEmpty;
} SqBiTreeNode ;

typedef struct SqBiTree{
    SqBiTreeNode node[MaxSize+1];
} SqBiTree ;

Status initSqBiTree(SqBiTree* tree);
Status isSqBiTreeNodeEmpty(SqBiTree* tree, int index);
Status getSqBiTreeLchild(SqBiTree* tree, int index, SqBiTreeNode* child);
Status getSqBiTreeRchild(SqBiTree* tree, int index, SqBiTreeNode* child);
Status getSqBiTreeParent(SqBiTree* tree, int index, SqBiTreeNode* parent);
Status preOrderSqBiTree(SqBiTree* tree, int index);
Status inOrderSqBiTree(SqBiTree* tree, int index);
Status postOrderSqBiTree(SqBiTree* tree, int index);

//辅助函数
Status paramCheckSqBiTree(int index);
Status copyNodeSqBiTree(SqBiTree* tree, int index, SqBiTreeNode* node);
Status visitSqBiTreeNode(SqBiTree* tree, int index);


#endif //INC_408_DATASTRUCT_SQBINARYTREE_H
