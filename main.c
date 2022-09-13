
///测试文件
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "DataStruct.h"
#include "TestFunction.h"

int main () {
//    srand((unsigned int)time(NULL));
//    for (int i = 0; i < 10; i++) {
//        printf("%d ", rand()%100);
//    }

    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    LiStack stack = InitLiStack();
    printf("%d", stack->data);



}
