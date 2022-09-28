//
// Created by Lenovo on 2022/9/27.
//

#ifndef INC_408_DATASTRUCT_HASHARRAY_H
#define INC_408_DATASTRUCT_HASHARRAY_H

#include "BasicType.h"

//--------------哈希数组--------------//

typedef int HashLength;
typedef int HashFunc;

typedef struct HashArray {
    ElemType hashArr[MaxSize]; // 默认数组元素为0时为空
    HashLength length;      //散列表长度
    HashFunc p;
} HashArray;

Status initHashArray(HashArray* hash, HashLength length, HashFunc p);
Status addElemHashArray(HashArray* hash, ElemType elem);
Status findElemHashArray(HashArray hash, ElemType elem);
Status removeElemHashArray(HashArray* hash, ElemType elem);



//----------哈希数组（拉链法）-----------//
typedef struct HashNode {
    ElemType data;
    struct HashNode *next;
} HashNode;

typedef struct HashArrayPro {
    HashNode hashArr[MaxSize]; //数组的data值为该链上有几个数据
    HashFunc p;
} HashArrayPro;

Status initHashArrayPro(HashArrayPro* hash, HashFunc p);
Status addElemHashArrayPro(HashArrayPro* hash, ElemType elem);
Status findElemHashArrayPro(HashArrayPro* hash, ElemType elem);
Status removeElemHashArrayPro(HashArrayPro* hash, ElemType elem);

//辅助函数
HashNode* createHashNode(ElemType elem);

#endif //INC_408_DATASTRUCT_HASHARRAY_H
