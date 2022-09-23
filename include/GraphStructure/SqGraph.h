//
// Created by Lenovo on 2022/9/23.
//

#ifndef INC_408_DATASTRUCT_SQGRAPH_H
#define INC_408_DATASTRUCT_SQGRAPH_H

#include "BasicType.h"
//---------图的顺序存储------------//
//邻接矩阵法
typedef char VertexType;
typedef int EdgeType;

typedef struct SqGraph {
    VertexType vex[MaxSize];
    EdgeType edge[MaxSize][MaxSize];
} SqGraph;



#endif //INC_408_DATASTRUCT_SQGRAPH_H
