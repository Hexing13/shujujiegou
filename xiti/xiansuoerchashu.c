/*************************************************************************
	> File Name: xiansuoerchashu.c
	> Author: Hexing
	> Mail: 1776898728@qq.com
	> Created Time: 2014年11月06日 星期四 17时26分30秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char data;
    int Ltag;
    int Rtag;
    struct Node *Lchild;
    struct Node *Rchild;
}Bitnode, *Bitree;

//记录访问的前一个结点
Bitree pre;

//建立二叉树
void CreateBitree(Bitree *root)
{
    char ch;

    ch = getchar();
    if(ch == '#') *root = NULL;
    else{
        *root = (Bitree)malloc(sizeof(Bitnode));
        (*root)->data = ch;
        (*root)->Ltag = 0;
        (*root)->Rtag = 0;
        CreateBitree(&((*root)->Lchild));
        CreateBitree(&((*root)->Rchild));
    }
}

//中序线索二叉树
void Inthread(Bitree root)
{
    if(root){
        
        //线索化左子树
        Inthread(root->Lchild);

        //置前驱线索
        if(root->Lchild == NULL){
            root->Lchild = pre;
            root->Ltag = 1;
        }

        //置后驱线索
        if(pre != NULL && pre->Rchild == NULL){
            pre->Rchild = root;
            pre->Rtag = 1;
        }

        //记录当前结点，将成为下一个访问结点的前驱
        pre = root;

        //线索化右孩子
        Inthread(root->Rchild);
    }
}

//中序线索树中找结点的前驱
Bitnode *Inpre(Bitnode *p)
{
    Bitnode *q;
    //直接利用线索
    if(p->Ltag == 1)   pre = p->Lchild;

    //在ｐ的左子树中查找最右下端的结点
    else{
        for(q = p->Lchild; q->Rtag == 0; q = q->Rchild)
            pre = q;
    }
    return pre;
}

//中序线索树中找结点的后驱
Bitnode *Innext(Bitnode *p)
{
    Bitnode *q, *next;
    //直接利用线索
    if(p->Rtag == 1)   next = p->Rchild;

    //在ｐ的右子树中查找最左下端的结点
    else{
        for(q = p->Rchild; q->Ltag == 0; q = q->Lchild)
            next = q;
    }
    return next;
}

//找中序线索树中要遍历的第一个结点
Bitree Infirst(Bitree root)
{
    Bitree p = root;
    if(p == NULL) return NULL;
    while(p->Ltag == 0)
        p = p->Lchild;
    return p;
}

//遍历中序线索二叉树
void Tinorder(Bitree root)
{
    Bitree p;
    p = Infirst(root);
    while(p){
        p = Innext(p);
    }
}

int main()
{
    Bitree root, p, q;

    printf("请输入二叉树序列：");
    CreateBitree(&root);
    pre = NULL;
    Inthread(root);
    printf("中序线索二叉树：");
    Tinorder(root);
    p = root->Lchild;
    q = Inpre(p);
    printf("前驱为：%c\n", q->data);
    q = Innext(p);
    printf("后继为：%c\n", q->data);

    return 0;
}
