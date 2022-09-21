//
// Created by Lenovo on 2022/9/21.
//

#include <stdio.h>
#include "TreeStructure/LiTree.h"


//-------------孩子表示法表示树的链式结构-------------------//

Status initLiTree(LiTree* tree){
    for (int i = 0; i < MaxSize; ++i) {
        tree->node[i].data = 0;
        tree->node[i].child = NULL;
    }
}


//------------孩子兄弟表示法表示树的链式存储结构------------//

Status initLiTreePro(LiTreePro* tree){
    tree->root = NULL;
    return OK;
}

Status createDemoLiTreePro(LiTreePro* tree){

}