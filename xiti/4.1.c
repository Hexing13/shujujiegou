/*************************************************************************
	> File Name: erchashu.c
	> Author: 
	> Mail: 
	> Created Time: 2014年10月22日 星期三 17时38分25秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

//结点结构体
typedef struct node
{
    char data;
    struct node *lchild;
    struct node *rchild;
}Bitnode, *Bitree;

//创建二叉树
void Createbitree(Bitree *root)
{
    char ch;
    
    ch = getchar();
    if(ch == '#') *root =  NULL;
    else{
        *root = (Bitnode *)malloc(sizeof(Bitnode));
        (*root)->data = ch;
        Createbitree(&((*root)->lchild));
        Createbitree(&((*root)->rchild));
    }
}


//递归统计叶子结点的数目
int Numleaf(Bitree root)
{
    int nl, nr;

    if(root == NULL) return 0;
    if(root->lchild == NULL && root->rchild == NULL) return 1;
    nl = Numleaf(root->lchild);
    nr = Numleaf(root->rchild);
    
    return nl+nr;
}

int main()
{
    Bitree root;
    int num;

    //创建二叉树
    Createbitree(&root);

    //递归统计度为２的数目
    num = Numleaf(root);
    printf("度为２的结点数为：%d\n", num-1);

    return 0;
}
