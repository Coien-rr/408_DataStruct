
///测试文件
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "DataStruct.h"
#include "TestFunction.h"


int main () {
    LinkList list = initLinkList();

    createDemoLinkList(list, 10);

//    linkListSort(list);

    linkListPrint(list);

    printf("minNode:%d", linkListFindMin(list));
//    linkListRemoveRepeat_Sorted(list);

//    linkListRemoveElem(list, x);

//    linkListPrint(list);
}
