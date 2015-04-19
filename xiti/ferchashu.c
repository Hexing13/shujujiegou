/*************************************************************************
	> File Name: ferchashu.c
	> Author: Hexing
	> Mail: 1776898728@qq.com
	> Created Time: 2014年11月05日 星期三 16时27分39秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

//树的结构体
typedef struct Node
{
    char data;
    struct Node *lchild;
    struct Node *rchild;
}Bitree;

//链栈的结构体
typedef struct Linkstack
{
    Bitree *data;
    struct Linkstack *next;
}Stack;

//链队列的结构体
typedef struct Linkqueue
{
    Bitree *data;
    struct Linkqueue *next;
}Linkqueue;

//将链队头队尾封装在一起
typedef struct
{
    Linkqueue *front;
    Linkqueue *rear;
}Queue;

//初始化链栈
Stack *Init_stack()
{
    Stack *head;
    head = (Stack *)malloc(sizeof(Stack));
    head->next == NULL;

    return head;
}

//压栈操作
int Push_stack(Stack *top, Bitree *tem)
{
    Stack *s;
    s = (Stack *)malloc(sizeof(Stack));
    s->data = tem;
    s->next = top->next;
    top->next = s;

    return TRUE;
}

//弹栈操作
int Pop_stack(Stack *top, Bitree **tem)
{
    Stack *p;

    if(top->next == NULL){
        printf("抱歉，栈空不能出栈！\n");
        return FALSE;
    }
    p = top->next;
    top->next = p->next;
    *tem = p->data;
    free(p);
}

//取栈顶元素
Bitree *Get_top(Stack *top)
{
    if(top->next == NULL){
        printf("抱歉，栈空不能出栈！\n");
        return FALSE;
    }
    return top->next->data;
}

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
void Enter_queue(Queue *q, Bitree *tem)
{
    Linkqueue *p;
    p = malloc(sizeof(Linkqueue));
    p->data = tem;
    p->next = NULL;
    q->rear->next = p;
    q->rear = p;
}

//出队列
void Delete_queue(Queue *q, Bitree **tem)
{
    Linkqueue *p;
    if(q->front == q->rear){
        printf("抱歉，队列为空！\n");
        exit(-1);
    }
    p = q->front->next;
    q->front->next = p->next;
    *tem = p->data;
    free(p);
    if(q->front->next == NULL)
        q->rear = q->front;
}

//先序递归遍历二叉树
void Preorder(Bitree *root)
{
    if(root){
        printf("%c ", root->data);
        Preorder(root->lchild);
        Preorder(root->rchild);
    }
}
//中序递归遍历二叉树
void Inorder(Bitree *root)
{
    
    if(root){
        Preorder(root->lchild);
        printf("%c ", root->data);
        Preorder(root->rchild);
    }
}

//后序递归遍历二叉树
void Postorder(Bitree *root)
{
    
    if(root){
        Preorder(root->lchild);
        Preorder(root->rchild);
        printf("%c ", root->data);
    }
}

//先序非递归遍历二叉树
void fPreorder(Bitree *root)
{
    Stack *top;
    Bitree *p = root;
    top = Init_stack();

    while(p != NULL || top->next != NULL){
        while(p){
            printf("%c ", p->data);
            Push_stack(top, p);
            p = p->lchild;
        }
        if(top->next != NULL){
            Pop_stack(top, &p);
            p = p->rchild;
        } 
    }
}

//中序非递归遍历二叉树
void fInorder(Bitree *root)
{
    
    Stack *top;
    Bitree *p = root;
    top = Init_stack();

    while(p != NULL || top->next != NULL){
        while(p){
            Push_stack(top, p);
            p = p->lchild;
        }
        if(top->next != NULL){
            Pop_stack(top, &p);
            printf("%c ", p->data);
            p = p->rchild;
        } 
    }
}

//后序非递归遍历二叉树遍历
void fPostorder(Bitree *root)
{
    Stack *top;
    Bitree *p = root;
    Bitree *q = NULL;
    top = Init_stack();
    while(p != NULL || top->next != NULL){
        while(p){
            Push_stack(top, p);
            p = p->lchild;
        }
        if(top->next != NULL){
            p = Get_top(top);
            if(p->rchild == NULL || p->rchild == q){
                Pop_stack(top, &p);
                printf("%c ", p->data);
                q = p;
                p = NULL;
            }else{
                p = p->rchild;
            }
        }
    }
}

//按层次遍历二叉树
void Levelorder(Bitree *root)
{
    Queue *q;
    Bitree *p;
    
    q = Init_queue();
    Enter_queue(q, root);
    while(q->rear != q->front){
        Delete_queue(q, &p);
        printf("%c ", p->data);
        if(p->lchild != NULL)
            Enter_queue(q, p->lchild);
        if(p->rchild != NULL)
            Enter_queue(q, p->rchild);
    }
}

//创建二叉树
void Creat( Bitree **root )
{
    char ch;
    ch = getchar();
    if( ch == '#' )
    {
        root = NULL;
    }
    else
    {
        *root = (Bitree *)malloc( sizeof(Bitree) );
        (*root)->data = ch;
        Creat( &((*root)->lchild) );
        Creat( &((*root)->rchild) );
    }
}

int main( int argc, char *argv[] )
{
    Bitree *root;
    printf("请一次性输入每个结点的信息，以‘#’代替空\n");
    Creat(&root);

	printf("递归方式：\n");
    printf("先序：\n");
    Preorder(root);
    printf("\n");
    printf("中序：\n");
    Inorder(root); 
    printf("\n");
    printf("后序：\n");
    Postorder(root);
    printf("\n");
    printf("非递归方式：\n");
    printf("先序：\n");
    fPreorder(root);
    printf("\n");
    printf("中序：\n");
    fInorder(root); 
    printf("\n");
    printf("后序：\n");
    fPostorder(root);
    printf("\n");
    printf("按层次遍历：");
    Levelorder(root);
    printf("\n");
}
