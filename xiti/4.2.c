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

//递归交换各结点的左右子树
void Exchangeleaf(Bitree root)
{
    Bitree temp;
    if(root){
        temp = root->lchild;
        root->lchild = root->rchild;
        root->rchild = temp;
        Exchangeleaf(root->lchild);
        Exchangeleaf(root->rchild);
    }
}

//按树状打印二叉树
void Printtree(Bitree root, int h)
{
    int i;

    if(root == NULL) return;
    Printtree(root->rchild, h+1);
    for(i = 0; i < h; i++)
        printf("   ");
    printf("%c\n", root->data);
    Printtree(root->lchild, h+1);
}

int main()
{
    Bitree root;
    Createbitree(&root);

    //递归交换各结点的左右子树
    Exchangeleaf(root);
    printf("\n");

    //按树状打印二叉树
    Printtree(root, 1);

    return 0;
}
