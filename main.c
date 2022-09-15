
///测试文件
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "DataStruct.h"
#include "TestFunction.h"

int main () {
    CreateTestData(10);
    int a = GetTestData();
    for (int i = 0; i < 5; i++) {
        printf("%d", a);
    }
}
