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
#define Maxlen 5

#define   datatype int
typedef struct 
{
        datatype data[Maxlen];
        int rear, quelen;
}Csequeue;

//置空队
Csequeue *Init_sequeue()
{
        Csequeue *q;

        q = malloc(sizeof(Csequeue));
        q->rear = 0;
        q->quelen = 0;

        return q;
}

//入队
int In_sequeue(Csequeue *q, datatype x)
{
        if((q->rear+1)%Maxlen == (q->rear - q->quelen + Maxlen)%Maxlen){
                printf("　抱歉，　队满!\n");
                return 1;
        }else{
                q->data[q->rear] = x;
                q->rear = (q->rear+1)%Maxlen;
                q->quelen++;
                return 0;
        }
}

//出队
int Out_sequeue(Csequeue *q)
{
        if(q->quelen == 0){
                printf("抱歉，　队空!\n");
                return 1;
        }else{
                printf("%d\n", q->data[(q->rear-q->quelen+Maxlen)%Maxlen]);
                q->quelen--;
                return q->data[(q->rear-q->quelen+Maxlen+1)%Maxlen];
        }
}

int main()
{
        Csequeue *q;

        q = Init_sequeue();
        In_sequeue(q, 1);
        In_sequeue(q, 2);
        In_sequeue(q, 3);
        Out_sequeue(q);
        Out_sequeue(q);
        Out_sequeue(q);
        Out_sequeue(q);

        return 0;

}

