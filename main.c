
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

//    LiStack stack = InitLiStack();
//    printf("LiStackEmpty: %d\n", LiStackEmpty(stack));
//    for(int i = 0; i < 10; i++){
//        Push_LiStack(stack, arr[i]);
//    }
//    printf("LiStackEmpty: %d\n", LiStackEmpty(stack));
//    printf("LiStackCount: %d\n", LiStackCount(stack));
//    Destroy_LiStack(stack);

    DLiStack stack = InitDLiStack();
    printf("DLiStackEmpty: %d\n", DLiStackEmpty(stack));
    for (int i = 0; i < 10; i++){
        Push_DLiStack(stack, arr[i]);
    }
    printf("DLiStackEmpty: %d\n", DLiStackEmpty(stack));
    for (int i = 0; i < 9; i++) {
        int x = 0;
        Pop_DLiStack(stack, &x);
        printf("%d %d\n", i, x);
    }
    int x = 0;
    GetTop_DLiStack(stack, &x);
    printf("%d\n", x);
    Destroy_DLiStack(stack);
}
