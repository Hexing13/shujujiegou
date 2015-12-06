/*************************************************************************
	> File Name: jishu.c
	> Author: 
	> Mail: 
	> Created Time: 2015年12月06日 星期日 10时53分41秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#define SIZE 6
typedef int datatype;

//链结点
typedef struct node
{
    datatype data;   
    struct node *next;
}Qnode;

//链头
typedef struct queue
{
    Qnode *front;
    Qnode *rear;
}Lqueue;

//创建空队列
void Init_Lqueue(Lqueue *q)
{
    Qnode *p;
    //q = (Lqueue*)malloc(sizeof(Lqueue));
    p = (Qnode*)malloc(sizeof(Qnode));
    p->next = NULL;
    q->front = q->rear = p;
}

//入队
void In_Lqueue(datatype x,Lqueue *q)
{
    Qnode *p;
    p = malloc(sizeof(Qnode));
    p->data = x;
    p->next = NULL;
    q->rear->next = p;
    q->rear = p;
}

//判断对空
int Empty_Lqueue(Lqueue *q)
{
    if(q->rear==q->front) return 0;
    else return 1;
}

//出队
int Out_Lqueue(datatype *x,Lqueue *q)
{
    Qnode *p;
    //判断对空
    if(!Empty_Lqueue(q)){
        printf("队空");
        return 1;
    }else{
        p = q->front->next;
        *x = p->data;
        q->front->next = p->next;
        free(p);
        if(q->front->next==NULL)
            q->rear = q->front;
        return 0;
    }
}

int digit(datatype k, int m,int r)
{
    int i,d;
    if(m == 0) return k%r;
    d = r;
    for(i = 1; i < m; i++)
        d*=r;
    return k/d%r;
}

void radixSort(int a[],int m, int r)
{
    //m为位数,r为进制数
    int i,j,k;
    //把r个队列定义为动态数组
    Lqueue *q =(Lqueue *)malloc(sizeof(Lqueue)*r);
    //初始化
    for(i = 0; i < r; i++)
         Init_Lqueue(&q[i]);

    for(i = 0; i < m; i++){//进行m次分配和收集
        for(j = 0; j < SIZE; j++){
            k = digit(a[j],i,r);
            In_Lqueue(a[j],&q[k]);
        }
    
        k = 0;
        //收集
        for(j = 0; j < r; j++)
            for(;Empty_Lqueue(&q[j]);k++)
                Out_Lqueue(&(a[k]),&q[j]);
    }
}

int main()
{
    int a[SIZE] = {61,11,41,67,43,21}, i;
    radixSort(a,2,10);
    printf("基数排序:");
    for(i = 0; i < SIZE; i++)
        printf("%d ",a[i]);
    printf("\n");
    
    return 0;
}

