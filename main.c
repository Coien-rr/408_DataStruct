
///测试文件
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "DataStruct.h"

int main () {
    srand((unsigned)time(NULL));
    printf("Hello, World!\n");
    DynamicSqList L;
    InitList_Dynamic(&L);
    for (int i = 0; i < 105; i++) {
        if(ListInsert_Dynamic(&L, i, rand()%10) == OVERFLOW){
            printf("OVERFLOW\n");
            exit(0);
        }
    }
    printf("%d\n", ListLength_Dynamic(&L));
    ListPrint_Dynamic(&L);
    DestroyList_Dynamic(&L);
    return 0;
}
