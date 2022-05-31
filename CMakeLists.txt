cmake_minimum_required(VERSION 3.22)
project(408_DataStruct C)

set(CMAKE_C_STANDARD 17)

add_executable(408_DataStruct main.c libDS/BasicType.h libDS/DataStruct.h libDS/LinearList/LinearList.h)
#add_executable(libDS )
add_executable(SequenceTable libDS/LinearList/SequenceTable/SequenceTable.h libDS/LinearList/SequenceTable/SequenceTable.c)