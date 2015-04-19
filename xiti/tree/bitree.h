/*====================================================
  File name :     bitree.h
  Create date   : 2013-11-11 21:19
  Modified date : 2013-11-11 21:19
  Author :        Geng Jinkai//Junco
  Email:          249869652@qq.com          
  Explain:                             
  ====================================================
  Please keep this mark,thanks!                        */

#ifndef _BITREE_H_
#define _BITREE_H_

typedef struct Node
{
    char data;
    struct Node *Lchild;
    struct Node *Rchild;
}BiTree;

void RePreOrder( BiTree *root );
void ReInOrder( BiTree *root );
void RePostOrder( BiTree *root );
void PreOrder( BiTree *root );
void InOrder( BiTree *root );
void PostOrder( BiTree *root );
void creat( BiTree **root );

#endif

