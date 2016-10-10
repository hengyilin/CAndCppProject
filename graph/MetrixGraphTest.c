/* 数据结构：图
 * 关于使用邻接矩阵创建图的demo
 */
#include <stdio.h>
#include <stdlib.h>
#define MAXVEX 100         //最大顶点数
#define INFINITY 65535    // 无穷大
#define DEBUG

typedef char VertexType ; // 定点类型
typedef int EdgeType;     // 权值类型

typedef struct {
    VertexType vexs[MAXVEX]; // 顶点表
    EdgeType arc[MAXVEX][MAXVEX]; // 邻接矩阵
    int numVertexs; // 当前顶点数
    int numEdges; // 当前边数
} Graph;

/**
 * 定位函数
 * @param g 图的指针
 * @param ch 待定位的元素
 * @return  元素在顶点表中所在的位置
 */
int locates(Graph *g, char ch){
    int i ;
    for (i = 0; i < g->numVertexs; i++) {
        if (g->vexs[i] == ch) {
            break;
        }
    }
    if (i > g->numVertexs) {
        return -1;
    }
    return i;
}

/**
 * 无向网图的邻接矩阵构建
 * @param g  图的指针
 */
void createMetrixGraph(Graph *g){
    int i,j,k,w;
    printf("输入顶点数和边数\n");
    scanf("%d%d", &(g->numVertexs), &(g->numEdges));

#ifdef DEBUG
    printf("%d,%d\n",g->numVertexs,g->numEdges);
#endif

    /*初始化顶点*/
    for (i = 0; i < g->numVertexs; i++) {
        g->vexs[i] = getchar();
        while (g->vexs[i] == '\n') {
            g->vexs[i] = getchar();
        }
    }

#ifdef DEBUG
    for (i = 0; i < g->numVertexs; i++) {
        printf("%c", g->vexs[i]);
    }
    printf("\n");
#endif

    /*邻接矩阵初始化：全部设置值为无穷大 复杂度为O(n^2)*/
    for (i = 0; i < g->numEdges; i++) {
        for (j = 0; j < g->numEdges; j++) {
            g->arc[i][j] = INFINITY;
        }
    }

    /*构造邻接矩阵*/
    for (k = 0; k < g->numEdges; k++) {
        char p,q;
        printf("输入边（vi,vj）的上标i和下标j和权值w:\n");
        p = getchar();
        while (p == '\n') {
            p = getchar();
        }
        q = getchar();
        while (q == '\n') {
            q = getchar();
        }
        scanf("%d", &w);
        int m = -1;
        int n = -1;
        m = locates(g, p);
        n = locates(g, q);
        if (m == -1 || n == -1) {
            fprintf(stderr, "there is no this vertex.\n");
            return ;
        }
        g->arc[m][n] = w;
        g->arc[n][m] = g->arc[m][n]; // 无向图是对称矩阵
    }
}

/**
 * 打印图
 * @param g 图的指针
 */
void printGraph(Graph *g){
    int i,j;
    for (i = 0; i < g->numVertexs; i++) {
        for (j = 0; j < g->numVertexs; j++) {
            printf("%d ", g->arc[i][j]);
        }
        printf("\n");
    }
}

int main(void){
    Graph g;
    createMetrixGraph(&g);
    printGraph(&g);
}




