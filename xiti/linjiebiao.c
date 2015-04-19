/*************************************************************************
	> File Name: linjiebiao.c
	> Author: Hexing
	> Mail: 1776898728@qq.com
	> Created Time: 2014年11月13日 星期四 19时57分08秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define Max_NUM 20

int visit[Max_NUM] = {0};
typedef char vextype;
//结点的结构体
typedef struct Arcnode
{
    int adjvex;
    int weight;
    struct Arcnode *nextarc;
}Arcnode;

//表头的结构体
typedef struct Vexnode
{
    vextype vexdata;
    Arcnode *firstchild;
}Vexnode;

//邻接表结构体
typedef struct
{
    Vexnode vextex[Max_NUM+1];
    int vexnum;
    int arcnum;
}Adjlist;

//链队列的结构体
typedef struct Linkqueue
{
    int adjvex;
    int weight;
    struct Linkqueue *next;
}Linkqueue;

//将链队头队尾封装在一起
typedef struct
{
    Linkqueue *front;
    Linkqueue *rear;
}Queue;

//初始化链队列
Queue *Init_queue()
{
    Queue *q;
    Linkqueue *p;
    q = malloc(sizeof(Queue));
    p = malloc(sizeof(Linkqueue));
    p->next = NULL;
    q->front = q->rear = p;

    return q;
}

//入队列
void Enter_queue(Queue *q,  int i, int weight)
{
    Linkqueue *p;
    p = malloc(sizeof(Linkqueue));
    p->adjvex = i;
    p->weight = weight;
    p->next = NULL;
    q->rear->next = p;
    q->rear = p;
}

//出队列
void Delete_queue(Queue *q, int *i, int *weight)
{
    Linkqueue *p;
    if(q->front == q->rear){
        printf("抱歉，队列为空！\n");
        exit(-1);
    }
    p = q->front->next;
    q->front->next = p->next;
    *i = p->adjvex;
    *weight = p->weight;
    free(p);
    if(q->front->next == NULL)
        q->rear = q->front;
}

//查找顶点位置函数
int Locationvex(Adjlist *G, char v)
{
    int i;
    for(i = 1; i <= G->vexnum; i++){

        if(G->vextex[i].vexdata == v)
            return i;
    }
    printf("抱歉，您的输入有误！\n");
    return -1;
}

//插入相连结点的函数
void Insert_adjvex(Arcnode **firstchild, int n, int weight)
{
    Arcnode *p, *q = *firstchild;
    p = (Arcnode *)malloc(sizeof(Arcnode));
    p->adjvex = n;
    p->weight = weight;
    p->nextarc = NULL;

    if(*firstchild == NULL){
        *firstchild = p;
    }else if(n < (*firstchild)->adjvex){
        p->nextarc = *firstchild;
        *firstchild = p;
    }else{
        while( q->nextarc && n > q->nextarc->adjvex)
            q = q->nextarc;
        p->nextarc = q->nextarc;
        q->nextarc = p;        
    }        
}

//创建邻接表
void Creat_adjlist(Adjlist *G)
{
    Arcnode *p;
    char vex1, vex2;
    int i, j, k, weight;

    printf("请输入图中结点的个数及相连边的个数：");
    scanf("%d%d", &G->vexnum, &G->arcnum);
    
    //初始化图中结点
    for(i = 1; i <= G->vexnum; i++){
        printf("NO.%d个结点：", i);
        getchar();
        scanf("%c", &G->vextex[i].vexdata);
        G->vextex[i].firstchild = NULL;
    }

    //初始化图中边信息
    for(k = 1; k <= G->arcnum; k++){
        printf("NO.%d个边关系：", k);
        getchar();
        scanf("%c %c %d", &vex1,&vex2, &weight);
        i = Locationvex(G, vex1);
        j = Locationvex(G, vex2);
        Insert_adjvex(&(G->vextex[i].firstchild), j, weight);
        //Insert_adjvex(&(G->vextex[j].firstchild), i);
    }
}

//输出邻接表
void Print_adjlist(Adjlist *G)
{
    int i;
    Arcnode *p;

    for(i = 1; i <= G->vexnum; i++){
        printf("%c", G->vextex[i].vexdata);
        for(p = G->vextex[i].firstchild; p != NULL; p = p->nextarc){
            printf("——>%c: %d", G->vextex[p->adjvex], p->weight);
        }
        printf("\n");
    }
}

/*//递归深度优先搜索遍历连通子图
void DFS(Adjlist *G, int i)
{
    visit[i] = 1;
    printf("%c ", G->vextex[i].vexdata);
    Arcnode *p = G->vextex[i].firstchild;
    while(p){
        if(!visit[p->adjvex])
            DFS(G, p->adjvex);
        p = p->nextarc;
    }
}

//递归深度优先搜索遍历连通图
void DFSTraverse(Adjlist *G)
{
    int i;
    for(i = 1; i <= G->vexnum; i++)
        if(!visit[i])
            DFS(G, i);
}

//递归广度优先搜索遍历连通子图
void BFS(Adjlist *G, int i)
{
    Queue *q;
    q = Init_queue();
    Arcnode *p;

    printf("%c ", G->vextex[i].vexdata);
    visit[i] = 1;
    Enter_queue(q, i,);
    while(q->front != q->rear){
        Delete_queue(q, &i);
        p = G->vextex[i].firstchild;
        while(p){
            if(!visit[p->adjvex]){
                printf("%c ", G->vextex[p->adjvex].vexdata);
                visit[p->adjvex] = 1;
                Enter_queue(q, p->adjvex);
            }
            p = p->nextarc;
        }
    }
}


//递归广度优先搜索遍历连通图
void BFSTraverse(Adjlist *G)
{
    int i;
    for(i = 1; i <= G->vexnum; i++)
        if(!visit[i])
            BFS(G, i);
}*/

//拓扑排序获取图中每个结点的入度
void Find_indegree(Adjlist *G, int indegree[Max_NUM+1])
{
    int i;
    Arcnode *p;

    //初始化indegree数组为0
    for(i = 1; i <= G->vexnum; i++)
        indegree[i] = 0;
    //逐个扫描各个结点的链表，计算入度
    for(i = 1; i <= G->vexnum; i++){
        p = G->vextex[i].firstchild;
        while(p){
            indegree[p->adjvex]++;
            p = p->nextarc;
        }
    }
    for(i = 1; i <= G->vexnum; i++)
        printf("%d ", indegree[i]);
    printf("\n");
}

//拓扑排序
int Topusort(Adjlist *G, int tp[])
{
    Queue *q;
    int indegree[Max_NUM+1], ve[Max_NUM+1];
    int i, count, k = 1;
    Arcnode *p;

    Find_indegree(G, indegree);
    q = Init_queue();

    //初始化indegree数组
    for(i = 1; i <= G->vexnum; i++){
        if(indegree[i] == 0)
            Enter_queue(q, i);
    }

    //初始化ve数组
    for(i = 1; i <= G->vexnum; i++){
        ve[i] = 0;
    }
    count = 0;
    while(q->rear != q->front){
        Delete_queue(q, &i);
        tp[k++] = i;
        printf("%c ", G->vextex[i].vexdata);
        count++;
        p = G->vextex[i].firstchild;
        while(p){
            indegree[p->adjvex]--;
            if(indegree[p->adjvex]== 0)
                Enter_queue(q, p->adjvex);
            if(ve[i]+ p->weight > ve[p->adjvex])
                ve[p->adjvex] = ve[i]+ p->weight;
            p = p->nextarc;
        }
    }
    if(count < G->vexnum)   return 0;
    else return 1;
}

//关键路径
int CriticalPath(Adjlist *G)
{
    Arcnode *p;
    int i, j, ee, el, flag = 0;
    int vl[Max_NUM+1], tp[Max_NUM+1];
    
    //求拓扑序列并求ve数组
    if(!Topusort(G, tp)){
        printf("抱歉，没有拓扑序列！\n");
        return -1;
    }

    //初始化vl数组
    for(i = 1; i <= G->vexnum; i++){
        vl[i] = ve[G->vexnum];
    }

    //求vl
    for(i = G->vexnum-1; i >= 1; i--){
        p = G->vextex[tp[i]].firstchild;
        while(p){
            if(vl[p->adjvex]-p->weight < vl[tp[i]])
                vl[tp[i]] = vl[p->adjvex]-p->adjvex;
            p = p->nextarc;
        }
    }

    //比较ee和el求关键路径
    for(i = 1; i <= G->vexnum; i++){
        p = G->vextex[i].firstchild;
        while(p){
            ee = ve[i];
            el = vl[p->adjvex]-p->weight;
            if(ee == el){
                printf("%c->%c ", G->vextex[i], G->vextex[p->adjvex]);
            }

            p = p->nextarc;
        }
    }
}

int main()
{
    Adjlist *G;
    G = (Adjlist *)malloc(sizeof(Adjlist));
    Creat_adjlist(G);
    Print_adjlist(G);
    //printf("递归深度优先搜索遍历连通子图：");
    //DFS(G, 1);
    //printf("\n");
    //printf("递归广度优先搜索遍历连通子图：");
    //BFS(G, 1);
    //printf("\n");
    //printf("拓扑排序：");
    //Topusort(G);
    //printf("\n");
    printf("关键路径：");
    CriticalPath(G);
    printf("\n");

    return 0;
}

