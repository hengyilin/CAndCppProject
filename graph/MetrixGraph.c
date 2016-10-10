/* 数据结构：图
 * 关于使用邻接矩阵创建图的demo
 */
#include <stdio.h>
#include <stdlib.h>
#define MAXVEX 100         //最大顶点数
#define INFINITY 65535    // 无穷大

typedef char VertexType ; // 定点类型
typedef int EdgeType;     // 权值类型

typedef struct {
    VertexType vexs[MAXVEX]; // 顶点表
    EdgeType arc[MAXVEX][MAXVEX]; // 邻接矩阵
    int numVertexs; // 当前顶点数
    int numEdges; // 当前边数

} Graph;




