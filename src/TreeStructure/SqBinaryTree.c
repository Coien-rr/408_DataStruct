//
// Created by Lenovo on 2022/9/19.
//

#include <stdio.h>
#include "TreeStructure/SqBinaryTree.h"

Status initSqBiTree(SqBiTree* tree){
    for (int i = 1; i <= MaxSize; ++i) {
        tree->node[i].data = i;
        tree->node[i].isEmpty = FALSE;
    }
    return OK;
}

Status isSqBiTreeNodeEmpty(SqBiTree* tree, int index) {
    //参数检查
    if ( paramCheckSqBiTree(index) == OVERFLOW ) return OVERFLOW;

    return tree->node[index].isEmpty;
}

Status getSqBiTreeLchild(SqBiTree* tree, int index, SqBiTreeNode* child) {
    //参数检查
    if( paramCheckSqBiTree(index) == OVERFLOW) return OVERFLOW;

    return copyNodeSqBiTree(tree, index*2, child);


}

Status getSqBiTreeRchild(SqBiTree* tree, int index, SqBiTreeNode* child) {
    //参数检查
    if( paramCheckSqBiTree(index) == OVERFLOW) return OVERFLOW;

    return copyNodeSqBiTree(tree, index*2 + 1, child);
}

Status getSqBiTreeParent(SqBiTree* tree, int index, SqBiTreeNode* parent) {
    //参数检查
    if( paramCheckSqBiTree(index) == OVERFLOW) return OVERFLOW;

    return copyNodeSqBiTree(tree, index/2, parent);
}

Status preOrderSqBiTree(SqBiTree* tree, int index) {
    if (isSqBiTreeNodeEmpty(tree, index)) return OVERFLOW;

    visitSqBiTreeNode(tree, index);
    preOrderSqBiTree(tree, index*2);
    preOrderSqBiTree(tree, index*2 + 1);

    return OK;
}

Status inOrderSqBiTree(SqBiTree* tree, int index) {
    if ( isSqBiTreeNodeEmpty(tree, index) ) return OVERFLOW;

    inOrderSqBiTree(tree, index*2);
    visitSqBiTreeNode(tree, index);
    inOrderSqBiTree(tree, index*2 + 1);

    return OK;
}

Status postOrderSqBiTree(SqBiTree* tree, int index) {
    if ( isSqBiTreeNodeEmpty(tree, index) ) return OVERFLOW;

    postOrderSqBiTree(tree, index*2);
    postOrderSqBiTree(tree, index*2 + 1);
    visitSqBiTreeNode(tree, index);

    return OK;
}

Status paramCheckSqBiTree(int index) {
    if ( index <=0 || index > MaxSize ) {
        return OVERFLOW;
    }
    return OK;
}

Status copyNodeSqBiTree(SqBiTree* tree, int index, SqBiTreeNode* node){
    //参数检查
    if ( paramCheckSqBiTree(index) == OVERFLOW ) return OVERFLOW;

    tree->node[index].data = node->data;
    tree->node[index].isEmpty = node->isEmpty;

    return OK;
}

Status visitSqBiTreeNode(SqBiTree* tree, int index){
    if (paramCheckSqBiTree(index) == OVERFLOW ) return OVERFLOW;

    printf("%d ", tree->node[index].data);

    return OK;
}