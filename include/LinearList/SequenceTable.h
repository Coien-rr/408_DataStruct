//
// Created by Coien-rr on 2022/5/31.
//

#ifndef INC_408_DATASTRUCT_SEQUENCETABLE_H
#define INC_408_DATASTRUCT_SEQUENCETABLE_H

#include "BasicType.h"
#define LIST_INIT_SIZE 100      //顺序表动态分配存储空间的初始分配量
#define LISTINCREAMENT 10        //顺序表动态分配存储空间的分配增量

//-------------线性表的静态分配顺序存储结构------------//
typedef struct {
    ElemType data[MaxSize];       //顺序表的元素
    int Length;                   //顺序表长度
}StaticSqList;

Status InitList_Static(StaticSqList *L);        //构造一个空的顺序表
Status DestroyList_Static(StaticSqList *L);     //销毁线性表L
Status ClearList_Static(StaticSqList *L);       //将L重置为空表
Status ListEmpty_Static(StaticSqList *L);       //判断表是否为空
int ListLength_Static(StaticSqList *L);         //返回L中数据元素个数
Status GetElem_Static(StaticSqList *L, int i, ElemType* e);         //用e返回L中第i个数据元素的值
Status LocateElem_Static(StaticSqList *L, ElemType e);      //返回第一个匹配的数据元素次序
Status PriorElem_Static(StaticSqList *L, ElemType cur_e, ElemType *pre_e); //返回cur_e的前驱
Status NextElem_Static(StaticSqList *L, ElemType cur_e, ElemType *next_e); //返回cur_e的后继
Status ListInsert_Static(StaticSqList *L, int i, ElemType e);           //在L的第i个位置上插入e
Status ListDelete_Static(StaticSqList *L, int i, ElemType *e);          //在L的第i个位置删除元素
Status ListPrint_Static(StaticSqList *L);       //打印顺序表


//-------------线性表的动态分配顺序存储结构------------//
typedef struct {
    ElemType *elem;               //存储空间基址
    int Length;                   //当前线性表长度
    int ListSize;                 //当前分配的存储容量
}DynamicSqList;

Status InitList_Dynamic(DynamicSqList* L);      //构造一个空的顺序表
Status DestroyList_Dynamic(DynamicSqList* L);   //销毁线性表·
Status ClearList_Dynamic(DynamicSqList* L);     //将L重置为空表
Status ListEmpty_Dynamic(DynamicSqList* L);     //判断表是否非空
int ListLength_Dynamic(DynamicSqList* L);       //返回L中数据元素个数
Status GetElem_Dynamic(DynamicSqList *L, int i, ElemType* e);      //用e返回L中第i个数据元素的值
Status LocateElem_Dynamic(DynamicSqList*L, int e);      //返回第一个匹配的数据元素次序
Status PriorElem_Dynamic(DynamicSqList *L, ElemType cur_e, ElemType *pre_e); //返回cur_e的前驱
Status NextElem_Dynamic(DynamicSqList *L, ElemType cur_e, ElemType *next_e); //返回cur_e的后继
Status ListInsert_Dynamic(DynamicSqList *L, int i, ElemType e);           //在L的第i个位置上插入e
Status ListDelete_Dynamic(DynamicSqList *L, int i, ElemType *e);          //在L的第i个位置删除元素
Status ListPrint_Dynamic(DynamicSqList *L);     //打印顺序表
Status IncreaseSize(DynamicSqList *L);          //动态增加顺序表长度
#endif //INC_408_DATASTRUCT_SEQUENCETABLE_H