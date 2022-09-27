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


//辅助函数
LinkNode* creatNewLinkNode(int elem);
Status createDemoLinkList(LinkList list, int count);


#endif //INC_408_DATASTRUCT_LINKLIST_H
