//
// Created by Lenovo on 2022/9/23.
//

#ifndef INC_408_DATASTRUCT_LIGRAPH_H
#define INC_408_DATASTRUCT_LIGRAPH_H

#include "BasicType.h"
//-------------图的链式存储------------//
typedef int EdgeType;
typedef int VertexIndex;

typedef struct EdgeNode {
    VertexIndex adjvex;
    EdgeType weight;
    struct EdgeNode* nextEdge;
}EdgeNode; //

typedef struct VertexNode {
    ElemType data;
    EdgeNode* firstEdge;
} VertexNode ;

typedef struct LiGraph {
    VertexNode vex[MaxSize];//顶点表
    int vexNum; //顶点数
    int edgeNum; //边数
} LiGraph ;

#endif //INC_408_DATASTRUCT_LIGRAPH_H
