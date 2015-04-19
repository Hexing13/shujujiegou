/*************************************************************************
	> File Name: erchashu.c
	> Author: 
	> Mail: 
	> Created Time: 2014年10月22日 星期三 17时38分25秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

//结点结构体
typedef struct CSnode
{
    char data;
    struct CSnode *firstchild;
    struct CSnode *nextsibling;
}CSnode, *CStree;

//以孩子兄弟结点创建树
void Createcstree(CStree *root)
{
    char ch;
    
    ch = getchar();
    if(ch == '#') *root =  NULL;
    else{
        *root = (CSnode *)malloc(sizeof(CSnode));
        (*root)->data = ch;
        Createcstree(&((*root)->firstchild));
        Createcstree(&((*root)->nextsibling));
    }
}

//二叉树形式先序递归遍历树
void Preorder(CStree root)
{
    if(root){
        printf("%c ", root->data);
        Preorder(root->firstchild);
        Preorder(root->nextsibling);
    }
}


//二叉树形式中序递归遍历树
void Inorder(CStree root)
{
    if(root){
        Inorder(root->firstchild);
        printf("%c ", root->data);
        Inorder(root->nextsibling);
    }
}

//树的定义先序遍历树
void Rootfirst(CStree root)
{
    CStree p;

    if(root){
        printf("%c ", root->data);
        p = root->firstchild;
        while(p){
            Rootfirst(p);
            p = p->nextsibling;
        }
    }
}


//树的定义后序遍历树
void Rootpost(CStree root)
{
    CStree p;

    if(root){
        p = root->firstchild;
        while(p){
            Rootpost(p);
            p = p->nextsibling;
        }
        printf("%c ", root->data);
    }
}

int main()
{
    CStree root;
    //创建二叉树
    Createcstree(&root);
    //先序递归遍历二叉树
    printf("二叉树形式先序递归遍历树：");
    Preorder(root);
    printf("\n");
    printf("树的定义先序遍历树：");
    Rootfirst(root);
    printf("\n");
    printf("二叉树形式中序递归遍历树：");
    Inorder(root);
    printf("\n");
    printf("树的定义后序遍历树：");
    Rootpost(root);
    printf("\n");
    return 0;
}
