
///测试文件
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "DataStruct.h"
#include "TestFunction.h"

int main () {
    LiQueue queue = InitLiQueue();

    printf("LiQueueEmpty: %d\n", LiQueueEmpty(queue));

    for (int i = 0; i < 10; i++) {
        EnLiQueue(queue, i);
    }

    int top = 0;
    GetTopLiQueue(queue, &top);
    printf("LiQueueTop: %d\n", top);

    for (int i = 0; i < 5; i++) {
        int x = 0;
        DeLiQueue(queue, &x);
        printf("DeLiQueueResult: %d\n", x);
    }

    DestroyLiQueue(queue);
}
