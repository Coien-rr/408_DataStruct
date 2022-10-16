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
Status linkListHeadInsertNode(LinkList list, LinkNode* curNode);
Status linkListTailInsert(LinkList list, int elem);
Status linkListTailInsertNode(LinkList list, LinkNode* curNode);
Status linkListInsert(LinkList list, int index, int elem);
Status linkListRemove(LinkList list, int index, int *elem);
Status linkListTraverse(LinkList list);
Status linkListPrint(LinkList list);//打印函数

//------------链表有关操作算法的实现(参考王道强化DS打卡表)-----------//
Status linkListRemoveElem(LinkList list, ElemType elem);
Status linkListSort(LinkList list);                             //链表排序
Status linkListRemoveRepeat(LinkList list);                     //链表去重
Status linkListRemoveRepeat_Sorted(LinkList list);              //有序链表去重
Status linkListSplit(LinkList list1, LinkList list2);           //拆分链表
Status linkListSortedMerge_Descending(LinkList list1, LinkList list2);     //有序链表合并为递增链表
Status linkListSortedMerge_Ascending(LinkList list1, LinkList list2);     //有序链表合并为递增链表
ElemType linkListFindMin(LinkList list);                        //返回链表最小值
Status linkListCheckRings(LinkList list);                       //查找链表内是否有环
Status linkListCheckSymmetry(LinkList list);                    //判断链表是否对称

//辅助函数
LinkNode* creatNewLinkNode(int elem);
Status createDemoLinkList(LinkList list, int count);
LinkNode* linkListAddBackNode( LinkNode* priorNode, LinkNode* curNode);//在某个结点后添加一个结点，返回后一结点的指针



#endif //INC_408_DATASTRUCT_LINKLIST_H
