/*************************************************************************
	> File Name: wuxiangtu.c
	> Author: Hexing
	> Mail: 1776898728@qq.com
	> Created Time: 2014年11月10日 星期一 19时29分15秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define MAXVEX 20   //最大顶点个数
#define INFINITY 32767  //表示极大值

typedef char vextype;
typedef struct
{
    int arcs[MAXVEX+1][MAXVEX+1]; //边或弧集的信息
    vextype vex[MAXVEX+1];      //顶点信息
    int vexnum;  //顶点数目
    int arcnum;  //边数目
}AdjMatrix;

//查找顶点位置函数
int Locationvex(AdjMatrix *G, char v)
{
    int i;
    for(i = 1; i <= G->vexnum; i++)
        if(G->vex[i] == v)
            return i;
    printf("抱歉，您的输入有误！\n");
    return -1;
}

//用邻接矩阵创建无向网
void Create(AdjMatrix *G)
{
    int i, j, k, weight;
    char vex1, vex2;
    printf("请输入无向图中顶点和边个数：");
    scanf("%d %d", &G->vexnum, &G->arcnum);

    //初始化顶点信息
    for(i = 1; i <= G->vexnum; i++){
        printf("No.%d个顶点：", i);
        getchar();
        scanf("%c", &G->vex[i]);
    }

    //初始化边信息
    for(i = 1; i <= G->vexnum; i++){
        for(j = 1; j <= G->vexnum; j++){
            G->arcs[i][j] = INFINITY;
        }
    }
    
    //边关系表示
    for(k = 1; k <= G->arcnum; k++){
        printf("请输入相关联的两个顶点：");
        getchar();
        scanf("%c %c", &vex1, &vex2);
        i = Locationvex(G, vex1);
        j = Locationvex(G, vex2);
        printf("请输入权值：");
        scanf("%d", &weight);
        G->arcs[i][j] = weight;
        G->arcs[j][i] = weight;
    }
}

//输出邻接矩阵
void print_AdjMatrix(AdjMatrix *G)
{
    int i, j;
    for(i = 1; i <= G->vexnum; i++)
        printf("%c  ", G->vex[i]);
    printf("\n");

    for(i = 1; i <= G->vexnum; i++){
        for(j = 1; j <= G->vexnum; j++){
            printf("%d  ", G->arcs[i][j]);
        }
        printf("\n");
    }
}

//prim算法求最小生成树
void prim(AdjMatrix *G, int start)
{
    struct{
        int adjvex;
        int lowcost;
    }closedge[MAXVEX+1];
    int i, e, k, m, min;

    closedge[start].lowcost = 0; //标志点u已经加入生成树中
    for(i = 1; i <= G->vexnum; i++){ //对除了出发点以外的closedge数组进行初始化
        if(i != start){
            closedge[i].adjvex = start;
            closedge[i].lowcost = G->arcs[start][i];
        }
    }
    //控制选择中的n-1条符合条件的边
    for(e = 1; e < G->vexnum; e++){
        min = INFINITY;
        for(k = 1; k <= G->vexnum; k++){
            if(closedge[k].lowcost != 0 && closedge[k].lowcost < min){
                m = k;
                min = closedge[k].lowcost;
            }
        }

        //标志点v0加入生成树中
        printf("%d ", m);
        closedge[m].lowcost = 0;
        printf("%c->%c\n", G->vex[closedge[m].adjvex], G->vex[m]);
        //当v0加入后，更新closedge数组信息
        for(i = 1; i <= G->vexnum; i++){
            if(i != m && G->arcs[m][i] < closedge[i].lowcost){
                closedge[i].lowcost = G->arcs[m][i];
                closedge[i].adjvex = m;
            }
        }

    }
}

int main()
{
    AdjMatrix *G;
    
    G = (AdjMatrix *)malloc(sizeof(AdjMatrix));
    printf("创建邻接无向图.\n");
    Create(G);
    print_AdjMatrix(G);
    printf("prim算法生成最小生成树:\n");
    prim(G, 1);
    printf("\n");

    return 0;
}

