/*************************************************************************
	> File Name: lianduilie.c
	> Author: 
	> Mail: 
	> Created Time: 2015年12月01日 星期二 10时37分54秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

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
Lqueue *Init_Lqueue()
{
    Lqueue *q;
    Qnode *p;
    q = (Lqueue*)malloc(sizeof(Lqueue));
    p = (Qnode*)malloc(sizeof(Qnode));
    p->next = NULL;
    q->front = q->rear = p;
    return q;
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
