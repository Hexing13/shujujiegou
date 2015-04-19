// =====================================================================================
//
//       Filename:  xunhuanduilie.c
//
//    Description:  
//
//        Version:  1.0
//        Created:  2014年09月25日 15时29分35秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Hexing (Lucia), 1776898728@qq.com
//        Company:  Xiyou linux
//
// =====================================================================================
#include <stdio.h>
#include <stdlib.h>
#define Maxlen 3

#define   datatype int
typedef struct 
{
        datatype data[Maxlen];
        int rear, front, tag;
}Csequeue;

//置空队
Csequeue *Init_sequeue()
{
        Csequeue *q;

        q = malloc(sizeof(Csequeue));
        q->rear = q->front = 0;
        q->tag = 0;

        return q;
}

//入队
int In_sequeue(Csequeue *q, datatype x)
{
        if(q->tag == 1 && q->front == q->rear){
                printf("**抱歉,队满!\n");
                return 1;
        }else{
            q->data[q->rear] = x;
            q->rear = (q->rear+1)%Maxlen;
            if(q->rear == q->front){
                printf("抱歉，队满!\n");
                q->tag = 1;
            }
            return 0;
        }
}

//出队
int Out_sequeue(Csequeue *q, datatype *x)
{
        if(q->tag == 0 && q->front == q->rear){
                printf("**抱歉，队空!\n");
                return 1;
        }else{
            *x = q->data[q->front];
            printf("%d\n", *x);
            q->front = (q->front+1)%Maxlen;
            if(q->tag == q->front){
                printf("抱歉，队空!\n");
                q->tag = 0;
            }
            return 0;
        }
}

int main()
{
        Csequeue *q;
        int x;

        q = Init_sequeue();
        In_sequeue(q, 1);
        In_sequeue(q, 2);
        //In_sequeue(q, 3);
        Out_sequeue(q, &x);
        Out_sequeue(q, &x);
        //Out_sequeue(q, &x);
        //Out_sequeue(q, &x);

        return 0;

}

