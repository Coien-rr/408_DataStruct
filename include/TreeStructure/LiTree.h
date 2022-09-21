//
// Created by Lenovo on 2022/9/21.
//

#ifndef INC_408_DATASTRUCT_LITREE_H
#define INC_408_DATASTRUCT_LITREE_H

#include "BasicType.h"

//-------------孩子表示法表示树的链式结构-------------------//
typedef struct LiTreeChildNode{
    int nodeIndex;
    struct LiTreeChildNode* next;
} LiTreeChildNode;

typedef struct LiTreeNode{
    ElemType data;
    LiTreeChildNode* child;
} LiTreeNode;

typedef struct LiTree{
    LiTreeNode node[MaxSize];
} LiTree;

Status initLiTree(LiTree* tree);



//------------孩子兄弟表示法表示树的链式存储结构------------//
typedef struct LiTreeProNode{
    ElemType data;
    struct LiTreeProNode *firstChild, *firstsibling;
} LiTreeProNode, *LiTreeCS;


typedef struct LiTreePro{
    LiTreeProNode* root;
} LiTreePro;

Status initLiTreePro(LiTreePro* tree);


//辅助函数
Status createDemoLiTreePro(LiTreePro* tree);

#endif //INC_408_DATASTRUCT_LITREE_H
