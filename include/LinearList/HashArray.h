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



#endif //INC_408_DATASTRUCT_HASHARRAY_H
