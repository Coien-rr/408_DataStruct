
///测试文件
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "DataStruct.h"
#include "TestFunction.h"

int main () {
    SqBiTree tree;

    if(!initSqBiTree(&tree)) return ERROR;

    preOrderSqBiTree(&tree, 1);
}
