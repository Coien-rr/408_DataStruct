//
// Created by Lenovo on 2022/9/27.
//

#include <stdio.h>
#include <stdlib.h>
#include "LinearList/HashArray.h"

Status initHashArray(HashArray* hash, HashLength length, HashFunc p){

    if ( length > p + 2 ) return ERROR;

    hash->length = length;
    hash->p = p;
    for (int i = 0; i < length; i++) {
        hash->hashArr[i] = 0;
    }

    return OK;
}

Status addElemHashArray(HashArray* hash, ElemType elem){
    int index = elem % hash->p;

    while (index < hash->length){
        if (hash->hashArr[index] == 0){
            hash->hashArr[index] = elem;
            return OK;
        } else {
            ++index;
        }
    }

    if ( hash->hashArr[0] == 0 ){
        hash->hashArr[0] = elem;
        return OK;
    }

    return OVERFLOW;
}

Status findElemHashArray(HashArray hash, ElemType elem){
    int index = elem % hash.p;

    while (index < hash.length){
        if ( hash.hashArr[index] == elem ){
            return TRUE;
        } else {
            ++index;
        }
    }

    if (hash.hashArr[0] == elem ) return TRUE;

    return FALSE;
}

Status removeElemHashArray(HashArray* hash, int elem){
    if ( !findElemHashArray(*hash, elem) ) return ERROR;

    IndexType index = elem % hash->p;

    while (index < hash->length){
        if ( hash->hashArr[index] == elem ) {
            hash->hashArr[index] = 0;
            return OK;
        } else {
            ++index;
        }
    }

    if ( hash->hashArr[0] == elem ){
        hash->hashArr[0] = 0;
        return OK;
    }

    return FALSE;
}

//----------哈希数组（拉链法）--------------//
Status initHashArrayPro(HashArrayPro* hash, HashFunc p){
    hash->p = p;

    for (int i = 0; i < MaxSize; ++i) {
        hash->hashArr[i].data = 0;
        hash->hashArr[i].next = NULL;
    }

    return OK;
}

Status addElemHashArrayPro(HashArrayPro* hash, ElemType elem){
    IndexType index = elem % hash->p;

    HashNode* node = &(hash->hashArr[index]);

    while (node->next != NULL){
        node = node->next;
    }

    node->next = createHashNode(elem);

    hash->hashArr[index].data++;

    return OK;
}

Status findElemHashArrayPro(HashArrayPro* hash, ElemType elem){
    IndexType index = elem % hash->p;

    if ( hash->hashArr[index].data == 0 ) return FALSE;

    HashNode* node = hash->hashArr[index].next;

    while( node != NULL ) {
        if ( node->data == elem ) return TRUE;
        node = node->next;
    }

    return FALSE;
}

Status removeElemHashArrayPro(HashArrayPro* hash, ElemType elem){
    IndexType index = elem % hash->p;

    if ( hash->hashArr[index].data == 0 ) return ERROR;

    HashNode* node = &(hash->hashArr[index]);

    while( node->next != NULL ){
        if ( node->next->data == elem ){
            HashNode* nextNode = node->next;

            node->next = nextNode->next;

            nextNode->next = NULL;

            free(nextNode);

            return OK;
        }
        node = node->next;
    }

    return ERROR;

}


//---------辅助函数----------//

HashNode* createHashNode(ElemType elem){
    HashNode* node = (HashNode*)malloc(sizeof(HashNode));

    if ( !node ) exit(ERROR);

    node->data = elem;
    node->next = NULL;

    return node;
}













