/*
 * =====================================================================================
 *
 *       Filename:  3.6.c
 *
 *    Description:  
 *
 *
 *        Version:  1.0
 *        Created:  2014年09月27日 21时55分56秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Hexing, 1776898728@qq.com
 *        Company:  Xiyou linux
 *
 * =====================================================================================
 */

#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cnode
{
	int data;
	struct cnode *next;
}Cnode;

typedef struct 
{
    Cnode *rear;
}Lqueue;

//初始化
Lqueue *Init_lqueue()
{
	Lqueue *q;

	q = malloc(sizeof(Lqueue));kongcheng
	q->rear = malloc(sizeof(Cnode));
    q->rear->next = q->rear;

	return q;
}

//进队
void In_lqueue(Lqueue *q, int x)
{
	Cnode *s;
	s = malloc(sizeof(Cnode));
	s->data = x;
    s->next =q->rear->next;
    q->rear->next = s;
	q->rear = s;
}

//判队空
int Empty_lqueue(Lqueue *q)
{
    if(q->rear->next == q->rear){
        printf("队空！\n");
        return 0;
    }else{
        return 1;
    }
}

//出队
int Out_lqueue(Lqueue *q, int *x)
{
    Cnode *p;
    if(!Empty_lqueue(q)){
        printf("队空，不能出队!\n");
        return 1;
    }else{
        p = q->rear->next->next;
        *x = p->data;
        printf("%d\n", *x);
        if(q->rear == p){     //只剩一个元素时，分情况讨论
            q->rear = q->rear->next;
            q->rear->next = p->next;
        }else{
            q->rear->next->next = p->next;
            free(p);
        }
        return 0;
    }
}

int main(int argc, char *argv[])
{
    Lqueue *q;
    int x;

    q = Init_lqueue();
    In_lqueue(q, 1);
    //In_lqueue(q, 2);
  //  In_lqueue(q, 3);
    Out_lqueue(q, &x);
    Out_lqueue(q, &x);
    
	return EXIT_SUCCESS;
}

//出现的问题
//　　　　只剩一个元素的情况
