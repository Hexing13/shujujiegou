// =====================================================================================
//
//       Filename:  lianduilie.c
//
//    Description:  
//
//        Version:  1.0
//        Created:  2014年09月25日 16时12分22秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Hexing (Lucia), 1776898728@qq.com
//        Company:  Xiyou linux
//
// =====================================================================================
#include <stdio.h>
#include <stdlib.h>
#define datatype int

//链队结点的类型
typedef struct node
{
        datatype data;
        struct node *next;
}Qnode;

//头尾指针的链队
typedef struct 
{
        Qnode *front;
        Qnode *rear;
}Lqueue;

//创建一个带头结点的空队
Lqueue *Init_lqueue()
{
        Lqueue *q;
        Qnode *p;

        q = malloc(sizeof(Lqueue));
        p = malloc(sizeof(Qnode));
        p->next = NULL;
        q->front = q->rear = p;

        return q;
}

//入队
void In_lqueue(Lqueue *q, datatype x)
{
        Qnode *p;
        p = malloc(sizeof(Qnode));
        p->data = x;
        p->next = NULL;
        q->rear->next = p;
        q->rear = p;
}

//判断队空
int Isempty(Lqueue *q)
{
        if(q->front == q->rear)  return 0;
        else                     return 1;
}
//出队
int Out_lqueue(Lqueue *q, datatype *x)
{
        Qnode *p;
        
        if(!Isempty(q)){
                printf("抱歉，队空!\n");
                return 1;
        }else{
                p = q->front->next;
                q->front->next = p->next;
                *x = p->data;
                printf("%d\n", *x);
                free(p);
                if(q->front->next == NULL)
                        q->rear = q->front;

                return 0;
        }
}

int main()
{
        Lqueue *q;
        int x;

        q = Init_lqueue();
        In_lqueue(q, 1);
        In_lqueue(q, 2);
        In_lqueue(q, 3);
        In_lqueue(q, 4);
        Out_lqueue(q,&x);
        Out_lqueue(q,&x);
        Out_lqueue(q,&x);
        Out_lqueue(q,&x);
        Out_lqueue(q,&x);

        return 0;
}
