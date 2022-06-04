cmake_minimum_required(VERSION 3.22)
project(408_DataStruct C)

set(CMAKE_C_STANDARD 17)


FILE(GLOB_RECURSE CURRENT_INCLUDE include/*.h)
FILE(GLOB_RECURSE CURRENT_SOURCES src/*.c)

include_directories(include) #添加头文件


add_executable(408_DataStruct ${CURRENT_SOURCES} ${CURRENT_INCLUDE} main.c src/Test.c)  #制定生成目标