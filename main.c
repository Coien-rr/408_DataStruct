
///测试文件
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "DataStruct.h"
#include "TestFunction.h"


int main () {
    LinkList list = initLinkList();

    printf("%d\n", linkListEmpty(list));

    createDemoLinkList(list, 10);

    int x = 0;
    LinkNode* node = linkListNextELem(list, list->next);

    printf("%d\n", node);

    linkListRemove(list, 6, &x);

    linkListTraverse(list);
    //linkListClear(list);
    linkListDestroy(list);
//    printf("%d", list);


}
