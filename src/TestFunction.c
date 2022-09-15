//
// Created by Lenovo on 2022/9/13.
//
#include "TestFunction.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

Status CreateTestData(int count) {
    FILE *file = fopen("data.txt", "w");
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 10; i++) {
        fprintf(file, "%d ", rand()%100);
    }
    fclose(file);
    return OK;
}

int* GetTestData() {}