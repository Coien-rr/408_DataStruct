
///测试文件
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "DataStruct.h"
#include "TestFunction.h"


int main () {
    StaticSqList sqList;
    InitList_Static(&sqList);
    createDemoSqList(&sqList, 12);

    ListPrint_Static(&sqList);

    int key = sqList.data[11];

    mergeSort(&sqList, 0, 11);

    ListPrint_Static(&sqList);

    printf("binarySearch Test!\nIndex: %d!", binarySearch(sqList, key));
}
