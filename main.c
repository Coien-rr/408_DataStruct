
///测试文件
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "DataStruct.h"
#include "TestFunction.h"


int main () {
    LiBinaryTree tree = NULL;

    initLiBinaryTree(&tree);
    creatDemoLiBiTree(tree);

    printf("%d ", tree->root);

}
