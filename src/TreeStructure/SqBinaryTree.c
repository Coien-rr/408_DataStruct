//
// Created by Lenovo on 2022/9/19.
//

#include <stdio.h>
#include "TreeStructure/SqBinaryTree.h"

Status initSqBiTree(SqBiTree* tree){

}

Status isSqBiTreeNodeEmpty(SqBiTree* tree, int index) {

}

Status getSqBiTreeLchild(SqBiTree* tree, int index, SqBiTreeNode* child) {

}

Status getSqBiTreeRchild(SqBiTree* tree, int index, SqBiTreeNode* child) {

}

Status getSqBiTreeParent(SqBiTree* tree, int index, SqBiTreeNode* parent) {

}

Status preOrderSqBiTree(SqBiTree* tree, int index) {

}

Status inOrderSqBiTree(SqBiTree* tree, int index) {

}

Status postOrderSqBiTree(SqBiTree* tree, int index) {

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