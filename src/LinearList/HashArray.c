//
// Created by Lenovo on 2022/9/27.
//

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