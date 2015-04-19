#ifndef _STACK_H_
#define _STACK_H_

#include <stdlib.h>
#include <stdio.h>

#include "bitree.h"

#define TRUE 1
#define FALSE 0

//链栈结构
typedef struct linkstack
{
	BiTree *data;
	struct linkstack *next;
}Stack;

//链队列结构
typedef struct linkqueue
{
    BiTree *data;
    struct linkqueue *next;
}LinkQueue;

//将链队列头尾指针封装在一起
typedef struct
{
    LinkQueue *front;
    LinkQueue *rear;
}Queue;

//初始化链栈
Stack *stack_creat()
{
	Stack *head;
	head = (Stack *)malloc( sizeof(Stack) );
	head->next = NULL;
	return head;
}

//压栈操作
int push( Stack *top, BiTree *tem )
{
	Stack *s;
	s = (Stack *)malloc( sizeof(Stack) );
	s->data = tem;
	s->next = top->next;
	top->next = s;
	return TRUE;
}

//弹栈操作
int pop( Stack *top, BiTree **tem )
{
	Stack *p;
	if( top->next == NULL )
		return FALSE;            //空栈
	p = top->next;
	top->next = p->next;
    *tem = p->data;
	free(p);
}

//获取栈顶元素
BiTree* get_top( Stack *top )
{
	if( top->next == NULL )
		return FALSE;
	return top->next->data;
}

//创建链栈
Queue *queue_creat()
{
    Queue *q;
    LinkQueue *p;
    q = malloc( sizeof(Queue) );
    p = malloc( sizeof(LinkQueue) );
    p->next = NULL;
    q->front = q->rear = p;
    return q;
}

//入队列
void EnterQueue( Queue *q, BiTree *x )
{
    LinkQueue *p;
    p = malloc( sizeof(LinkQueue) );
    p->data = x;
    p->next = NULL;
    q->rear->next = p;
    q->rear = p;
}

//出队列
void DeleteQueue( Queue *q, BiTree **x )
{
    LinkQueue *p;
    if( q->front == q->rear )
    {
        printf("错误，队列空！\n");
        exit(1);
    }
    p = q->front->next;
    q->front->next = p->next;
    *x = p->data;
    free(p);
    if( q->front->next == NULL )
    {
        q->rear = q->front;
    }
}

#endif
