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
void Preorder(Bitree root)
{
    if(root){
        printf("%c ", root->data);
        Preorder(root->lchild);
        Preorder(root->rchild);
    }
}

//统计二叉树中的结点数
int count = 0;

void Countpreorder(Bitree root)
{
    if(root){
        count++;
        Countpreorder(root->lchild);
        Countpreorder(root->rchild);
    }
}
//输出二叉树中的叶子结点
void Outpreleaf(Bitree root)
{
    if(root){
        if(root->lchild == NULL && root->rchild == NULL)
            printf("%c ", root->data);
        Outpreleaf(root->lchild);
        Outpreleaf(root->rchild);
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

//递归求二叉树的高度
int Depthtree(Bitree root)
{
    int hl, hr, h;

    if(root == NULL) return 0;
    else{
        hl = Depthtree(root->lchild);
        hr = Depthtree(root->rchild);
        h = (hl > hr? hl:hr)+1;

        return h;
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
    int height, num;

    //创建二叉树
    Createbitree(&root);

    //先序递归遍历二叉树
    Preorder(root);
    printf("\n");

    //统计二叉树中的结点数
    Countpreorder(root);
    printf("二叉树的结点数为：%d\n", count);

    //输出二叉树中的叶子结点
    printf("二叉树的叶子结点为：");
    Outpreleaf(root);
    printf("\n");

    //递归统计叶子结点的数目
    printf("二叉树的叶子结点数为：");
    num = Numleaf(root);
    printf("%d\n", num);

    //递归求二叉树的高度
    height = Depthtree(root);
    printf("二叉树的高度为：%d\n", height);

    //按树状打印二叉树
    Printtree(root, 2);

    return 0;
}
