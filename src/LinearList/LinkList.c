#include "LinearList/LinkList.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>


LinkList initLinkList(){
    LinkList list = creatNewLinkNode(0);

    if ( !list ) exit(ERROR);

    return list;
}

Status linkListEmpty(LinkList list){
    if ( !list ) return ERROR;

    if ( list->data == 0 && list->next == NULL) return TRUE;

    return FALSE;
}

Status linkListClear(LinkList list){
    if ( !list ) return ERROR;

    while(list->next != NULL){
        LinkNode* oldNode = list->next;
        list->next = oldNode->next;
        free(oldNode);
    }

    return OK;
}

Status linkListDestroy(LinkList list){
    if ( !list ) return ERROR;

    linkListClear(list);

    free(list);

    return OK;
}

int linkListLength(LinkList list){
    if ( !list ) return ERROR;

    return list->data;
}

Status linkListGetElem(LinkList list, int index, int* elem){
    if ( !list ) return ERROR;

    if ( index > list->data || index < 1 ) return OVERFLOW;

    LinkNode* node = list;

    for (int i = 0; i < index; ++i) {
        node = node->next;
    }

    *elem = node->data;

    return OK;
}

int linkListLocateElem(LinkList list, int elem){
    if ( !list ) return ERROR;

    LinkNode* node = list->next;
    int index = 1;

    while(node){
        if ( node->data == elem ) return index;
        node = node->next;
        ++index;
    }

    return 0;
}

LinkNode* linkListPriorElem(LinkList list, LinkNode* curNode){
    if ( !list ) return ERROR;

    LinkNode* node = list->next;

    if ( node == curNode ) return NULL;

    while(node->next != NULL){
        if (node->next == curNode) return node;

        node = node->next;
    }

    return NULL;
}

LinkNode* linkListNextELem(LinkList list, LinkNode* curNode){
    if ( !curNode ) return ERROR;

    return curNode->next;
}

Status linkListHeadInsert(LinkList list, int elem){
    if ( !list ) return ERROR;

    LinkNode* newNode = creatNewLinkNode(elem);

    if ( !newNode ) return ERROR;

    newNode->next = list->next;
    list->next = newNode;
    list->data++;

    return OK;
}

Status linkListHeadInsertNode(LinkList list, LinkNode* curNode){
    if ( !list || !curNode ) return ERROR;

    curNode->next = list->next;
    list->next = curNode;
    list->data++;

    return OK;
}

Status linkListTailInsert(LinkList list, int elem){
    if ( !list ) return ERROR;

    LinkNode* newNode = creatNewLinkNode(elem);

    if ( !newNode ) return ERROR;

    LinkNode* curNode = list;
    while( curNode->next != NULL ) curNode = curNode->next;
    curNode->next = newNode;
    list->data++;

    return OK;
}

Status linkListTailInsertNode(LinkList list, LinkNode* curNode){
    if ( !list || !curNode ) return ERROR;

    LinkNode* node = list;

    while ( node->next != NULL ) node = node->next;
    curNode->next = node->next;
    node->next = curNode;
    list->data++;

    return OK;
}

Status linkListInsert(LinkList list, int index, int elem){
    if ( !list || index > list->data+1 ) return ERROR;

    LinkNode* newNode = creatNewLinkNode(elem);
    if ( !newNode ) return ERROR;

    LinkNode* curNode = list;
    for (int i = 1; i < index; i++){
        curNode = curNode->next;
    }

    newNode->next = curNode->next;
    curNode->next = newNode;
    list->data++;

    return OK;
}

Status linkListRemove(LinkList list, int index, int *elem){
    if ( !list || index > list->data) return ERROR;

    LinkNode* curNode = list;

    for (int i = 1; i < index; i++){
        curNode = curNode->next;
    }

    LinkNode* oldNode = curNode->next;
    curNode->next = oldNode->next;
    *elem = oldNode->data;
    free(oldNode);
    list->data--;

    return OK;
}

Status linkListTraverse(LinkList list){
    if ( !list ) return ERROR;

    if ( list->data < 2 ) return OK; //链表只有0个或1个结点，无需转置

    LinkNode* curNode = list->next;

//    LinkNode* nextNode = curNode->next;
    while ( curNode->next != NULL ){
        LinkNode* nextNode = curNode->next;
        curNode->next = nextNode->next;
        nextNode->next = list->next;
        list->next = nextNode;
    }

    return OK;
}


//辅助函数
LinkNode* creatNewLinkNode(int elem){
    LinkNode* newNode = (LinkNode*)malloc(sizeof(LinkNode));

    if ( !newNode ) exit(ERROR);

    newNode->data = elem;
    newNode->next = NULL;

    return newNode;
}

Status createDemoLinkList(LinkList list, int count){
    srand((unsigned int)time(NULL));
    for (int i = count; i > 0; i--){
        int x = rand() % 100;
        linkListTailInsert(list, x);
    }

    return OK;
}

//在某个结点后添加一个结点，返回后一结点的指针
LinkNode* linkListAddBackNode( LinkNode* priorNode, LinkNode* curNode) {
    if ( !priorNode || !curNode ) return ERROR;

    curNode->next = priorNode->next;
    priorNode->next = curNode;

    return curNode;
}


Status linkListPrint(LinkList list){
    printf("%d\n", list->data);
    list = list->next;

    while ( list != NULL ) {
        printf("%d ", list->data);
        list = list->next;
    }
    printf("End!\n");

    return OK;
}


//------------链表有关操作算法的实现(参考王道强化DS打卡表)-----------//
Status removeElem(LinkList list, ElemType elem){
    int flag = 0;

    if ( !list->next ) return flag;

    if ( list->next->data == elem ) {
        //删除操作
        LinkNode* oldNode = list->next;
        list->next = oldNode->next;
        oldNode->next = NULL;
        free(oldNode);
        flag = 1;
        flag += removeElem(list, elem);
    } else {
        flag += removeElem(list->next, elem);
    }

    return flag;
}

Status linkListRemoveElem(LinkList list, ElemType elem){
    //非递归实现：遍历一遍链表，删除data为elem的结点

    //递归实现---------递归实现无法更新头节点的结点数（data）
    int flag = removeElem(list, elem);

    list->data -= flag;

    return OK;
}

//链表排序
Status linkListSort(LinkList list){
    if ( !list ) return ERROR;
    if ( list->data < 2 ) return OK;

    LinkNode* p = list->next;

    while ( p->next != NULL ) {
        LinkNode* node = p->next;
        p->next = node->next; //保持p为有序链表的最后结点！
        LinkNode* curNode = list;

        while ( curNode != p && node->data >= curNode->next->data ) {
            //当数小于curNode的下一节点时 或 curNode为有序链表最后结点时跳出循环
            curNode = curNode->next;
        }

        node->next = curNode->next;
        curNode->next = node;

        //curNode为有序链表最后结点
        if ( p == curNode ){
            //保持p为有序链表的最后结点！
            p = p->next;
        }
    }

    return OK;
}


//无序链表去重
Status linkListRemoveRepeat(LinkList list){
    ElemType* arr = (ElemType*)malloc(sizeof(ElemType)*MaxSize);
    memset(arr, 0, sizeof(ElemType)*MaxSize);

    LinkNode* p = list;
    while(p->next != NULL) {
        if (arr[p->next->data] == 1){
            //已出现过的情况
            LinkNode* oldNode = p->next;
            p->next = oldNode->next;
            free(oldNode);
            list->data--;
        } else {
            //未出现过的情况
            arr[p->next->data] = 1;
            p = p->next;
        }
    }

    free(arr);

    return OK;
}

//有序链表去重
Status linkListRemoveRepeat_Sorted(LinkList list){
    if ( !list ) return ERROR;

    if ( list->data < 2 ) {
        return OK;
    }

    LinkNode* p = list->next;

    while ( p->next != NULL ) {
        if ( p->data == p->next->data ){
            //若后一结点与当前结点相同，则删除
            LinkNode* oldNode = p->next;
            p->next = oldNode->next;
            free(oldNode);
            list->data--;
        } else {
            p = p->next;
        }
    }

    return OK;
}

//拆分链表
Status linkListSplit(LinkList list1, LinkList list2) {
    //list1, list2指向的均为头节点
    LinkNode* p = list1->next;
    LinkNode* q = list2;

    while ( p->next != NULL ) {
        LinkNode* curNode = p->next;
        p->next = curNode->next;
        p = p->next;

        //使用头插法插入list2
        curNode->next = q->next;
        q->next = curNode;
        list2->data++;

        if ( p == NULL ) {
            break;
        }//偶数个结点情况
    }

    return OK;
}

//有序链表合并为降序链表
Status linkListSortedMerge_Descending(LinkList list1, LinkList list2){
    LinkNode* p = list1;
    LinkNode* q = list2;

    LinkNode* list = creatNewLinkNode(0);

    while ( q->next != NULL && p->next != NULL ) {
        LinkNode* curNode = NULL;
        if ( q->next->data < p->next->data ) {
            //从list2上摘下该结点
            curNode = q->next;
            q->next = curNode->next;
        } else {
            curNode = p->next;
            p->next = curNode->next;
        }
        //将结点插入list中
        linkListHeadInsertNode(list, curNode);
    }

    while ( p->next != NULL ) {
        LinkNode* curNode = p->next;
        p->next = curNode->next;

        linkListHeadInsertNode(list, curNode);
    }

    while ( q->next != NULL ) {
        LinkNode* curNode = q->next;
        q->next = curNode->next;

        linkListHeadInsertNode(list, curNode);
    }

    //此时list1为空，将list转接到list1上，
    list1->data = list->data;
    list1->next = list->next;
    list->next = NULL;

    //list2没有结点时
    free(q);
    free(list);

    return OK;
}


//有序链表合并为递增链表
Status linkListSortedMerge_Ascending(LinkList list1, LinkList list2){
    LinkNode* p = list1;
    LinkNode* q = list2;

    LinkList list = creatNewLinkNode(0);
    LinkNode* endNode = list;

    while ( p->next != NULL && q->next != NULL) {
        LinkNode* curNode = NULL;
        if ( p->next->data < q->next->data ) {
            curNode = p->next;
            p->next = curNode->next;
        } else {
            curNode = q->next;
            q->next = curNode->next;
        }

        //在list队尾插入数据
        endNode = linkListAddBackNode(endNode, curNode);;
        list->data++;
    }

    while ( p->next != NULL ) {
        LinkNode* curNode = p->next;
        p->next = curNode->next;

        endNode = linkListAddBackNode(endNode, curNode);;
        list->data++;
    }

    while ( q->next != NULL ) {
        LinkNode* curNode = q->next;
        q->next = curNode->next;

        endNode = linkListAddBackNode(endNode, curNode);;
        list->data++;
    }

    //此时list1为空，将list转接到list1上，
    list1->data = list->data;
    list1->next = list->next;
    list->next = NULL;

    //list2没有结点时
    free(q);
    free(list);

    return OK;
}

//返回链表最小值
ElemType linkListFindMin(LinkList list) {
    LinkNode* curNode = list->next;
    int min = INT_MAX;
    while (curNode != NULL){
        if ( curNode->data < min) {
            min = curNode->data;
        }
        curNode = curNode->next;
    }

    return min;
}

//查找链表内是否有环（快慢指针）
Status linkListCheckRings(LinkList list) {
    if ( !list ) return ERROR;
    if ( list->data < 3 ) return TRUE;

    LinkNode* p1 = list->next;          //慢指针
    LinkNode* p2 = list->next->next;    //快指针

    while (TRUE) {
        if ( p1 == p2 ) return TRUE;
        if ( p2 == NULL ) return FALSE;

        p1 = p1->next;
        p2 = p2->next;

        if ( p2 != NULL ) {
            p2 = p2->next;
        } else {
            break;
        }
    }

    return FALSE;
}

//判断链表是否对称
Status linkListCheckSymmetry(LinkList list) {
    //法一：拷贝到数组
    //时间复杂度O(n)
    //空间复杂度O(n)
    ElemType* arr = (ElemType*)malloc(sizeof(ElemType)*(list->data));
    LinkNode* curNode = list->next;
    int index = 0;
    while ( curNode != NULL ) {
        arr[index++] = curNode->data;
        curNode = curNode->next;
    }

    for (int i = 0; i <= index/2; i++) {
        if ( arr[i] != arr[index-i] ) {
            free(arr);
            return FALSE;
        }
    }

    free(arr);
    return TRUE;

    //法二：数组逆置 （but会变换链表！！
    //时间复杂度O(n)
    //空间复杂度O(1)
    //1、 先设置快慢指针-查找到链表中点
    //2、 后半段逆置
    //3. 逐项比较

}




