
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

    quickSort(sqList.data, 0, sqList.Length-1);

    ListPrint_Static(&sqList);
}
