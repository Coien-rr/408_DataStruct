//
// Created by Lenovo on 2022/9/21.
//
#include "TreeStructure/SqTree.h"

Status initSqTree(SqTree* tree){
    tree->count = 0;
    for (int i = 0; i < MaxSize; ++i) {
        tree->node[i].data = 0;
        tree->node[i].parentIndex = -1;
    }
    return OK;
}

int getSqTreeParent(SqTree *tree, int index){
    return tree->node[index].parentIndex;
}


//辅助函数
Status createDemoSqTree(SqTree *tree){
    initSqTree(tree);
    SqTreeNode demo[11] = {
            'R', -1,
            'A', 0,
            'B', 0,
            'C', 1,
            'D', 2,
            'E', 2,
            'H', 3,
            'I', 3,
            'G', 4,
            'F', 5,
            'J', 7
    };
    for(int i = 0; i < 11; i++){
        tree->node[i].data = demo[i].data;
        tree->node[i].parentIndex = demo[i].parentIndex;
    }
    return OK;
}

