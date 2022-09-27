#include "LinearList/LinkList.h"
#include <stdlib.h>
#include <stdio.h>


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

    newNode->next = list->next;
    list->next = newNode;
    list->data++;

    return OK;

}

Status linkListTailInsert(LinkList list, int elem){
    if ( !list ) return ERROR;

    LinkNode* newNode = creatNewLinkNode(elem);
    LinkNode* curNode = list;

    while(curNode->next != NULL){
        curNode = curNode->next;
    }

    curNode->next = newNode;

    list->data++;

    return OK;
}

Status linkListInsert(LinkList list, int index, int elem){
    if ( !list ) return ERROR;

    if ( index < 1 || index >= list->data ) return OVERFLOW;

    LinkNode* node = list;

    for (int i = index; i > 1; i--) {
        node = node->next;
    }

    LinkNode* newNode = creatNewLinkNode(elem);

    newNode->next = node->next;
    node->next = newNode;

    list->data++;

    return OK;
}

Status linkListRemove(LinkList list, int index, int *elem){
    if ( !list ) return ERROR;

    if ( index < 1 || index > list->data ) return OVERFLOW;

    LinkNode* node = list;

    for (int i = index; i > 1; i--) {
        node = node->next;
    }

    LinkNode* oldNode = node->next;

    *elem = oldNode->data;

    node->next = oldNode->next;

    free(oldNode);

    return OK;
}

Status linkListTraverse(LinkList list){
    if ( !list ) return ERROR;

    LinkNode* node = list->next;

    while(node){
        printf("%d ", node->data);
        node = node->next;
    }
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
    for (int i = count; i > 0; i--){
        linkListTailInsert(list, i);
    }



    return OK;
}
