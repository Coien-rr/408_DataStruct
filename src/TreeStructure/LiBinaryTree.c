//
// Created by Lenovo on 2022/9/20.
//

#include <stdlib.h>
#include "TreeStructure/LiBinaryTree.h"

int treeIndex = 0;
char treeNode[15] = {'A', 'B', 'C', ' ', ' ',
                     'D', 'E', ' ', 'G', ' ',
                     ' ', 'F', ' ', ' ', ' '};


Status initLiBinaryTree(LiBinaryTree* tree){
    LiBinaryTree root = (LiBinaryTreeRoot*) malloc(sizeof(LiBinaryTreeRoot));

    if ( !root ) return ERROR;

    *tree = root;
    root->count = 0;
    root->root = NULL;

    return OK;
}

Status preOrderLiBiTree(LiBinaryTree tree){

}

Status inOrderLiBiTree(LiBinaryTree tree){

}

Status postOrderLiBiTree(LiBinaryTree tree){

}

Status levelOrderLiBiTree(LiBinaryTree tree){

} //层序遍历

Status destroyLiBinaryTree(LiBinaryTree tree){

}


//辅助函数

Status creatDemoLiBiTree(LiBinaryTree tree){
    tree->root = preOrderCreateLiBiTree();
    if(!tree->root) return ERROR;
    return OK;
}

LiBinaryTreeNode* preOrderCreateLiBiTree(){
    treeIndex = 0;
    LiBinaryTreeNode* root = insertPreLiBinaryTree();

    return root;
}



LiBinaryTreeNode* insertPreLiBinaryTree() {
    if (treeNode[treeIndex] == ' ') {
        treeIndex++;
        return NULL;
    } else {
        LiBinaryTreeNode* node = (LiBinaryTreeNode*) malloc (sizeof(LiBinaryTreeNode));
        node->data = treeNode[treeIndex] - 65;
        node->lchild = NULL;
        node->rchild = NULL;

        treeIndex++;

        node->lchild = insertPreLiBinaryTree();
        node->rchild = insertPreLiBinaryTree();
        return node;
    }
}