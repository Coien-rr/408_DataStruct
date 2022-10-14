//
// Created by Lenovo on 2022/9/25.
//

#ifndef INC_408_DATASTRUCT_LINKLIST_H
#define INC_408_DATASTRUCT_LINKLIST_H

#include "BasicType.h"
//--------------单链表----------------//
//带头结点的实现
typedef struct LinkNode {
    ElemType data;
    struct LinkNode* next;
}LinkNode, *LinkList;

LinkList initLinkList();
Status linkListEmpty(LinkList list);
Status linkListClear(LinkList list);
Status linkListDestroy(LinkList list);
int linkListLength(LinkList list);
Status linkListGetElem(LinkList list, int index, int* elem);
Status linkListLocateElem(LinkList list, int elem);
LinkNode* linkListPriorElem(LinkList list, LinkNode* curNode);
LinkNode* linkListNextELem(LinkList list, LinkNode* curNode);
Status linkListHeadInsert(LinkList list, int elem);
Status linkListTailInsert(LinkList list, int elem);
Status linkListInsert(LinkList list, int index, int elem);
Status linkListRemove(LinkList list, int index, int *elem);
Status linkListTraverse(LinkList list);

//------------链表有关操作算法的实现(参考王道强化DS打卡表)-----------//
Status linkListRemoveElem(LinkList list, ElemType elem);
Status linkListSort(LinkList list);                             //链表排序
Status linkListRemoveRepeat(LinkList list);                     //链表去重
Status linkListRemoveRepeat_Sorted(LinkList list);              //有序链表去重

//辅助函数
LinkNode* creatNewLinkNode(int elem);
Status createDemoLinkList(LinkList list, int count);
Status linkListPrint(LinkList list);//打印函数


#endif //INC_408_DATASTRUCT_LINKLIST_H
