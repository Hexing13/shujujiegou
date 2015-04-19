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

//先序递归遍历二叉树
void Preorder(Bitree root, int h)
{
    if(root){
        printf("(%c,%d) ", root->data, h);
        Preorder(root->lchild, h+1);
        Preorder(root->rchild, h+1);
    }
}

int main()
{
    Bitree root;
    int height, num;

    //创建二叉树
    Createbitree(&root);

    //先序递归遍历二叉树
    Preorder(root, 1);
    printf("\n");

    return 0;
}
