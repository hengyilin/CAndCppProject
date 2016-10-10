#include <stdio.h>
#include <stdlib.h>

#define DEBUG
#define MAXVEX 100
typedef char VertexType;
typedef int EdgeType;

typedef struct EdgeNode{ // 边表节点
    int adjvex; // 邻接点域存储该定点对应的下标
    EdgeType weight; // 权重
    struct EdgeNode *next; // 指针域指向下一个邻接点
}EdgeNode;

typedef struct VertexNode {
    VertexType data; // 顶点域 存储顶点信息
    EdgeNode *firstEdge;// 边表头指针
} VertexNode, AdjList[MAXVEX];

typedef struct {
    AdjList adjList;
    int numVertexs;
    int numEdges;
}GraphList;

int locates(GraphList *g, char ch){
    int i;
    for (i = 0; i < MAXVEX; i++) {
        if (ch == g->adjList[i].data) {
            break;
        }
    }
    if (i >= MAXVEX) {
        fprintf(stderr, "there is not vertex.\n");
        return -1;
    }
    return i;
}

void createGraph(GraphList *g){
    int i,j,k;
    EdgeNode *e;
    EdgeNode *f;
    printf("输入顶点数和边数\n");
    scanf("%d%d", &g->numVertexs, &g->numEdges);

#ifdef DEBUG
    printf("顶点数：%d，边数：%d", g->numVertexs, g->numEdges);
#endif
    /*初始化顶点数组*/
    for (i = 0; i < g->numVertexs; i++) {
        printf("输入顶点%d数据\n", i);
        g->adjList[i].data = getchar();
        g->adjList[i].firstEdge = NULL;
        while (g->adjList[i].data == '\n') {
            g->adjList[i].data = getchar();
        }
    }
    /*建立边表*/
    for (k = 0; k < g->numEdges; k++) {
        printf("输入边(vi,vj)上的顶点序号\n");
        char p,q;
        p = getchar();
        while (p == '\n') {
            p = getchar();
        }
        q = getchar();
        while (q == '\n') {
            q = getchar();
        }
        int m = -1, n = -1;
        m = locates(g, p);
        n = locates(g, q);
        if (m == -1 || n == -1) {
            printf("没有该元素\n");
            return;
        }
#ifdef DEBUG
        printf("p = %c\n q = %c\n m = %d \n n = %d\n", p, q, m, n);
#endif
        // 向内存申请空间生成边表节点
        e = (EdgeNode*)malloc(sizeof(EdgeNode));
        if (e == NULL) {
            fprintf(stderr, "malloc() function error\n");
            return ;
        }
        e->adjvex = n; // 邻接序号为j
        e->next = g->adjList[m].firstEdge; // 将e指针指向当前定点指向的结构
        g->adjList[m].firstEdge = e; // 将当前定点的指针指向e

        f = (EdgeNode*)malloc(sizeof(EdgeNode));
        if (f == NULL) {
            fprintf(stderr, "malloc() function error");
            return ;
        }
        f->adjvex = m;
        f->next = g->adjList[n].firstEdge;
        g->adjList[m].firstEdge = f;
    }
}