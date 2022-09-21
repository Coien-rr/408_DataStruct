
///测试文件
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "DataStruct.h"
#include "TestFunction.h"


int main () {
    SqTree tree;
    createDemoSqTree(&tree);

    printf("%d ", getSqTreeParent(&tree, 5));

}
