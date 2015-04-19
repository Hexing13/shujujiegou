/*************************************************************************
	> File Name: mowangyuyan.c
	> Author: 
	> Mail: 
	> Created Time: 2014年10月10日 星期五 21时55分09秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Maxsize 100
#define elemtype char 

//栈结构体
typedef struct snode
{
    elemtype data;
    struct snode *next;
}Stacknode;

//队结构体
typedef struct qnode  //链队结点类型
{
    elemtype data;
    struct qnode *next;
}Queuenode;

typedef struct //将头尾指针封装在一起
{
    Queuenode *front;
    Queuenode *rear;
}Lqueue;

//栈的初始化
Stacknode *Init_stack()
{
    Stacknode *top;
    
    if((top = (Stacknode *)malloc(sizeof(Stacknode))) == NULL){
        printf("抱歉，申请空间失败!\n");
        exit(1);
    }
    top->next = NULL;
    return top;
}
//入栈
void Push_stack(Stacknode *top, elemtype x)
{
    Stacknode *p;
    
    if((p = (Stacknode *)malloc(sizeof(Stacknode))) == NULL){
        printf("抱歉，申请空间失败!\n");
        exit(1);
    }
    p->data = x;
    p->next = top->next;
    top->next = p;
}

//出栈
void Pop_stack(Stacknode *top, elemtype *x)
{
    Stacknode *p;

    if(top->next == NULL){
        printf("抱歉，栈空!\n");
        exit(1);
    }
    p = top->next;
    top->next = p->next;
    *x = p->data;
    free(p);
}

//链队的初始化
Lqueue *Init_queue()
{
    Lqueue *q;
    Queuenode *p;

    q = malloc(sizeof(Lqueue)); //申请头尾指针结点
    p = malloc(sizeof(Queuenode)); //申请链队头结点

    p->next = NULL;
    q->front = q->rear = p;

    return q;
}

//入队
void In_queue(Lqueue *q, elemtype x)
{
    Queuenode *p;

    p = malloc(sizeof(Queuenode));
    p->data = x;
    p->next = NULL;
    q->rear->next = p;
    q->rear = p;
}

//输出队中的元素
void Print_queue(Lqueue *q)
{
    Queuenode *p;
    for(p = q->front->next; p != NULL; p = p->next){
        printf("%c", p->data);
    }
    printf("\n");
}
void In_queueA(Lqueue *q)
{
    In_queue(q, 's');
    In_queue(q, 'a');
    In_queue(q, 'e');
}

void In_queueB(Lqueue *q)
{
    In_queue(q, 't');
    In_queueA(q);
    In_queue(q, 'd');
    In_queueA(q);
}

//将魔王语言读入栈中
int Read_language(Stacknode *s)
{
    int i, n;
    int left = 0, right = 0;
    char str[Maxsize]; 

    printf("请输入魔王语言：");
    scanf("%s", str);
    n = strlen(str);
    
    //判断括号匹配
    for(i = 0; i < n; i++){
        if(str[i] == '(')
           left++;
        else if(str[i] == ')')
            right++;
    }
    if(left != right){
        printf("抱歉，括号不匹配!\n");
        return 1;
    }
    
    //将魔王语言从尾部压入栈中
    for(i = n-1; i >= 0; i--)
        Push_stack(s, str[i]);

    return 0;
}

//处理规则２
void Push_and_Pop(Stacknode *s1, Stacknode *s2)
{
    char x, x1;
    Stacknode *s3; //栈s3作为进行转化的中间变量

    s3 = Init_stack();
    while(s1->next != NULL){
        Pop_stack(s1, &x);
        if(x == '('){
            Pop_stack(s1, &x);
            x1 = x;
            if(x != ')')
                Pop_stack(s1, &x);
            while(x != ')'){
                Push_stack(s3, x);
                Pop_stack(s1, &x);
            }
            while(s3->next != NULL){
                Push_stack(s2, x1);
                Pop_stack(s3, &x);
                Push_stack(s2, x);
            }
            Push_stack(s2, x1);
        }
    }
}

int main()
{
    char x;
    Stacknode *s, *s1, *s2;
    Lqueue *q;

    s = Init_stack();
    s1 = Init_stack();
    s2 = Init_stack();
    q = Init_queue();
    if(Read_language(s))
        return 1;
    while(s->next != NULL){
       Pop_stack(s, &x);
        if(x == ')'){
            Push_stack(s1, x);
            Pop_stack(s2, &x);
            while(x != '('){
                Push_stack(s1, x);
                Pop_stack(s2, &x);
            }
            if(x == '('){
                Push_stack(s1, x);
            }
            Push_and_Pop(s1, s2);
        }else{
            Push_stack(s2, x);
        }
    }
    
    //魔王语言的前面部分在栈s2的底部，转换一下
    while(s2->next != NULL){
        Pop_stack(s2, &x);
        Push_stack(s, x);
    }

    //处理规则１
    while(s->next != NULL){
        Pop_stack(s, &x);
        if(x == 'A')
            In_queueA(q);
        else if(x == 'B')
            In_queueB(q);
        else 
            In_queue(q, x);
    }
    printf("魔王语言解释为：\n");
    Print_queue(q);

    return 0;
}



