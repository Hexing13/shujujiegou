/*====================================================
  File name :     creat.c
  Create date   : 2013-11-11 21:09
  Modified date : 2013-11-11 21:09
  Author :        Geng Jinkai//Junco
  Email:          249869652@qq.com          
  Explain:                             
  ====================================================
  Please keep this mark,thanks!                        */

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "print.c"
#include "bitree.h"
#include "stack.h"

void RePreOrder( BiTree *root )
{
    if(root)
    {
        printf("%c ", root->data);
        RePreOrder( root->Lchild );
        RePreOrder( root->Rchild );
    }
}

void ReInOrder( BiTree *root )
{
    if(root)
    {
        ReInOrder( root->Lchild );
        printf("%c ",root->data);
        ReInOrder( root->Rchild );
    }
}

void RePostOrder( BiTree *root )
{
    if(root)
    {
        RePostOrder( root->Lchild );
        RePostOrder( root->Rchild );
        printf("%c ",root->data);
    }
}

void PreOrder( BiTree *root )
{
    Stack *top;
    top = stack_creat();
    BiTree *p = root;
    while( p != NULL || top->next != NULL)
    {
        while( p != NULL )
        {
            printf("%c ",p->data);
            push( top, p );
            p = p->Lchild;
        }
        if( top->next != NULL )
        {
            pop( top, &p );
            p = p->Rchild;
        }
    }
}

void InOrder( BiTree *root )
{
    Stack *top;
    top = stack_creat();
    BiTree *p = root;
    while( p != NULL || top->next != NULL )
    {
        while( p != NULL )
        {
            push( top, p );
            p = p->Lchild;
        }
        if( top->next != NULL )
        {
            pop( top, &p );
            printf("%c ",p->data);
            p = p->Rchild;
        }
    }
}

void PostOrder( BiTree *root )
{
    Stack *top;
    top = stack_creat();
    BiTree *p = root;
    BiTree *q = NULL;
    while( p != NULL || top->next != NULL )
    {
        while( p != NULL )
        {
            push( top, p );
            p = p->Lchild;
        }
        if( top->next != NULL )
        {
            p = get_top(top);
            if( ( p->Rchild == NULL || p->Rchild == q ) )
            {
                pop( top, &p );
                printf("%c ",p->data);
                q = p;
                p = NULL;
            }
            else
            {
                p = p->Rchild;
            }
        }
    }
}

void LevelOrder( BiTree *root )
{
    Queue *que;
    BiTree *p;
    que = queue_creat();
    EnterQueue( que, root );
    while( que->front != que->rear )
    {
        DeleteQueue( que, &p );
        printf("%c ", p->data);
        if( p->Lchild != NULL )
        {
            EnterQueue( que, p->Lchild );
        }
        if( p->Rchild != NULL )
        {
            EnterQueue( que, p->Rchild );
        }
    }
}

void creat( BiTree **root )
{
    char ch;
    ch = getchar();
    if( ch == '#' )
    {
        root = NULL;
    }
    else
    {
        *root = (BiTree *)malloc( sizeof(BiTree) );
        (*root)->data = ch;
        creat( &((*root)->Lchild) );
        creat( &((*root)->Rchild) );
    }
}

int main( int argc, char *argv[] )
{
    int n;
    BiTree *root;
    printf("请一次性输入每个结点的信息，以‘#’代替空\n");
    creat(&root); 
    printf("创建成功！所建二叉树如下：\n");
    n = PostTreeDepth(root);
    print(root, n);

	printf("递归方式：\n");
    printf("先序：\n");
    RePreOrder(root);
    printf("\n");
    printf("中序：\n");
    ReInOrder(root); 
    printf("\n");
    printf("后序：\n");
    RePostOrder(root);
    printf("\n");
    printf("非递归方式：\n");
    printf("先序：\n");
    PreOrder(root);
    printf("\n");
    printf("中序：\n");
    InOrder(root);
    printf("\n");
    printf("后序：\n");
    PostOrder(root);
    printf("\n");
    printf("按层次：\n");
    LevelOrder(root);
    printf("\n");
    return 0;
}

