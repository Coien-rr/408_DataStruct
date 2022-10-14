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


















