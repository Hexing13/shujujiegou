/*************************************************************************
	> File Name: erchashu.c
	> Author: 
	> Mail: 
	> Created Time: 2015年11月30日 星期一 09时02分47秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define type char
#define datatype BiTree

//定义二叉树
typedef struct Node
{
    type data;
    struct Node *lchild;
    struct Node *rchild;
}BiNode,*BiTree;

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

//创建二叉树
void createBitree1(BiTree *root)
{
    char ch ;
    ch = getchar();
    if(ch == '#') *root = NULL;
    else{
        *root = (BiTree)malloc(sizeof(BiNode));
        (*root)->data = ch;
        createBitree1(&((*root)->lchild));
        createBitree1(&((*root)->rchild));
    }
}

//创建二叉树
BiTree createBitree2()
{
    char ch = NULL;
    BiTree root = NULL;
    ch = getchar();
    if(ch == '#') return NULL;
    else{
        root = (BiTree)malloc(sizeof(BiNode));
        root->data = ch;
        root->lchild = createBitree2();
        root->rchild = createBitree2();
        return root;
    }
}

//打印二叉树
void printTree(BiTree root,int h)
{
    int i = 0;
    if(root==NULL) return;
    else{
        printTree(root->rchild,h+1);
        for(;i < h;i++){
            printf(" ");
        }
        printf("%c\n",root->data);
        printTree(root->lchild,h+1);
    }
}

//先序递归遍历二叉树
void preOrder(BiTree root)
{   
    if(root){
        printf("%c ",root->data);
        preOrder(root->lchild);
        preOrder(root->rchild);
    }
}

//按层次遍历
void LevelOrder(BiTree root)
{
    Lqueue *q;
    BiTree p;
    q = (Lqueue*)malloc(sizeof(Lqueue));
    q = Init_Lqueue();
    In_Lqueue(root,q);
    while(Empty_Lqueue(q)){
        Out_Lqueue(&p,q);
        printf("%c ",p->data);
        if(p->lchild!=NULL)
        In_Lqueue(p->lchild,q);
        if(p->rchild!=NULL)
            In_Lqueue(p->rchild,q);
    }
}

void main()
{
    BiTree t = NULL;

    //创建
    //createBitree1(&t);
    t = createBitree2();
    
    //先序
    preOrder(t);
    printf("\n");

    //树状打印
    printTree(t,1);
    printf("\n");

    //层次遍历
    LevelOrder(t);
    printf("\n");

}
