//
// Created by Lenovo on 2022/9/20.
//

#ifndef INC_408_DATASTRUCT_LIBINARYTREE_H
#define INC_408_DATASTRUCT_LIBINARYTREE_H

#include "BasicType.h"

//--------二叉树的链式存储表示------------//
typedef struct LiBinaryTreeNode {
    ElemType data;
    struct LiBinaryTreeNode *lchild, *rchild;
} LiBinaryTreeNode; // 二叉树结点

typedef struct LiBinaryTreeRoot{
    ElemType count;
    LiBinaryTreeNode *root;
} *LiBinaryTree, LiBinaryTreeRoot; //由Root节点记录二叉树的相关信息：结点数 | 根节点地址 | 层高（Optional）

Status initLiBinaryTree(LiBinaryTree* tree);

Status preOrderLiBiTree(LiBinaryTree tree);
Status inOrderLiBiTree(LiBinaryTree tree);
Status postOrderLiBiTree(LiBinaryTree tree);
Status levelOrderLiBiTree(LiBinaryTree tree); //层序遍历
Status destroyLiBinaryTree(LiBinaryTree tree);


//辅助函数
Status creatDemoLiBiTree(LiBinaryTree tree);
LiBinaryTreeNode* preOrderCreateLiBiTree();
LiBinaryTreeNode* insertPreLiBinaryTree();

#endif //INC_408_DATASTRUCT_LIBINARYTREE_H
