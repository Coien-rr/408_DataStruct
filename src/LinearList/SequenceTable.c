#include <stdlib.h>
#include <stdio.h>
#include "LinearList/SequenceTable.h"


//-----线性表的静态分配顺序存储结构的基本操作函数实现-----//
Status InitList_Static(StaticSqList *L){ 
  //构造一个空的顺序表
  L->Length = 0;
  return OK;
}   

Status DestroyList_Static(StaticSqList *L){
  //销毁线性表L
  L->Length = 0;
  return OK;
}    

Status ClearList_Static(StaticSqList *L){
  //将L重置为空表
  L->Length = 0;
  return OK;
}     

Status ListEmpty_Static(StaticSqList *L){
  //判断表是否为空
  return (L->Length == 0) ? TRUE : FALSE;
}       

int ListLength_Static(StaticSqList *L){
  //返回L中数据元素个数
  return L->Length;
}        

Status GetElem_Static(StaticSqList *L, int i, ElemType* e){
  //用e返回L中第i个数据元素的值
  if(i < 1 || i > L->Length)
    return OVERFLOW;
  *e = L->data[i-1];
  return OK;
}

//返回第一个匹配的数据元素次序
Status LocateElem_Static (StaticSqList *L, ElemType e) {
    for (int i = 0; i < L->Length; ++i) {
        if(L->data[i] == e){
            return i;
        }
    }
    return 0;
}

//返回cur_e的前驱
Status PriorElem_Static(StaticSqList *L, ElemType cur_e, ElemType *pre_e){
    int curIndex = LocateElem_Static(L, cur_e);
    if( curIndex > 0 ){
        *pre_e = L->data[curIndex - 1];
        return OK;
    }
    return ERROR;
}

//返回cur_e的后继
Status NextElem_Static(StaticSqList *L, ElemType cur_e, ElemType *next_e){
    int curIndex = LocateElem_Static(L, cur_e);
    if(curIndex < L->Length-1){
        *next_e = L->data[curIndex + 1];
        return OK;
    }
    return ERROR;
}

//在L的第i个位置上插入e
Status ListInsert_Static(StaticSqList *L, int i, ElemType e){
    //1、范围检查
    if ( i<0 || i > L->Length ||i > MaxSize-1 ) {
        return OVERFLOW;
    }
    for (int j = L->Length; j > i; j--) {
        L->data[j] = L->data[j-1];
    }
    L->data[i] = e;
    L->Length++;
    return OK;
}

//在L的第i个位置删除元素
Status ListDelete_Static(StaticSqList *L, int i, ElemType *e){
    if (i >= L->Length || i < 0 ) {
        return OVERFLOW;
    }
    *e = L->data[i];
    for (int j = i; j < L->Length-1; j++) {
        L->data[j] = L->data[j+1];
    }
    L->Length--;
    return OK;
}

//打印顺序表
Status ListPrint_Static(StaticSqList *L){
    for (int i = 0; i < L->Length; i++) {
        printf("%d ", L->data[i]);
    }
    printf("end\n");
    return OK;
}

//-----线性表的动态分配顺序存储结构的基本操作函数实现-----//
Status InitList_Dynamic(DynamicSqList* L){
  //构造一个空的顺序表
  L->elem = (ElemType*)malloc(sizeof(ElemType)*LIST_INIT_SIZE);
  if(!L->elem) exit(OVERFLOW);          //存储分配失败
  L->Length = 0;                        //空表长度为0
  L->ListSize = LIST_INIT_SIZE;         //初始存储容量
  return OK;
}

Status DestroyList_Dynamic(DynamicSqList* L){
  L->Length = 0;
  L->ListSize = 0;
  free(L->elem);
  return OK;
  //销毁线性表·
} 
Status ClearList_Dynamic(DynamicSqList* L){
  //将L重置为空表 
  L->Length = 0;
  return OK;
}  

Status ListEmpty_Dynamic(DynamicSqList* L){
  //判断表是否非空
  return (L->Length == 0) ? TRUE : FALSE;
}    

int ListLength_Dynamic(DynamicSqList* L){
  //返回L中数据元素个数
  return L->Length;
}       

Status GetElem_Dynamic(DynamicSqList *L, int i, ElemType* e){
  //用e返回L中第i个数据元素的值
  if(i < 1 || i > L->Length)
    return OVERFLOW;
  *e = L->elem[i];
  return OK;
}

Status LocateElem_Dynamic (DynamicSqList *L, int e) {
    for (int i = 0; i < L->Length; ++i) {
        if(L->elem[i] == e){
            return i;
        }
    }
    return 0;
}

//返回cur_e的前驱
Status PriorElem_Dynamic(DynamicSqList *L, ElemType cur_e, ElemType *pre_e){
    int curIndex = LocateElem_Dynamic(L, cur_e);
    if ( curIndex > 0 ){
        *pre_e = L->elem[curIndex-1];
        return OK;
    }
    return ERROR;
}

//返回cur_e的后继
Status NextElem_Dynamic(DynamicSqList *L, ElemType cur_e, ElemType *next_e){
    int curIndex = LocateElem_Dynamic(L, cur_e);
    if (curIndex < L->Length-1){
        *next_e = L->elem[curIndex+1];
        return OK;
    }
    return ERROR;
}

//在L的第i个位置上插入e
Status ListInsert_Dynamic(DynamicSqList *L, int i, ElemType e) {
    if (i < 0 || i > L->Length) {
        return OVERFLOW;
    }
    if (i == L->ListSize){
        if(!IncreaseSize(L)){
            return OVERFLOW;
        }
    }
    for (int j = L->ListSize; j > i; j--){
        L->elem[j] = L->elem[j-1];
    }
    L->elem[i] = e;
    L->Length++;
    return OK;
}

//在L的第i个位置删除元素
Status ListDelete_Dynamic(DynamicSqList *L, int i, ElemType *e){
    if (i >= L->Length || i < 0) {
        return OVERFLOW;
    }
    *e = L->elem[i];
    for(int j = i; j < L->Length-1; j++){
        L->elem[j] = L->elem[j+1];
    }
    L->Length--;
    return OK;
}

//打印顺序表
Status ListPrint_Dynamic(DynamicSqList *L){
    for (int i = 0; i < L->Length; i++){
        printf("%d ", L->elem[i]);
    }
    printf("end\n");
    return OK;
}

//动态增加顺序表长度
Status IncreaseSize(DynamicSqList *L){
    int *p = L->elem;
    L->elem = (ElemType* )malloc((L->ListSize+LISTINCREAMENT)*sizeof(ElemType));
    if (!L->elem){
        exit(-1);
        return ERROR;
    }
    for (int i = 0; i < L->Length; i++){
        L->elem[i] = p[i];
    }
    L->ListSize += LISTINCREAMENT;
    free(p);
    return OK;
}





