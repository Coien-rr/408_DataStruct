//
// Created by Lenovo on 2022/9/22.
//


#include <stdio.h>
#include "TreeStructure/UFSet.h"

Status initUFSet(UFSet* ufSet){
    ufSet->count = 0;
    for (int i = 0; i < MaxSize; ++i) {
        ufSet->setNode[i].data = 0;
        ufSet->setNode[i].parentIndex = -1;
    }

    return OK;
}

Status unionUFSet( UFSet* ufSet, int root1, int root2){
    int fRoot = findUFSet(ufSet, root1);
    int sRoot = findUFSet(ufSet, root2);

    //小树加到大树的集合中去
    if ( ufSet->setNode[fRoot].data <= ufSet->setNode[sRoot].data){
        //root1为大树
        ufSet->setNode[fRoot].data += ufSet->setNode[sRoot].data;
        ufSet->setNode[sRoot].parentIndex = fRoot;
        ufSet->setNode[sRoot].data = 0;
    } else {
        //root2为大树
        ufSet->setNode[sRoot].data += ufSet->setNode[fRoot].data;
        ufSet->setNode[fRoot].parentIndex = sRoot;
        ufSet->setNode[fRoot].data = 0;
    }

    return OK;
}

int findUFSet(UFSet* ufSet, int index){
    //参数检查
    if (index < 0 || index >= MaxSize) return ERROR;

//    //无路径压缩版
//    int root = index;
//    while ( ufSet->setNode[root].parentIndex > 0) {
//        root = ufSet->setNode[root].parentIndex;
//    }
//
//    return root;

    //路径压缩版
    int root = index;
    while ( ufSet->setNode[root].parentIndex > 0) {
        root = ufSet->setNode[root].parentIndex;
    }

    //结点不是根结点直接孩子时，进行路径压缩操作
    if (ufSet->setNode[index].parentIndex != -1){
        int copyRoot = index;
        while (ufSet->setNode[copyRoot].parentIndex > 0) {
            int parentIndex = ufSet->setNode[copyRoot].parentIndex;
            ufSet->setNode[copyRoot].parentIndex = root;
            copyRoot = parentIndex;
        }
    }


    return root;
}

//辅助函数
int searchSetRoot(UFSet* ufset, int index){

}

Status createDemoUfSet(UFSet* ufSet){
    initUFSet(ufSet);
    //并查集内初始有10个元素，即并查集内有10个集合
    for (int i = 0; i < 10; ++i) {
        ufSet->count++;
        ufSet->setNode[i].data = -1;
        ufSet->setNode[i].parentIndex = -1;
    }

    return OK;
}

Status printUFSet(UFSet *ufSet) {
    for (int i = 0; i < ufSet->count; ++i) {
        printf("%d %d\n", i, ufSet->setNode[i].parentIndex);
    }
    return OK;
}

void testUFSetFunc(){
    UFSet ufSet;

    createDemoUfSet(&ufSet);
    unionUFSet(&ufSet, 1, 2);
    unionUFSet(&ufSet, 3, 4);
    unionUFSet(&ufSet, 5, 6);
    unionUFSet(&ufSet, 7, 8);
    unionUFSet(&ufSet, 9, 0);


    unionUFSet(&ufSet, 1, 3);
    unionUFSet(&ufSet, 7, 5);
    unionUFSet(&ufSet, 7, 9);

    unionUFSet(&ufSet, 1, 7);

    findUFSet(&ufSet, 0);
    findUFSet(&ufSet, 4);
    findUFSet(&ufSet, 6);

    printUFSet(&ufSet);
}