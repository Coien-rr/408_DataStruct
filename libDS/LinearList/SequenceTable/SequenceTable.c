#include "SequenceTable.h"


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
